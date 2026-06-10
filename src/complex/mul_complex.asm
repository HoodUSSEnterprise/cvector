global mul_complex

section .text

mul_complex:
    ; 保存 c1 的值
    movsd xmm2, [rdx]      ; c1.real
    movsd xmm3, [rdx+8]    ; c1.imag
    movsd xmm4, [r8]       ; c2.real
    movsd xmm5, [r8+8]     ; c2.imag
    
    ; real = c1.real*c2.real - c1.imag*c2.imag
    movsd xmm0, xmm2
    mulsd xmm0, xmm4
    movsd xmm1, xmm3
    mulsd xmm1, xmm5
    subsd xmm0, xmm1
    
    ; imag = c1.real*c2.imag + c1.imag*c2.real
    movsd xmm1, xmm2
    mulsd xmm1, xmm5
    movsd xmm6, xmm3
    mulsd xmm6, xmm4
    addsd xmm1, xmm6
    
    ; 存结果
    movsd [rcx], xmm0
    movsd [rcx+8], xmm1
    
    mov rax, rcx
    ret