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
	L0 sdword 2
	L1 sdword 1
	L2 sdword 4
	L3 sdword 0

.data
	buf byte 255 dup(0)
	buffer00000 sdword ?
	g01000 sdword ?
	f01000 sdword ?

.code


main proc
	START :
	push L0
	push L1
	pop ebx
	pop eax
	sub eax, ebx
	push eax
	pop g01000
	push L2
	push g01000
	pop ebx
	pop eax
	cmp ebx,0
	je divbyzero
	mov edx,0
	idiv ebx
	push eax
	pop f01000
	mov eax,L3
	push 0
CKECKNOT0 :
jmp toend
divbyzero:
	push offset mesdivbyzero
	call outtxt
toend:
	call sleep
	call ExitProcess
main endp
end main

