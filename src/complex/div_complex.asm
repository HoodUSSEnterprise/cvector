global div_complex

section .text

div_complex:
    ; rcx = &result, rdx = &c1, r8 = &c2
    
    ; 加载 c1
    movsd xmm0, [rdx]      ; c1.real
    movsd xmm1, [rdx+8]    ; c1.imag
    
    ; 加载 c2
    movsd xmm2, [r8]       ; c2.real
    movsd xmm3, [r8+8]     ; c2.imag
    
    ; 保存 c1 的值
    movsd xmm4, xmm0       ; c1.real
    movsd xmm5, xmm1       ; c1.imag
    
    ; 计算 k = c2.real² + c2.imag²
    movsd xmm0, xmm2
    mulsd xmm0, xmm0       ; c2.real²
    movsd xmm1, xmm3
    mulsd xmm1, xmm1       ; c2.imag²
    addsd xmm0, xmm1       ; k
    movsd xmm6, xmm0       ; 保存 k
    
    ; real = (c1.real*c2.real + c1.imag*c2.imag) / k
    movsd xmm0, xmm4
    mulsd xmm0, xmm2       ; c1.real * c2.real
    movsd xmm1, xmm5
    mulsd xmm1, xmm3       ; c1.imag * c2.imag
    addsd xmm0, xmm1
    divsd xmm0, xmm6
    
    ; imag = (c1.imag*c2.real - c1.real*c2.imag) / k
    movsd xmm1, xmm5
    mulsd xmm1, xmm2       ; c1.imag * c2.real
    movsd xmm7, xmm4
    mulsd xmm7, xmm3       ; c1.real * c2.imag
    subsd xmm1, xmm7
    divsd xmm1, xmm6
    
    ; 存结果
    movsd [rcx], xmm0      ; real
    movsd [rcx+8], xmm1    ; imag
    mov rax, rcx
    ret