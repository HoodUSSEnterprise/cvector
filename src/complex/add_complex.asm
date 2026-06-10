global add_complex

section .text

; Windows x64 调用约定:
; rcx = 返回值指针 (调用者分配好的)
; rdx = &c1
; r8  = &c2

add_complex:
    ; 加载 c1
    movsd xmm0, [rdx]      ; c1.real
    movsd xmm1, [rdx+8]    ; c1.imag
    
    ; 加上 c2
    addsd xmm0, [r8]       ; real = c1.real + c2.real
    addsd xmm1, [r8+8]     ; imag = c1.imag + c2.imag
    
    ; 存结果到返回值指针
    movsd [rcx], xmm0
    movsd [rcx+8], xmm1
    
    ; 返回指针
    mov rax, rcx
    ret