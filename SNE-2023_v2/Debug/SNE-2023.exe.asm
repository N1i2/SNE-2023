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
	T0 byte 'Yes', 0
	T1 byte 'No', 0
	T2 byte '3', 0
	L0 sdword 13
	L1 sdword 7
	L2 sdword 15
	L3 sdword 5
	T3 byte 'Yes', 0
	L4 sdword 2
	L5 sdword 0

.data
	buf byte 255 dup(0)
	buffer00000 sdword ?
	res01000 byte 255 dup(0)
	T0T byte 255 dup(0)
	T1T byte 255 dup(0)
	f04000 sdword ?
	s04000 sdword ?
	summa04000 sdword ?
	raznost04000 sdword ?
	proizv04000 sdword ?
	delen04000 sdword ?
	ostdelen04000 sdword ?
	octo04000 sdword ?
	oftext04000 sdword ?
	tonumb04000 byte 255 dup(0)
	T2T byte 255 dup(0)
	T3T byte 255 dup(0)

.code

proc_iftest proc, f01000 : dword, s01000 : dword
	push s01000
	pop f01000
	push f01000
	push s01000
	pop eax
	pop ebx
	cmp eax,ebx
	jne CKECKNOT1
	push offset T0
	push offset res01000
	call copytxt
jmp OUTCHECK1
CKECKNOT1 :
	push offset T1
	push offset res01000
	call copytxt
OUTCHECK1 :
	mov eax, offset res01000
jmp toend
divbyzero:
	push offset mesdivbyzero
	call outtxt
	call sleep
	call ExitProcess
toend:
	ret
proc_iftest endp

main proc
	START :
	push offset T2
	push offset tonumb04000
	call copytxt
	push L0
	pop f04000
	push L1
	pop s04000
	push f04000
	push s04000
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop summa04000
	push f04000
	push s04000
	pop ebx
	pop eax
	sub eax, ebx
	push eax
	pop raznost04000
	push f04000
	push s04000
	pop eax
	pop ebx
	mul ebx
	push eax
	pop proizv04000
	push f04000
	push s04000
	pop ebx
	pop eax
	cmp ebx,0
	je divbyzero
	mov edx,0
	idiv ebx
	push eax
	pop delen04000
	push f04000
	push s04000
	pop ebx
	pop eax
	cmp ebx,0
	je divbyzero
	mov edx,0
	idiv ebx
	push edx
	pop ostdelen04000
	push L2
	pop octo04000
	push offset tonumb04000
	pop edx
	push offset tonumb04000
	call texttolit
	push eax
	pop oftext04000
	push summa04000
	call outlit
	push raznost04000
	call outlit
	push proizv04000
	call outlit
	push delen04000
	call outlit
	push ostdelen04000
	call outlit
	push octo04000
	call outlit
	push oftext04000
	call outlit
	push oftext04000
	push L3
	pop eax
	pop ebx
	cmp eax,ebx
	jnl CKECKNOT2
	push offset T3
	call outtxt
jmp OUTCHECK2
CKECKNOT2 :
	push oftext04000
	push L4
	pop eax
	pop ebx
	mul ebx
	push eax
	pop oftext04000
	push oftext04000
	call outlit
OUTCHECK2 :
	push f04000
	push s04000
	pop edx
	pop edx
	push s04000
	push f04000
	call proc_iftest
	push eax
	push offset tonumb04000
	call copytxt
	push offset tonumb04000
	call outtxt
	mov eax,L5
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

