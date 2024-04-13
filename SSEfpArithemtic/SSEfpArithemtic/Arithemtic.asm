.model flat, c
.const

				align 16

AbsMaskFloat	dword 7fffffffh, 0ffffffffh, 0ffffffffh, 0ffffffffh
AbsMaskDouble	qword 7fffffffffffffffh, 0fffffffffffffffh

.code
SseArithemticOperationsFloat proc
		push ebp
		mov ebp,esp

		movss xmm0, real4 ptr [ebp+8]		; xmm0 = 'a'
		movss xmm1, real4 ptr [ebp+12]		; xmm1 = 'b'

		mov eax,[ebp+16]					; eax = 'c'

; Addition
		movss xmm2,xmm0
		addss xmm2,xmm1						; xmm2 = a+b
		movss real4 ptr [eax],xmm2

; Substraction
		movss xmm3,xmm0
		subss xmm3,xmm1						; xmm3 = a-b
		movss real4 ptr [eax+4], xmm3

; Multiplication
		movss xmm4,xmm0
		mulss xmm4,xmm1						; xmm4 = a*b
		movss real4 ptr [eax+8],xmm4

; Devision
		movss xmm5,xmm0
		divss xmm5,xmm1						; xmm5 = a/b
		movss real4 ptr [eax+12],xmm5

; Minimum
		movss xmm6,xmm0
		minss xmm6,xmm1						; xmm6 = min(a,b)
		movss real4 ptr [eax+16],xmm6

; Maximum
		movss xmm7,xmm0
		maxss xmm7,xmm1						; xmm7 = max(a,b)
		movss real4 ptr [eax+20],xmm7

; Absolute value
		andps xmm1, [AbsMaskFloat]			; xmm1 = fabs(b)
		movss real4 ptr [eax+24],xmm1

; Square root
		sqrtss xmm0,xmm1					; xmm0 = sqrt(fabs(b))
		movss real4 ptr [eax+28],xmm0

		pop ebp
		ret

SseArithemticOperationsFloat endp

; in de plaats van float nu double

SseArithemticOperationsDouble proc
		push ebp
		mov ebp,esp

		movsd xmm0, real8 ptr [ebp+8]
		movsd xmm1, real8 ptr [ebp+16]
		mov eax,[ebp+24]

		movsd xmm2,xmm0
		addsd xmm2,xmm1
		movsd real8 ptr [eax],xmm2

		movsd xmm3,xmm0
		subsd xmm3,xmm1
		movsd real8 ptr [eax+8],xmm3

		movsd xmm4,xmm0
		mulsd xmm4,xmm1
		movsd real8 ptr [eax+16],xmm4

		movsd xmm5,xmm0
		divsd xmm5,xmm1
		movsd real8 ptr [eax+24],xmm5
		
		movsd xmm6,xmm0
		minsd xmm6,xmm1
		movsd real8 ptr [eax+32],xmm6

		movsd xmm7,xmm0
		maxsd xmm7,xmm1
		movsd real8 ptr [eax+40],xmm7

		andpd xmm1, [AbsMaskDouble]
		movsd real8 ptr [eax+48],xmm1

		sqrtsd xmm0,xmm1
		movsd real8 ptr [eax+56],xmm0

		pop ebp
		ret

SseArithemticOperationsDouble endp
	end
