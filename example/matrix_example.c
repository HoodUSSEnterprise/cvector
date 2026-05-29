#include "matrix/matrix.h"
#include "complex/complex.h"
#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("========================================\n");
    printf("  CVector Matrix Library Example\n");
    printf("========================================\n\n");

    /* ======================== 1. Create Matrices ======================== */
    printf("--- 1. Create Matrices ---\n");

    // Create an int matrix (2x3) from an int array
    int data_i[] = {1, 2, 3, 4, 5, 6};
    MatrixI *m_i = create_matrixi(2, 3, data_i, 6);
    printf("m_i (int 2x3):\n");
    print_matrix(m_i);

    // Create a double matrix (3x3) from a double array
    double data_d[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    MatrixD *m_d = create_matrixd(3, 3, data_d, 9);
    printf("m_d (double 3x3):\n");
    print_matrix(m_d);

    /* ======================== 2. Special Matrices ======================== */
    printf("--- 2. Special Matrices ---\n");

    MatrixD *ident = identity_matrixd(4);
    printf("Identity matrix (4x4):\n");
    print_matrix(ident);

    MatrixD *zero = zero_matrixd(2, 3);
    printf("Zero matrix (2x3):\n");
    print_matrix(zero);

    double diag_data[] = {1.0, 2.0, 3.0, 4.0};
    MatrixD *diag = diag_matrixd(diag_data, 4);
    printf("Diagonal matrix from [1,2,3,4]:\n");
    print_matrix(diag);

    MatrixD *eye_mat = eye_matrixd(3, 5);
    printf("Eye matrix (3x5):\n");
    print_matrix(eye_mat);

    /* ======================== 3. Random Matrix ======================== */
    printf("--- 3. Random Matrix ---\n");

    MatrixD *rand_mat = random_matrixd(3, 4, 0.0, 10.0);
    printf("Random 3x4 matrix (uniform [0,10)):\n");
    print_matrix(rand_mat);

    /* ======================== 4. Copy Matrix ======================== */
    printf("--- 4. Copy Matrix ---\n");

    MatrixD *m_copy = copy_matrix(m_d);
    printf("Copy of m_d:\n");
    print_matrix(m_copy);

    /* ======================== 5. Matrix Addition ======================== */
    printf("--- 5. Matrix Addition ---\n");

    double data_b[] = {9.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0};
    MatrixD *m_b = create_matrixd(3, 3, data_b, 9);
    MatrixD *m_sum = add_matrix(m_d, m_b);
    printf("m_d + m_b:\n");
    print_matrix(m_sum);

    /* ======================== 6. Matrix Subtraction ======================== */
    printf("--- 6. Matrix Subtraction ---\n");

    MatrixD *m_diff = sub_matrix(m_d, m_b);
    printf("m_d - m_b:\n");
    print_matrix(m_diff);

    /* ======================== 7. Scalar Multiplication ======================== */
    printf("--- 7. Scalar Multiplication ---\n");

    MatrixD *m_scaled = scalar_mul_matrix(m_d, 2.5);
    printf("m_d * 2.5:\n");
    print_matrix(m_scaled);

    /* ======================== 8. Matrix Multiplication ======================== */
    printf("--- 8. Matrix Multiplication ---\n");

    // 3x3 * 3x3
    MatrixD *m_prod = mul_matrix(m_d, m_b);
    printf("m_d * m_b (3x3 * 3x3):\n");
    print_matrix(m_prod);

    // Also demonstrate mixed-type multiplication: int * double
    MatrixD *m_mixed = mul_matrix(m_i, m_d);
    printf("m_i (int) * m_d (double):\n");
    print_matrix(m_mixed);

    /* ======================== 9. Transpose ======================== */
    printf("--- 9. Transpose ---\n");

    MatrixD *m_t = transpose_matrix(m_d);
    printf("transpose(m_d):\n");
    print_matrix(m_t);

    /* ======================== 10. Determinant ======================== */
    printf("--- 10. Determinant ---\n");

    double det = det_matrix(m_d);
    printf("det(m_d) = %lf\n\n", det);

    // Matrix with det = 0
    int singular_data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    MatrixI *m_singular = create_matrixi(3, 3, singular_data, 9);
    int det_i = det_matrix(m_singular);
    printf("det(singular 3x3) = %d\n\n", det_i);

    /* ======================== 11. Matrix Power ======================== */
    printf("--- 11. Matrix Power ---\n");

    MatrixD *m_pow3 = pow_matrix(m_d, 3);
    printf("m_d^3:\n");
    print_matrix(m_pow3);

    // Negative power = inverse^|n|
    MatrixD *m_pow_neg = pow_matrix(m_d, -2);
    printf("m_d^(-2) = (m_d^(-1))^2:\n");
    print_matrix(m_pow_neg);

    /* ======================== 12. Inverse ======================== */
    printf("--- 12. Inverse ---\n");

    MatrixD *m_inv = inv_matrix(m_d);
    printf("inv(m_d):\n");
    print_matrix(m_inv);

    // Verify: m_d * inv(m_d) should be identity
    MatrixD *verify = mul_matrix(m_d, m_inv);
    printf("m_d * inv(m_d) (should be identity):\n");
    print_matrix(verify);

    /* ======================== 13. Rank and Trace ======================== */
    printf("--- 13. Rank and Trace ---\n");

    int rank = rank_matrix(m_d);
    double trace = trace_matrix(m_d);
    printf("rank(m_d) = %d\n", rank);
    printf("trace(m_d) = %lf\n\n", trace);

    /* ======================== 14. Minor Matrix ======================== */
    printf("--- 14. Minor Matrix ---\n");

    // Minor after removing row 1, col 1 (0-indexed)
    MatrixD *m_minor = minor_matrix(m_d, 1, 1);
    printf("minor(m_d, row=1, col=1):\n");
    print_matrix(m_minor);

    /* ======================== 15. Cofactor Matrix ======================== */
    printf("--- 15. Cofactor Matrix ---\n");

    MatrixD *m_cof = cofactor_matrix(m_d);
    printf("cofactor(m_d):\n");
    print_matrix(m_cof);

    /* ======================== 16. Adjugate Matrix ======================== */
    printf("--- 16. Adjugate Matrix ---\n");

    MatrixD *m_adj = adjugate_matrix(m_d);
    printf("adjugate(m_d):\n");
    print_matrix(m_adj);

    // Verify: adj(A) = det(A) * inv(A)  (for invertible matrices)
    MatrixD *adj_times_inv = scalar_mul_matrix(m_inv, det);
    printf("det(m_d) * inv(m_d) (should equal adjugate):\n");
    print_matrix(adj_times_inv);

    /* ======================== 17. Extract Column / Diagonal ======================== */
    printf("--- 17. Extract Column and Diagonal ---\n");

    MatrixD *col1 = col_vector_matrix(m_d, 1);
    printf("Column 1 of m_d:\n");
    print_matrix(col1);

    double *diag_vals = get_diag_matrix(m_d);
    printf("Diagonal of m_d: [%lf, %lf, %lf]\n\n", diag_vals[0], diag_vals[1], diag_vals[2]);
    free(diag_vals);

    /* ======================== 18. Find Element ======================== */
    printf("--- 18. Find Element ---\n");

    Pos p = find_matrix(m_d, 5.0);
    if (p.x != -1 && p.y != -1)
        printf("Element 5.0 found at position (%d, %d)\n", p.x, p.y);
    else
        printf("Element 5.0 not found\n");

    p = find_matrix(m_d, 999.0);
    if (p.x == -1 && p.y == -1)
        printf("Element 999.0 correctly reported as not found\n\n");

    /* ======================== 19. Replace Elements ======================== */
    printf("--- 19. Replace Elements ---\n");

    // Replace 5.0 with 99.0 in a copy of m_d
    MatrixD *m_replaced = replace_matrix(m_copy, 5.0, 99.0);
    printf("m_copy with 5.0 -> 99.0:\n");
    print_matrix(m_replaced);

    /* ======================== 20. Remove Row / Column ======================== */
    printf("--- 20. Remove Row / Column ---\n");

    MatrixD *m_no_row1 = remove_matrix(m_d, 1, 0);  // axis=0: remove row 1
    printf("m_d with row 1 removed:\n");
    print_matrix(m_no_row1);

    MatrixD *m_no_col1 = remove_matrix(m_d, 1, 1);  // axis=1: remove column 1
    printf("m_d with column 1 removed:\n");
    print_matrix(m_no_col1);

    /* ======================== 21. Concatenate Matrices ======================== */
    printf("--- 21. Concatenate Matrices ---\n");

    // Concatenate horizontally (axis=1)
    MatrixD *m_cat_h = cat_matrix(m_d, m_b, 1);
    printf("m_d || m_b (horizontal concat, axis=1):\n");
    print_matrix(m_cat_h);

    // Concatenate vertically (axis=0)
    MatrixD *m_cat_v = cat_matrix(m_d, m_b, 0);
    printf("m_d || m_b (vertical concat, axis=0):\n");
    print_matrix(m_cat_v);

    /* ======================== 22. Compare Matrices ======================== */
    printf("--- 22. Compare Matrices ---\n");

    printf("m_d == m_copy? %s\n", is_equal_matrix(m_d, m_copy) ? "true" : "false");
    printf("m_d == m_b?   %s\n\n", is_equal_matrix(m_d, m_b) ? "true" : "false");

    /* ======================== 23. Check Matrix Properties ======================== */
    printf("--- 23. Check Matrix Properties ---\n");

    printf("Is m_d identity?     %s\n", is_identity_matrix(m_d) ? "yes" : "no");
    printf("Is m_d invertible?   %s\n", is_inv_matrix(m_d) ? "yes" : "no");
    printf("Is identity matrix identity? %s\n", is_identity_matrix(ident) ? "yes" : "no");
    printf("Is m_d orthogonal?   %s\n", is_orth_matrix(m_d) ? "yes" : "no");

    // Check positive definiteness on a symmetric positive definite matrix
    double pd_data[] = {2, -1, 0, -1, 2, -1, 0, -1, 2};
    MatrixD *m_pd = create_matrixd(3, 3, pd_data, 9);
    printf("Is pd matrix positive definite? %s\n\n", is_positive_matrix(m_pd) ? "yes" : "no");

    /* ======================== 24. LU Decomposition ======================== */
    printf("--- 24. LU Decomposition ---\n");

    double lu_data[] = {2, 1, 1, 4, 3, 3, 8, 7, 9};
    MatrixD *m_lu = create_matrixd(3, 3, lu_data, 9);
    printf("Matrix A for LU decomposition:\n");
    print_matrix(m_lu);

    if (can_lu_decomposition(m_lu))
    {
        MatrixD *L = NULL, *U = NULL;
        doolittle_matrixd(m_lu, &L, &U);
        printf("L (Doolittle):\n");
        print_matrix(L);
        printf("U (Doolittle):\n");
        print_matrix(U);

        // Verify: L * U should equal original
        MatrixD *lu_prod = mul_matrix(L, U);
        printf("L * U (should equal original):\n");
        print_matrix(lu_prod);

        free_matrix(L);
        free_matrix(U);
        free_matrix(lu_prod);
    }

    // Cholesky decomposition (symmetric positive definite)
    double chol_data[] = {4, 2, 2, 2, 5, 3, 2, 3, 6};
    MatrixD *m_chol = create_matrixd(3, 3, chol_data, 6);
    printf("Matrix A for Cholesky decomposition:\n");
    print_matrix(m_chol);

    MatrixD *L_chol = NULL;
    cholesky_matrixd(m_chol, &L_chol);
    printf("L (Cholesky):\n");
    print_matrix(L_chol);

    MatrixD *chol_prod = mul_matrix(L_chol, transpose_matrix(L_chol));
    printf("L * L^T (should equal original):\n");
    print_matrix(chol_prod);

    free_matrix(m_chol);
    free_matrix(L_chol);
    free_matrix(chol_prod);
    free_matrix(m_lu);

    /* ======================== 25. QR Decomposition ======================== */
    printf("--- 25. QR Decomposition ---\n");

    double qr_data[] = {1.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 1.0};
    MatrixD *m_qr = create_matrixd(3, 3, qr_data, 9);
    printf("Matrix A for QR decomposition:\n");
    print_matrix(m_qr);

    MatrixD *Q = NULL, *R = NULL;
    qr_gs_matrixd(m_qr, &Q, &R);
    printf("Q (Gram-Schmidt):\n");
    print_matrix(Q);
    printf("R (Gram-Schmidt):\n");
    print_matrix(R);

    // Verify: Q * R = A
    MatrixD *qr_prod = mul_matrix(Q, R);
    printf("Q * R (should equal A):\n");
    print_matrix(qr_prod);

    // Verify: Q^T * Q = I (orthogonal)
    MatrixD *qtq = mul_matrix(transpose_matrix(Q), Q);
    printf("Q^T * Q (should be identity):\n");
    print_matrix(qtq);

    free_matrix(m_qr);
    free_matrix(Q);
    free_matrix(R);
    free_matrix(qr_prod);
    free_matrix(qtq);

    /* ======================== 26. Eigenvalues ======================== */
    printf("--- 26. Eigenvalues ---\n");

    double eig_data[] = {3, 1, 1, 2};
    MatrixD *m_eig = create_matrixd(2, 2, eig_data, 4);
    printf("Matrix A for eigenvalue computation:\n");
    print_matrix(m_eig);

    double *eigvals = eigenvalue_matrixd(m_eig);
    if (eigvals)
    {
        printf("Eigenvalues of A: %lf, %lf\n\n", eigvals[0], eigvals[1]);
        free(eigvals);
    }
    else
    {
        printf("Eigenvalue computation did not converge\n\n");
    }

    /* ======================== 27. Complex Matrix ======================== */
    printf("--- 27. Complex Matrix ---\n");

    Complex cdata[] = {
        create_complex(1, 1), create_complex(2, 0), create_complex(0, 3),
        create_complex(4, 0), create_complex(5, -1), create_complex(6, 2),
        create_complex(7, 3), create_complex(8, 4), create_complex(9, 5)
    };
    MatrixC *m_c = create_matrixc(3, 3, cdata, 9);
    printf("Complex matrix m_c:\n");
    print_matrix(m_c);

    MatrixC *m_ct = transpose_matrix(m_c);
    printf("transpose(m_c):\n");
    print_matrix(m_ct);

    Complex c_det = det_matrix(m_c);
    printf("det(m_c) = ");
    print_complex(c_det);
    printf("\n");

    MatrixC *m_cinv = inv_matrix(m_c);
    printf("inv(m_c):\n");
    print_matrix(m_cinv);

    // Verify: m_c * inv(m_c) = I
    MatrixC *m_c_check = mul_matrix(m_c, m_cinv);
    printf("m_c * inv(m_c) (should be identity):\n");
    print_matrix(m_c_check);

    /* ======================== 28. Matrix Power with Int Matrix ======================== */
    printf("--- 28. Int Matrix Power ---\n");

    int pow_data[] = {1, 1, 1, 0};
    MatrixI *m_fib = create_matrixi(2, 2, pow_data, 4);
    printf("Fibonacci matrix M:\n");
    print_matrix(m_fib);

    // M^5 = [[F6,F5],[F5,F4]] = [[8,5],[5,3]]
    MatrixD *m_fib5 = pow_matrix(m_fib, 5);
    printf("M^5 (Fibonacci F6=8, F5=5):\n");
    print_matrix(m_fib5);

    /* ======================== Cleanup ======================== */
    printf("--- Cleanup (freeing all matrices) ---\n");

    free_matrix(m_i);
    free_matrix(m_d);
    free_matrix(ident);
    free_matrix(zero);
    free_matrix(diag);
    free_matrix(eye_mat);
    free_matrix(rand_mat);
    free_matrix(m_copy);
    free_matrix(m_b);
    free_matrix(m_sum);
    free_matrix(m_diff);
    free_matrix(m_scaled);
    free_matrix(m_prod);
    free_matrix(m_mixed);
    free_matrix(m_t);
    free_matrix(m_singular);
    free_matrix(m_pow3);
    free_matrix(m_pow_neg);
    free_matrix(m_inv);
    free_matrix(verify);
    free_matrix(m_minor);
    free_matrix(m_cof);
    free_matrix(m_adj);
    free_matrix(adj_times_inv);
    free_matrix(col1);
    free_matrix(m_replaced);
    free_matrix(m_no_row1);
    free_matrix(m_no_col1);
    free_matrix(m_cat_h);
    free_matrix(m_cat_v);
    free_matrix(m_pd);
    free_matrix(m_c);
    free_matrix(m_ct);
    free_matrix(m_cinv);
    free_matrix(m_c_check);
    free_matrix(m_fib);
    free_matrix(m_fib5);

    printf("\nAll examples completed successfully!\n");
    return 0;
}
