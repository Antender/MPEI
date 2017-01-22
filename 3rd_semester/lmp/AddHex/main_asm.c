#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// addhexstr arguments
#define first_a [esp+36]
#define second_a [esp+40]
#define result_a [esp+44]
// addhexstr locals
#define	first_length [esp+16]
#define	first_pos [esp+20]
#define	second_pos [esp+24]
#define	lengthdiff [esp+28]
//adds two hex text strings together, result is at least 1 character bigger then other strings
__declspec(naked) char* addhexstr(char* first, char* second, char* result) {
	__asm {
		// space for locals
		sub esp,16
		// saving_registers
		push ebx
		push esi
		push edi
		push ebp
		/* 
	int lengthdiff = strlen(second)-strlen(first);
	if (lengthdiff<0) {
		char* temp = first;
		first = second;
		second = temp;
		lengthdiff= -lengthdiff;  
	}
	char* first_pos = strchr(first,0);
	char* second_pos = strchr(second,0);
	*/
		mov eax, 0
		mov edi, first_a
		call asm_strlen
		mov first_length,ecx
		mov first_pos, edi
		mov edi, second_a
		call asm_strlen
		mov second_pos, edi
		mov ebx, ecx
		mov edx, first_length
		sub ecx, edx
		jg second_is_longer
		neg ecx
		mov eax, second_pos
		xchg eax, first_pos
		mov second_pos, eax
		mov edx, ebx
	second_is_longer:
		mov first_length, edx
		mov lengthdiff, ecx
	/*
	char* result_pos = result;
	char carry = 0;
	for(int length=strlen(first);length>0;length--)
	{
		first_pos--;
		second_pos--;
		carry += (char2hex(*first_pos)+char2hex(*second_pos));
		(*result_pos) = hex2char(carry % 16);
		carry>>=4;
		result_pos++;
	}
	*/
		mov edi, first_pos
		mov esi, second_pos
		mov edx, result_a 
		mov ecx, first_length
		mov ebx, 0 //carry
		mov eax, 0
		asm_process_first_second:
		std
		lodsb
		call asm_char2hex
		add ebx, eax
		xchg edi, esi // edi,esi,edx -> esi,edi,edx
		lodsb
		call asm_char2hex
		add ebx, eax
		mov eax, ebx
		and eax, 15
		call asm_hex2char
		xchg edi, edx // esi,edi,edx -> edx, edi, esi 
		cld
		stosb
		xchg edi, esi // edx, edi, esi -> edi, edx, esi
		xchg esi, edx // edi, edx, esi -> edi,esi,edx
		shr ebx, 4
		loop asm_process_first_second
	/*
	while (lengthdiff>0)
	{
		second_pos--;
		carry += char2hex(*second_pos);
		(*result_pos) = hex2char(carry % 16);
		carry>>=4;
		result_pos++;
		lengthdiff--;
	}
	*/
		mov ecx, lengthdiff
		cmp ecx, 0
		je asm_lengthdiff_is_zero
		mov edi, esi
	asm_process_second:
		std
		lodsb
		call asm_char2hex
		add eax, ebx
		mov ebx, eax
		and eax, 15
		call asm_hex2char
		xchg edi, edx
		cld
		stosb
		xchg edi, edx
		shr ebx, 4
		loop asm_process_second
	asm_lengthdiff_is_zero:
	/*
	if (carry!=0)
	{
		(*result_pos) = hex2char(carry);
		result_pos++;
	}
	*/
		cld
		cmp ebx, 0
		jz asm_carry_is_zero
		mov eax, ebx
		mov edi, edx
		call asm_hex2char
		stosb
		mov edx, edi
	asm_carry_is_zero:
	/*
	(*result_pos)=0;
	result_pos--;
	*/
		mov eax, 0
		mov edi, edx
		stosb
	/*
	for(char* pos=result; pos<result_pos; pos++)
	{
		char temp = (*pos);
		(*pos) = (*result_pos);
		(*result_pos) = temp;
		result_pos--;
	}
	*/
		dec edx
		mov edi, result_a
		mov ebx, 0
	asm_reverse_result:
		mov al, [edi]
		mov bl, [edx]
		mov [edx], al
		mov [edi], bl
		inc edi
		dec edx
		cmp edi, edx 
		jl asm_reverse_result
		// returning result
		mov eax, result_a
		// restoring registers
		pop ebp
		pop edi
		pop esi
		pop ebx
		// deleting locals
		add esp, 16
		ret

	asm_strlen:
		mov ecx, -1
		repne scasb
		neg ecx
		sub ecx, 2
		sub edi, 2
		ret

/*
char char2hex(char digit)
{
	#0-9
	if ((digit>=48) && (digit<=57)) {
		return digit-48;
	#A-F
	} else if ((digit>=65) && (digit<=70)) {
		return digit-55;
	#a-f
	} else if ((digit>=97) && (digit<=102)) {
		return digit-87;
	} else {
	#invalid character
		return 0;
	}
}
*/
	asm_char2hex:
		cmp eax, 48
		jl asm_char2hex_else
		cmp eax, 57
		jg asm_char2hex_AF
		sub eax, 48
		jmp asm_char2hex_end
	asm_char2hex_AF:
		cmp eax, 65
		jl asm_char2hex_else
		cmp eax, 70
		jg asm_char2hex_s_af
		sub eax, 55
		jmp asm_char2hex_end
	asm_char2hex_s_af:
		cmp eax, 97
		jl asm_char2hex_else
		cmp eax, 102
		jg asm_char2hex_else
		sub eax, 87
		jmp asm_char2hex_end
		asm_char2hex_else:
		mov eax, 0
		asm_char2hex_end:
		ret
/*
char hex2char(char hex)
{
	if ((hex>=0) && (hex<=9)) {
		//0-9
		return hex+48;
	} else {
		//A-F
		return hex+55;
	} 
}
*/
		asm_hex2char:
		cmp eax, 0
		jl asm_hex2char_else
		cmp eax, 9
		jg asm_hex2char_else
		add eax, 48
		jmp asm_hex2char_end
		asm_hex2char_else:
		add eax, 55
		asm_hex2char_end:
		ret
	}
}

int main(void) {
	puts("enter first number");
	char* first = (char*)malloc(255);
	fgets(first,254,stdin);
	(*strchr(first,10)) = 0;
	puts("enter second number");
	char* second = (char*)malloc(255);
	fgets(second,254,stdin);
	(*strchr(second,10)) = 0;
	puts("result");
	char* result = (char*)malloc(256);
	puts(addhexstr(first,second,result));
	free(first);
	free(second);
	free(result);
	return 0;
}
