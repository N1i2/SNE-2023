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
	T0 byte '23', 0
	L0 sdword 0

.data
	buf byte 255 dup(0)
	buffer00000 sdword ?
	f01000 sdword ?
	T0T byte 255 dup(0)

.code


main proc
	START :
	push offset T0
	pop edx
	push offset T0
	push offset T0T
	call copytxt
	push offset T0T
	call texttolit
	push eax
	pop f01000
	push f01000
	call outlit
	mov eax,L0
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

