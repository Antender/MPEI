.MODEL flat,stdcall
INCLUDE "windows.inc"
INCLUDE "kernel32.inc"

.DATA

inHandle  DD 0;
outHandle DD 0;
digits    DB "0123456789abcdef"
tempX DD 0;
tempN DD 0;
tempP DD 0;

.CODE

setbits PROC C USES ebx, ArgX:DWORD, ArgN:DWORD, ArgP:DWORD
mov ebx, -1
mov eax, ArgX
mov ecx, ArgN
mov edx, ArgP
sub ecx, edx
neg ecx
shl ebx, cl
mov ecx, -1
neg edx 
add edx, 32
shr ecx, dl
and ebx, ecx
or  eax, ebx
ret
setbits ENDP

InputNumber proc
      push  ebp					; Сохраняем в стеке значение регистра EBP
      mov   ebp, esp				; Заносим в регистр EBP текущее значение вершины стека
      sub   esp, 16				; Резервируем 16 байт. Вводимая строка может содержать до 8 цифр.
						; 2 байта требуются для символов с кодами 13 и 10. Итого 10 байт.
						; 4 байта нужно для целочисленной переменной, куда будет записываться количество
						; введённых символов. Итого 14 байт. Но выделим 16 байт, т.е. 4 двойных слова
      push  ebx					; Сохраняем значения важных регистров
      push  esi
  
  ; Вводим строку
      push  0
      lea   eax, [ebp - 16]			; 4 байта по адресу [EBP – 16] предназначены для хранения количества введённых символов
      push  eax
      push  10d
      lea   eax, [ebp - 12]			; По адресу [EBP – 12] начинается память для вводимой строки
      push  eax
      push  inHandle
      call  ReadConsole

  ; Преобразуем строку в число
      xor   eax, eax				; Обнуляем регистр EAX ...
      xor   ebx, ebx				; ... и регистр EBX
      mov   ecx, [ebp - 16]			; Заносим в регистр ECX количество введённых символов
      sub   ecx, 2				; Символы с кодами 13 и 10 обрабатывать не надо
      lea   esi, [ebp - 12]			; Заносим в регистр ESI адрес начала строки

      test  ecx, ecx				; Используем команду TEST для сравнения с нулём
      jz    L2					; Если ECX = 0, то завершаем работу процедуры
  L1: mov   bl, [esi]				; Заносим в регистр BL текущий символ (три старших байта EBX
						; содержат 0, т.к. ранее была команда XOR EBX, EBX)
      lea   edx, [ebx - 48]			; Заносим в регистр EDX разность между кодом текущего символа и кодом символа '0'
      cmp   edx, 9				; Сравниваем значение в регистре EDX с 9
      ja    M1					; Если выше, то переходим к следующему сравнению
      sub   bl, 48				; Иначе получаем число из кода символа
      jmp   M3					; Переходим к действиям, учитывающим текущую цифру
  M1: lea   edx, [ebx - 97]			; Заносим в регистр EDX разность между кодом текущего символа и кодом символа 'a'
      cmp   edx, 102 - 97			; Сравниваем значение в регистре EDX с 5
      ja    M2					; Если выше, то переходим к следующему сравнению
      sub   bl, 97 - 10d			; Иначе получаем число из кода символа
      jmp   M3					; Переходим к действиям, учитывающим текущую цифру
  M2: lea   edx, [ebx - 65] 			; Заносим в регистр EDX разность между кодом текущего символа и кодом символа 'A'
      cmp   edx, 70 - 65			; Сравниваем значение в регистре EDX с 5
      ja    L2					; Если выше, то завершаем процедуру. Результат не определён,
						; т.к. был введён некорректный символ
      sub   bl, 65 - 10d			; Иначе получаем число из кода символа
  M3: sal   eax, 4				; Умножаем EAX на 16
      add   eax, ebx				; Прибавляем текущую цифру
      inc   esi					; Переходим к следующему символу
      dec   ecx					; Уменьшаем ECX на 1
      jnz   L1					; Если ECX не равно 0, продолжаем цикл

  L2: pop   esi					; Восстанавливаем значения использовавшихся регистров
      pop   ebx
      mov   esp, ebp				; Освобождаем стек
      pop   ebp					; Восстанавливаем значение регистра EBP
      ret
InputNumber endp

OutputNumber proc
      push  ebp					; Сохраняем в стеке значение регистра EBP
      mov   ebp, esp				; Заносим в регистр EBP текущее значение вершины стека
      sub   esp, 12				; Выделяем в стеке место под формируемую строку
      push  esi
      
  ; Преобразуем число в строку
      mov   eax, [ebp + 8]			; Заносим в регистр EAX переданный параметр
      mov   ecx, 8				; Заносим в регистр ECX количество символов строки
      mov   byte ptr [ebp - 1], 10		; Добавляем в конец строки символы с кодами 13 и 10 для перевода курсора
      mov   byte ptr [ebp - 2], 13
      lea   esi, [ebp - 3]			; Начиная с адреса [EBP - 3] будут заносится цифры
  L3: mov   edx, eax				; Копируем значение регистра EAX в регистр EDX
      and   edx, 1111b				; Получаем остаток от деления на 16
      shr   eax, 4				; Делим исходное число на 16
      mov   dl, digits[edx]			; По полученному остатку от деления берём цифру ...
      mov   [esi], dl				; ... и записываем её в строку
      dec   esi					; Уменьшаем адрес, т.к. строка формируется с конца
      dec   ecx					; Уменьшаем ECX на 1
      jnz   L3					; Если ECX не равно 0, продолжаем цикл
      
  ; Выводим строку
      inc   esi					; Регистр ESI указывает на начало строки
      push  0
      push  0
      push  10
      push  esi
      push  outHandle
      call  WriteConsole

      pop   esi
      mov   esp, ebp				; Освобождаем стек
      pop   ebp					; Восстанавливаем значение регистра EBP
      ret   4					; Удаляем из стека переданный параметр и возвращаемся
OutputNumber endp

stdInHandle EQU -10d
stdOutHandle EQU -11d

main:
INVOKE GetStdHandle, stdOutHandle
mov    outHandle, eax
INVOKE GetStdHandle, stdInHandle
mov    inHandle, eax
call   InputNumber
mov    tempX, eax
call   InputNumber
mov    tempN, eax
cmp    eax, 31
jg     error
cmp    eax, 0
jl     error
call   InputNumber
cmp    eax, 0
jl     error
mov    tempP, eax
mov    eax, tempP
add    eax, tempN
cmp    eax, 32
jg     error
INVOKE invert, tempX, tempN, tempP
push   eax 
call   OutputNumber
INVOKE ExitProcess,0
error:
END main
