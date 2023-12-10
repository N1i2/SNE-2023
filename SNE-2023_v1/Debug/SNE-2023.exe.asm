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
	T0 byte '5', 0
	L0 sdword 8
	L1 sdword 0

.data
	buf byte 255 dup(0)
	buffer00000 sdword ?
	x01000 sdword ?
	h01000 byte 255 dup(0)
	T0T byte 255 dup(0)

.code


main proc
	START :
	push offset T0
	push offset h01000
	call copytxt
	push offset h01000
	pop edx
	push offset h01000
	call texttolit
	push eax
	pop x01000
	push x01000
	call outlit
	push x01000
	push L0
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop x01000
	push x01000
	call outlit
	mov eax,L1
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

