.586
.model flat, stdcall

includelib kernel32.lib
includelib libucrt.lib

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
	T0 byte 'Yes', 0
	T1 byte 'No', 0
	T2 byte '5', 0
	L0 sdword 8
	L1 sdword 14
	L2 sdword 0

.data
	buf byte 255 dup(0)
	buffer00000 sdword ?
	T0T byte 255 dup(0)
	T1T byte 255 dup(0)
	x04000 sdword ?
	T2T byte 255 dup(0)
	o04000 sdword ?
	j04000 sdword ?

.code

proc_sum proc, w01000 : dword, d01000 : dword
	push w01000
	push d01000
	pop eax
	pop ebx
	cmp eax,ebx
	jnl CKECKNOT1
	push offset T0
	call outtxt
	push w01000
	push d01000
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop w01000
jmp OUTCHECK1
CKECKNOT1 :
	push offset T1
	call outtxt
	push w01000
	push d01000
	pop ebx
	pop eax
	sub eax, ebx
	push eax
	pop w01000
OUTCHECK1 :
	mov eax,w01000
jmp toend
divbyzero:
	push offset mesdivbyzero
	call outtxt
	call sleep
	call ExitProcess
toend:
	ret
proc_sum endp

main proc
	START :
	push offset T2
	pop edx
	push offset T2
	push offset T2T
	call copytxt
	push offset T2T
	call texttolit
	push eax
	pop x04000
	push x04000
	call outlit
	push x04000
	push L0
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop x04000
	push x04000
	call outlit
	push L1
	pop j04000
	push x04000
	push j04000
	pop edx
	pop edx
	push j04000
	push x04000
	call proc_sum
	push eax
	pop o04000
	push o04000
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

