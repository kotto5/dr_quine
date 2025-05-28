; Outside comment out (* * ) 
section .text
global main
extern printf
main:
; Inside comment out (* _* `== `* _ *) 
push rbp
mov rbp, rsp

mov rax, 10
push rax
mov rax, 39
push rax
lea rax, [rel another_fmt]
push rax
mov rax, 39
push rax

mov rax, (48 - 3 - 5 - 1)
loop:
    cmp rax, 0
    jl .skip_if_body
    mov rdi, 10
    push rdi
    sub rax, 1
    jmp loop

.skip_if_body:
lea rdi, [rel another_fmt]
mov rsi, 10
mov rdx, 10
mov rcx, 10
mov r8, 10
mov r9, 10
xor rax, rax
mov rax, 0
call printf WRT ..plt
add rsp, 8 * (48 - 3 - 5 - 1 + 1) + 8 * 4
pop rbp
call return

return:
ret

section .data
another_fmt db '; Outside comment out (* * ) %csection .text%cglobal main%cextern printf%cmain:%c; Inside comment out (* _* `== `* _ *) %cpush rbp%cmov rbp, rsp%c%cmov rax, 10%cpush rax%cmov rax, 39%cpush rax%clea rax, [rel another_fmt]%cpush rax%cmov rax, 39%cpush rax%c%cmov rax, (48 - 3 - 5 - 1)%cloop:%c    cmp rax, 0%c    jl .skip_if_body%c    mov rdi, 10%c    push rdi%c    sub rax, 1%c    jmp loop%c%c.skip_if_body:%clea rdi, [rel another_fmt]%cmov rsi, 10%cmov rdx, 10%cmov rcx, 10%cmov r8, 10%cmov r9, 10%cxor rax, rax%cmov rax, 0%ccall printf WRT ..plt%cadd rsp, 8 * (48 - 3 - 5 - 1 + 1) + 8 * 4%cpop rbp%ccall return%c%creturn:%cret%c%csection .data%canother_fmt db %c%s%c%c'
