global is_equal_complex

section .text

is_equal_complex:
    ; rcx = &c1, rdx = &c2
    ; 返回值放在 eax (int)
    
    sub rsp, 40
    
    ; 比较 real
    movsd xmm0, [rcx]
    movsd xmm1, [rdx]
    subsd xmm0, xmm1
    andpd xmm0, [rel abs_mask]
    comisd xmm0, [rel eps]
    ja .false
    
    ; 比较 imag
    movsd xmm0, [rcx+8]
    movsd xmm1, [rdx+8]
    subsd xmm0, xmm1
    andpd xmm0, [rel abs_mask]
    comisd xmm0, [rel eps]
    ja .false
    
    mov eax, 1
    add rsp, 40
    ret
    
.false:
    xor eax, eax
    add rsp, 40
    ret

section .rodata
align 8
abs_mask:
    dq 0x7FFFFFFFFFFFFFFF
eps:
    dq 0x3EB0C6F7A0B5ED8D