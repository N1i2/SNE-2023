.586
.model flat, stdcall

includelib kernel32.lib
includelib libucrt.lib
includelib mylib.lib

ExitProcess PROTO : DWORD
outtxt PROTO : DWORD
outlit PROTO : SDWORD
sleep PROTO
textlenght PROTO : DWORD
texttolit PROTO : DWORD
copytxt PROTO : DWORD,:DWORD

.stack 4096

.const
	mesdivbyzero byte 'Divide by zero',0
	L0 sdword 32000
	L1 sdword 32000
	L2 sdword 0

.data
	buf byte 255 dup(0)
	buffer00000 sdword ?
	a01000 sdword ?

.code


main proc
	START :
	push L0
	push L1
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop a01000
	push a01000
	call outlit
	mov eax,L2
	push 0
jmp toend
divbyzero:
	push offset mesdivbyzero
	call outtxt
toend:
	call sleep
	call ExitProcess
main endp
end main

