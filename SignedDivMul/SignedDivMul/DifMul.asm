.386
.model flat,c
.code

; Return	: 0 error (division by zero)
;			: 1 succes
;
;Computation	*prod = a*b
;				*quo = a/b
;				*rem = a%b

IntegerMulDiv proc
		push ebp
		mov ebp,esp
		push ebx

		xor eax,eax

		mov ecx,[ebp+8]		;ecx = 'a'
		mov edx, [ebp+12]	;edx = 'b'
		
		or edx, edx
		jz InvalidDivisor

		imul edx,ecx		;eax = 'a*b'

		mov ebx,[ebp+16]	;ebx = 'prod'
		mov [ebx],edx

		mov eax,ecx			;eax = 'a'
		cdq					;edx:eax contains dividend$

		idiv dword ptr[ebp+12]

		mov ebx,[ebp+20]	; store quo
		mov [ebx],eax
		mov ebx,[ebp+24]	;store rem
		mov [ebx],edx
		mov eax,1

	InvalidDivisor: 
		pop ebx
		pop ebp
		ret

IntegerMulDiv endp
			end
