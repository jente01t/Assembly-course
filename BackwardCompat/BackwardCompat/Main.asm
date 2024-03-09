;------------- 64-bit code: x64-----------------
;.code
;main	proc
		;mov rax,2
		;mov rbx,3
		;mov rcx,4
		;ret
;main	endp
;end



;------------------- 32-bit code: x86------------------
;.386
;.model flat
;.code
;main	proc
;		mov eax,2
;		mov ebx,3
;		mov ecx,4
;		ret
;main	endp
;end	main

;----------------- 16-bit code: ------------------------
.386
.model flat
.code
main	proc
		mov ax,2
		mov bx,3
		mov cx,4
		ret
main	endp
end		main
