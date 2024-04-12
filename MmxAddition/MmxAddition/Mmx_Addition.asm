.model flat,c
.code

MmxVal proc
		push ebp
		mov ebp,esp

		mov eax,[ebp+24]		; load 'add_op'
		cmp eax,AddOpTableCount	; compare to table count
		jae BadAddOp			; jump if 'add_op' is invalid

		movq mm0,[ebp+8]		; load 'a'
		movq mm1,[ebp+16]		; load 'b'
		jmp [AddOpTable+eax*4]	; jump to specified 'add_op'

MmxPaddb: paddb mm0,mm1			; packed byte addition using wraparound
		jmp Saveresult

MmxPaddsb: paddsb mm0,mm1		; packed byte addition using signed stauration
		jmp Saveresult

MmxPaddusb: paddusb mm0,mm1		; packed byte addition using unsigned stauration
		jmp Saveresult

MmxPaddw: paddw mm0,mm1			; packed word addition using wraparound
		jmp Saveresult

MmxPaddsw: paddsw mm0,mm1		; packed word addition using signed stauration
		jmp Saveresult

MmxPaddusw: paddusw mm0,mm1		; packed word addition using unsigned stauration
		jmp Saveresult

MmxPaddd: paddd mm0,mm1			; packed dword addition using unsigned stauration
		jmp Saveresult

BadAddOp: pxor mm0,mm0

Saveresult: movd eax,mm0		; eaxm = low dword of register mm0
		pshufw mm2,mm0, 01001110b	; swap high and low dwords
		movd edx,mm2			; edx : eax = final result
		emms					; clear mmx state
		
		
		pop ebp
		ret


		align 4

AddOpTable:
		dword MmxPaddb, MmxPaddsb, MmxPaddusb
		dword MmxPaddw, MmxPaddsw, MmxPaddusw, MmxPaddd

AddOpTableCount equ ($-AddOpTable)/ size dword

MmxVal endp
	end