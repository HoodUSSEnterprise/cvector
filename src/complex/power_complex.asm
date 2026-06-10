global power_complex
extern mul_complex

section .text

power_complex:
    ; Windows x64 调用约定:
    ; rcx = 返回值指针
    ; rdx = &c1
    ; r8  = k (int)
    
    push rbx
    push rsi
    push rdi
    sub rsp, 64
    
    ; 保存参数
    mov [rsp+48], rcx     ; 返回值指针
    mov [rsp+56], rdx     ; &c1
    mov ebx, r8d          ; k
    
    ; 初始化 res = {1, 0} 到栈上
    movsd xmm0, [rel one]
    movsd xmm1, [rel zero]
    movsd [rsp], xmm0     ; res.real
    movsd [rsp+8], xmm1   ; res.imag
    
    ; 如果 k == 0，直接返回 (1, 0)
    cmp ebx, 0
    je .copy_result
    
    ; 如果 k == 1，返回 c1 的副本
    cmp ebx, 1
    je .copy_c1
    
    ; k >= 2，循环计算
    mov esi, ebx          ; esi = k
    dec esi               ; 需要乘 (k-1) 次
    
.loop:
    ; 调用 mul_complex(res, c1)
    ; mul_complex 需要: rcx=临时结果, rdx=&res, r8=&c1
    lea rdx, [rsp]        ; &res
    mov r8, [rsp+56]      ; &c1
    lea rcx, [rsp+16]     ; 临时结果指针
    call mul_complex
    
    ; 复制临时结果回 res
    movsd xmm0, [rsp+16]
    movsd xmm1, [rsp+24]
    movsd [rsp], xmm0
    movsd [rsp+8], xmm1
    
    dec esi
    jnz .loop
    
    jmp .copy_result
    
.copy_c1:
    ; 复制 c1 到结果
    mov rcx, [rsp+48]
    mov rdx, [rsp+56]
    movsd xmm0, [rdx]
    movsd xmm1, [rdx+8]
    movsd [rcx], xmm0
    movsd [rcx+8], xmm1
    mov rax, rcx
    jmp .return
    
.copy_result:
    ; 复制 res 到返回值指针
    mov rcx, [rsp+48]
    movsd xmm0, [rsp]
    movsd xmm1, [rsp+8]
    movsd [rcx], xmm0
    movsd [rcx+8], xmm1
    mov rax, rcx
    
.return:
    add rsp, 64
    pop rdi
    pop rsi
    pop rbx
    ret

section .rodata
align 8
one:
    dq 1.0
zero:
    dq 0.0