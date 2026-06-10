global sub_complex

section .text

sub_complex:
    movsd xmm0, [rdx]
    movsd xmm1, [rdx+8]
    
    subsd xmm0, [r8]
    subsd xmm1, [r8+8]
    
    movsd [rcx], xmm0
    movsd [rcx+8], xmm1
    
    mov rax, rcx
    ret