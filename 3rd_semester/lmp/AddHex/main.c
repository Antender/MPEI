#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

char char2hex(char digit)
{
	//0-9
	if ((digit>=48) && (digit<=57)) {
		return digit-48;
	//A-F
	} else if ((digit>=65) && (digit<=70)) {
		return digit-55;
	//a-f
	} else if ((digit>=97) && (digit<=102)) {
		return digit-87;
	} else {
	//invalid character
		return 0;
	}
}

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

//adds two hex text strings together, result is at least 1 character bigger then other strings
char* addhexstr(char* first, char* second, char* result) {
	int lengthdiff = strlen(second)-strlen(first);
	if (lengthdiff<0) {
		char* temp = first;
		first = second;
		second = temp;
		lengthdiff= -lengthdiff;
	}
	char* first_pos = strchr(first,0);
	char* second_pos = strchr(second,0);
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
	while (lengthdiff>0)
	{
		second_pos--;
		carry += char2hex(*second_pos);
		(*result_pos) = hex2char(carry % 16);
		carry>>=4;
		result_pos++;
		lengthdiff--;
	}
	if (carry!=0)
	{
		(*result_pos) = hex2char(carry);
		result_pos++;
	}
	(*result_pos)=0;
	result_pos--;
	for(char* pos=result; pos<result_pos; pos++)
	{
		char temp = (*pos);
		(*pos) = (*result_pos);
		(*result_pos) = temp;
		result_pos--;
	}
	return result;
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
