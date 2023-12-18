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
	L0 sdword 10
	L1 sdword 20
	T0 byte 'hbjx', 0
	L2 sdword 0

.data
	buf byte 255 dup(0)
	buffer00000 sdword ?
	j01000 sdword ?
	T0T byte 255 dup(0)

.code


main proc
	START :
	push L0
	pop j01000
	push j01000
	push L1
	pop eax
	pop ebx
	cmp eax,ebx
	jng CKECKNOT1
	push offset T0
	call outtxt
CKECKNOT1 :
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

