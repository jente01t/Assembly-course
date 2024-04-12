.model flat,c
.code

MmxShifter proc
    push ebp
    mov ebp, esp

    xor eax, eax
    mov edx, DWORD PTR [ebp+16]     ; Load 'count'
    cmp edx, ShiftOpTableCount
    jae BadShiftOp

    mov eax, 1                      ; Set success return code
    movq mm0, [ebp + 8]            ; Load 'a'
    movd mm1, DWORD PTR [ebp+20]    ; Load 'count' into low dword
    jmp [ShiftOpTable + edx*4]

MmxPsllw: psllw mm0, mm1          ; Shift left logical word
    jmp SaveResult

MmxPsrlw: psrlw mm0, mm1          ; Shift right logical word
    jmp SaveResult

MmxPsraw: psraw mm0, mm1          ; Shift right arithmetic word
    jmp SaveResult

MmxPslld: pslld mm0, mm1          ; Shift left logical dword
    jmp SaveResult

MmxPsrld: psrld mm0, mm1          ; Shift right logical dword
    jmp SaveResult

MmxPsrad: psrad mm0, mm1          ; Shift right arithmetic dword
    jmp SaveResult

BadShiftOp: pxor mm0, mm0

SaveResult: mov edx, [ebp+24]     ; edx = ptr to 'b'
            movq [edx], mm0
            emms

            pop ebp
            ret

align 4

ShiftOpTable:
    dword MmxPsllw, MmxPsrlw, MmxPsraw
    dword MmxPslld, MmxPsrld, MmxPsrad

ShiftOpTableCount equ ($ - ShiftOpTable) / SIZE DWORD

MmxShifter endp
end
