include windows.inc

includelib user32.lib
includelib kernel32.lib


TOTALLINES      EQU 1000000

MAKELABELS MACRO TotalLines:=<TOTALLINES>
    LOCAL cnt
    LOCAL tmp$
    LOCAL pub$
    LOCAL pubprev$
    cnt = 0
    tmp$ TEXTEQU <Label_>, %cnt, <::>
    
    WHILE cnt lt TotalLines
        .CODE
        pub$ TEXTEQU <Label_>, %cnt
        IF cnt gt 1
            cnt = cnt - 1
            pubprev$ TEXTEQU <Label_>, %cnt
            cnt = cnt + 1
        ENDIF
        tmp$ TEXTEQU <Label_>, %cnt, <::>
        PUBLIC pub$
        ;% echo tmp$
        % tmp$
        xor rax, rax
        add rbx, rcx
        IF cnt gt 1
        jne pubprev$
        ENDIF
        mov rax, qword ptr [pub$]
        cnt = cnt + 1
    ENDM
    
ENDM


.CONST




.DATA
;-----------------------------------------------------------------------------------------
; Output Initialized Data
;-----------------------------------------------------------------------------------------






.DATA?
;-----------------------------------------------------------------------------------------
; Output Uninitialized Data
;-----------------------------------------------------------------------------------------
align 08






