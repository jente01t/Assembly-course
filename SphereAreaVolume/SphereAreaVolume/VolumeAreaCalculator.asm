; Surface Area of a sphere : 4pi*r²
; Volume of a sphrere: 4pi*r²/3 = (4pi*r²)r/3

.model flat,c
.const
r8_4p0 real8 4.0
r8_3p0 real8 3.0

.code
CalcSpereAreaVolume proc
		push ebp
		mov ebp,esp

		xor eax,eax
		fld real8 ptr[ebp+8]		;ST(0) = 'r'
		fldz						;ST(0) = 0.0 ST(1) = 'r'
		fcomip st(0),st(1)			; compares 0.0 to r
		fstp st(0)

		jp Done						; jump if unoredered operands
		ja Done						; jump if r < 0.0

		fld real8 ptr[ebp+8]			; ST(0) = r
		fld st(0)					;ST(0) = r, ST(1) = r

		fmul st(0),st(0)			;ST(0) = r*r, st(1) = r

		fldpi						; st(0) = pi

		fmul[r8_4p0]				;st(0) = 4*pi
		fmulp						;st(0) = 4*pi*r*r

		mov edx,[ebp+16]
		fst real8 ptr [edx]
		

		;volume
		fmulp						;st(0) = 4*pi*r*r*r
		fdiv [r8_3p0]				;st(0) = 4*pi*r*r*r/3

		mov edx,[ebp+20]
		fstp real8 ptr[edx]

		mov eax,1

Done:	pop ebp
		ret

CalcSpereAreaVolume endp
	end