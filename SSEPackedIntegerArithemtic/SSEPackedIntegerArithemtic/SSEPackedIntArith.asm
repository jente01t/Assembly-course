.model flat,c
.code

SsePackedInt16_Add proc

		push ebp
		mov ebp,esp

		mov eax, [ebp+8]		; eax = pointer to a 
		mov ecx, [ebp+12]		; ecx = pointer to b
		mov edx, [ebp+16]		; edx = pointer to c

	movdqa xmm0, [eax]			; xmm0 = a
	movdqa xmm1, xmm0			; copy of content of xmm0 int xmm1
	movdqa xmm2, [ecx]			; xmm2 = b

; Addtion

		paddw xmm0,xmm2			; packed add -wraparound
		paddsw xmm1,xmm2		; packed add - staurated

;Save result

	movdqa [edx], xmm0			; save wraparounf at c[0]
	movdqa [edx+16],xmm1		; save saturated at c[1]

	pop ebp
	ret

SsePackedInt16_Add endp
	
SsePackedInt16_Sub proc
		push ebp
		mov ebp, esp

		mov eax, [ebp+8]		; eax = pointer to a 
		mov ecx, [ebp+12]		; ecx = pointer to b
		mov edx, [ebp+16]		; edx = pointer to c

; substarction 
		movdqa xmm0,[eax]		; xmm0 = a
		psubd xmm0,[ecx]		; xmm0 = a-b

; save
		movdqu [edx],xmm0
		pop ebp
		ret	
SsePackedInt16_Sub endp

SsePackedInt32_Mul proc
		push ebp
		mov ebp,esp

		mov eax, [ebp+8]		; eax = pointer to a 
		mov ecx, [ebp+12]		; ecx = pointer to b
		mov edx, [ebp+16]		; edx = pointer to c

; load paramaters
		movdqa xmm0,[eax]
		movdqa xmm1,[ecx]

		movdqa xmm2,xmm0
		pmulld xmm0,xmm1		; singed dword mul - low result
		pmullq xmm2,xmm1		; signed dword mul - qword reult
			
		movdqa [edx],xmm0		;c[0] pmulld result
		movdqa [edx+16],xmm2	;c[1] pmullq result

		pop ebp
		ret

SsePackedInt32_Mul endp
	end
