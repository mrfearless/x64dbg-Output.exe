.686
.MMX
.XMM
.x64

option casemap : none
option win64 : 11
option frame : auto
option stackbase : rsp

_WIN64 EQU 1
WINVER equ 0501h

;DEBUG64 EQU 1

IFDEF DEBUG64
    PRESERVEXMMREGS equ 1
    includelib \UASM\lib\x64\Debug64.lib
    DBG64LIB equ 1
    DEBUGEXE textequ <'\UASM\bin\DbgWin.exe'>
    include \UASM\include\debug64.inc
    .DATA
    RDBG_DbgWin	DB DEBUGEXE,0
    .CODE
ENDIF

include Output.inc



.CODE


OPTION PROC:PUBLIC

;-------------------------------------------------------------------------------------
; Startup
;-------------------------------------------------------------------------------------
main PROC FRAME


    MAKELABELS

	;Invoke ExitProcess, eax
    ret
main ENDP
	




end main

