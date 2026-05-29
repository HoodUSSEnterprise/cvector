#include "matrix/qr_matrix.h"

static const double EPS = 1e-6;

// ==================== Gram-Schmidt 正交化 ====================

void gram_schmidt_matrixd(MatrixD *m, MatrixD **Q)
{
    if (m == NULL || m->data == NULL || (*Q) == NULL)
    {
        return;
    }
    int n = m->rows, p = m->cols;
    if ((*Q)->rows != n || (*Q)->cols != p)
    {
        return;
    }

    // 提取每一列
    MatrixD *cols = (MatrixD *)malloc(sizeof(MatrixD) * p);
    for (int i = 0; i < p; i++)
    {
        cols[i].rows = n;
        cols[i].cols = 1;
        cols[i].data = (double *)malloc(sizeof(double) * n);
        for (int r = 0; r < n; r++)
        {
            cols[i].data[r] = m->data[r * p + i];
        }
    }

    for (int i = 0; i < p; i++)
    {
        // 减去已在前面向量上的投影
        for (int j = 0; j < i; j++)
        {
            // dot(cols[i], cols[j])
            double dot_ij = 0.0, dot_jj = 0.0;
            for (int r = 0; r < n; r++)
            {
                dot_ij += cols[i].data[r] * cols[j].data[r];
                dot_jj += cols[j].data[r] * cols[j].data[r];
            }
            double factor = dot_ij / dot_jj;
            for (int r = 0; r < n; r++)
            {
                cols[i].data[r] -= factor * cols[j].data[r];
            }
        }

        // 归一化
        double norm = 0.0;
        for (int r = 0; r < n; r++)
        {
            norm += cols[i].data[r] * cols[i].data[r];
        }
        norm = sqrt(norm);
        if (norm > EPS)
        {
            for (int r = 0; r < n; r++)
            {
                cols[i].data[r] /= norm;
            }
        }
    }

    // 写入 (*Q)
    for (int i = 0; i < p; i++)
    {
        for (int r = 0; r < n; r++)
        {
            (*Q)->data[r * p + i] = cols[i].data[r];
        }
    }

    for (int i = 0; i < p; i++)
    {
        free(cols[i].data);
    }
    free(cols);
}

void gram_schmidt_matrixc(MatrixC *m, MatrixC **Q)
{
    if (m == NULL || m->data == NULL || (*Q) == NULL)
    {
        return;
    }
    int n = m->rows, p = m->cols;
    if ((*Q)->rows != n || (*Q)->cols != p)
    {
        return;
    }

    // 提取每一列
    MatrixC *cols = (MatrixC *)malloc(sizeof(MatrixC) * p);
    for (int i = 0; i < p; i++)
    {
        cols[i].rows = n;
        cols[i].cols = 1;
        cols[i].data = (Complex *)malloc(sizeof(Complex) * n);
        for (int r = 0; r < n; r++)
        {
            cols[i].data[r] = m->data[r * p + i];
        }
    }

    for (int i = 0; i < p; i++)
    {
        // 减去已在前面向量上的投影
        for (int j = 0; j < i; j++)
        {
            // dot(cols[i], cols[j]) 注意复数内积需要用 cols[j] 的共轭
            Complex dot_ij = {0.0, 0.0};
            double dot_jj = 0.0;  // 模平方，实数
            
            for (int r = 0; r < n; r++)
            {
                // dot_ij += cols[i][r] * conj(cols[j][r])
                Complex temp = mul_complex(cols[i].data[r], (Complex){cols[j].data[r].real, -cols[j].data[r].imag});
                dot_ij = add_complex(dot_ij, temp);
                
                // dot_jj += |cols[j][r]|^2
                dot_jj += complex_norm2(cols[j].data[r]);
            }
            
            // factor = dot_ij / dot_jj (复数)
            Complex factor = (Complex){dot_ij.real / dot_jj, dot_ij.imag / dot_jj};
            
            for (int r = 0; r < n; r++)
            {
                // cols[i] -= factor * cols[j]
                Complex temp = mul_complex(factor, cols[j].data[r]);
                cols[i].data[r] = sub_complex(cols[i].data[r], temp);
            }
        }

        // 归一化
        double norm = 0.0;
        for (int r = 0; r < n; r++)
        {
            norm += complex_norm2(cols[i].data[r]);
        }
        norm = sqrt(norm);
        
        if (norm > EPS)
        {
            for (int r = 0; r < n; r++)
            {
                cols[i].data[r] = (Complex){cols[i].data[r].real / norm, cols[i].data[r].imag / norm};
            }
        }
    }

    // 写入 (*Q)
    for (int i = 0; i < p; i++)
    {
        for (int r = 0; r < n; r++)
        {
            (*Q)->data[r * p + i] = cols[i].data[r];
        }
    }

    for (int i = 0; i < p; i++)
    {
        free(cols[i].data);
    }
    free(cols);
}

// ==================== QR 分解 (Gram-Schmidt) ====================

void qr_gs_matrixd(MatrixD *m, MatrixD **Q, MatrixD **R)
{
    if (m == NULL || m->data == NULL || Q == NULL || R == NULL || (*Q) == NULL || (*R) == NULL)
    {
        return;
    }
    int n = m->rows, p = m->cols;
    if ((*Q)->rows != n || (*Q)->cols != p || (*R)->rows != p || (*R)->cols != p)
    {
        return;
    }

    gram_schmidt_matrixd(m, (*Q));

    // (*R) = (*Q)^T * m
    MatrixD *Qt = transpose_matrixd((*Q));
    for (int i = 0; i < p; i++)
        for (int j = 0; j < p; j++)
        {
            double sum = 0.0;
            for (int k = 0; k < n; k++)
            {
                sum += Qt->data[i * n + k] * m->data[k * p + j];
            }
            (*R)->data[i * p + j] = sum;
        }
    free(Qt->data);
    free(Qt);
}

// ==================== QR 分解 (Householder) ====================

void qr_householder_matrixd(MatrixD *m, MatrixD **Q, MatrixD **R)
{
    if (m == NULL || m->data == NULL || Q == NULL || R == NULL || (*Q) == NULL || (*R) == NULL)
    {
        return;
    }
    int n = m->rows, p = m->cols;
    if ((*Q)->rows != n || (*Q)->cols != p || (*R)->rows != p || (*R)->cols != p)
    {
        return;
    }

    // 复制一份到 (*R) 的临时空间
    MatrixD A;
    A.rows = n;
    A.cols = p;
    A.data = (double *)malloc(sizeof(double) * n * p);
    for (int i = 0; i < n * p; i++)
    {
        A.data[i] = m->data[i];
    }

    // (*Q) 初始化为单位矩阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            (*Q)->data[i * n + j] = (i == j) ? 1.0 : 0.0;
        }
    }

    for (int k = 0; k < p && k < n - 1; k++)
    {
        // 计算 Householder 向量 u
        int len = n - k;
        double *x = (double *)malloc(sizeof(double) * len);
        for (int i = 0; i < len; i++)
            x[i] = A.data[(k + i) * p + k];

        double norm_x = 0.0;
        for (int i = 0; i < len; i++)
        {
            norm_x += x[i] * x[i];
        }
        norm_x = sqrt(norm_x);

        if (norm_x < EPS)
        {
            free(x);
            continue;
        }

        double alpha = (x[0] >= 0) ? -norm_x : norm_x;
        double *u = (double *)malloc(sizeof(double) * len);
        for (int i = 0; i < len; i++)
        {
            u[i] = (i == 0) ? x[0] - alpha : x[i];
        }

        double u_norm2 = 0.0;
        for (int i = 0; i < len; i++)
        {
            u_norm2 += u[i] * u[i];
        }

        if (u_norm2 < EPS)
        {
            free(x);
            free(u);
            continue;
        }

        // H_k = I - 2*u*u^T / u_norm2
        // 先对子矩阵应用 H_k
        // A_{k:,k:} = H_k * A_{k:,k:}
        for (int j = k; j < p; j++)
        {
            double dot = 0.0;
            for (int i = 0; i < len; i++)
            {
                dot += u[i] * A.data[(k + i) * p + j];
            }
            double factor = 2.0 * dot / u_norm2;
            for (int i = 0; i < len; i++)
            {
                A.data[(k + i) * p + j] -= factor * u[i];
            }
        }

        // (*Q) = (*Q) * H_k
        for (int i = 0; i < n; i++)
        {
            double dot = 0.0;
            for (int j = 0; j < len; j++)
            {
                dot += u[j] * (*Q)->data[i * n + (k + j)];
            }
            double factor = 2.0 * dot / u_norm2;
            for (int j = 0; j < len; j++)
            {
                (*Q)->data[i * n + (k + j)] -= factor * u[j];
            }
        }

        free(x);
        free(u);
    }

    // 复制 A 的上三角部分到 (*R)
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < p; j++)
        {
            (*R)->data[i * p + j] = (i <= j) ? A.data[i * p + j] : 0.0;
        }
    }

    free(A.data);
}

void qr_householder_matrixc(MatrixC *m, MatrixC **Q, MatrixC **R)
{
    if (m == NULL || m->data == NULL || Q == NULL || R == NULL || (*Q) == NULL || (*R) == NULL)
    {
        return;
    }
    int n = m->rows, p = m->cols;
    if ((*Q)->rows != n || (*Q)->cols != n || (*R)->rows != n || (*R)->cols != p)
    {
        return;  // Q 应为 n×n，R 应为 n×p
    }
    
    // 复制一份到临时矩阵 A
    MatrixC A;
    A.rows = n;
    A.cols = p;
    A.data = (Complex *)malloc(sizeof(Complex) * n * p);
    for (int i = 0; i < n * p; i++)
    {
        A.data[i] = m->data[i];
    }
    
    // (*Q) 初始化为单位矩阵 (n×n)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            (*Q)->data[i * n + j].real = (i == j) ? 1.0 : 0.0;
            (*Q)->data[i * n + j].imag = 0.0;
        }
    }
    
    for (int k = 0; k < p && k < n - 1; k++)
    {
        int len = n - k;
        
        // 提取列向量 x
        Complex *x = (Complex *)malloc(sizeof(Complex) * len);
        for (int i = 0; i < len; i++)
        {
            x[i] = A.data[(k + i) * p + k];
        }
        
        // 计算 norm_x = ||x||
        double norm_x = 0.0;
        for (int i = 0; i < len; i++)
        {
            norm_x += complex_norm2(x[i]);
        }
        norm_x = sqrt(norm_x);
        
        if (norm_x < EPS)
        {
            free(x);
            continue;
        }
        
        // 计算 alpha = - (norm_x / |x[0]|) * x[0]
        double abs_x0 = complex_abs(x[0]);
        Complex alpha;
        if (abs_x0 < EPS) {
            alpha.real = -norm_x;
            alpha.imag = 0.0;
        } else {
            double factor = -norm_x / abs_x0;
            alpha.real = factor * x[0].real;
            alpha.imag = factor * x[0].imag;
        }
        
        // 计算 Householder 向量 u
        Complex *u = (Complex *)malloc(sizeof(Complex) * len);
        for (int i = 0; i < len; i++)
        {
            if (i == 0) {
                u[i] = sub_complex(x[0], alpha);
            } else {
                u[i] = x[i];
            }
        }
        
        // 计算 u_norm2 = u^H * u (实数)
        double u_norm2 = 0.0;
        for (int i = 0; i < len; i++)
        {
            u_norm2 += complex_norm2(u[i]);
        }
        
        if (u_norm2 < EPS)
        {
            free(x);
            free(u);
            continue;
        }
        
        // 更新 A = H * A
        // H = I - (2 / (u^H u)) * u * u^H
        for (int j = k; j < p; j++)
        {
            // 计算 dot = u^H * A(:,j)
            Complex dot = {0.0, 0.0};
            for (int i = 0; i < len; i++)
            {
                Complex temp = mul_complex((Complex){u[i].real, -u[i].imag}, A.data[(k + i) * p + j]);
                dot = add_complex(dot, temp);
            }
            
            // factor = 2 * dot / u_norm2
            Complex factor = (Complex){dot.real * 2.0, dot.imag * 2.0};
            factor = (Complex){factor.real / u_norm2, factor.imag / u_norm2};
            
            // A = A - factor * u
            for (int i = 0; i < len; i++)
            {
                Complex temp = mul_complex(factor, u[i]);
                A.data[(k + i) * p + j] = sub_complex(A.data[(k + i) * p + j], temp);
            }
        }
        
        // 更新 Q = Q * H
        // 先计算 t = Q * u (n 维向量)
        Complex *t = (Complex *)malloc(sizeof(Complex) * n);
        for (int i = 0; i < n; i++)
        {
            t[i].real = 0.0;
            t[i].imag = 0.0;
            for (int j = 0; j < len; j++)
            {
                Complex temp = mul_complex((*Q)->data[i * n + (k + j)], u[j]);
                t[i] = add_complex(t[i], temp);
            }
        }
        
        // Q = Q - (2/u_norm2) * t * u^H
        for (int i = 0; i < n; i++)
        {
            Complex factor = (Complex){t[i].real * 2.0 / u_norm2, t[i].imag * 2.0 / u_norm2};
            for (int j = 0; j < len; j++)
            {
                Complex temp = mul_complex(factor, (Complex){u[j].real, -u[j].imag});
                (*Q)->data[i * n + (k + j)] = sub_complex((*Q)->data[i * n + (k + j)], temp);
            }
        }
        
        free(t);
        free(x);
        free(u);
    }
    
    // 复制 A 的上三角部分到 (*R)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            if (i <= j && i < p)
            {
                (*R)->data[i * p + j] = A.data[i * p + j];
            }
            else
            {
                (*R)->data[i * p + j].real = 0.0;
                (*R)->data[i * p + j].imag = 0.0;
            }
        }
    }
    
    free(A.data);
}

// ==================== QR 迭代收敛判断 ====================

bool qr_iter_stop_matrixd(MatrixD *m)
{
    if (m == NULL || m->data == NULL)
    {
        return true;
    }
    int n = m->rows;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < m->cols; j++)
        {
            if (fabs(m->data[j * m->cols + i]) >= EPS)
            {
                return false;
            }
        }
    }
    return true;
}

bool qr_iter_stop_matrixc(MatrixC *m)
{
    if (m == NULL || m->data == NULL)
    {
        return true;
    }
    int n = m->rows;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < m->cols; j++)
        {
            if (is_equal_complex(m->data[j * m->cols + i], (Complex){0 ,0}))
            {
                return false;
            }
        }
    }
    return true;
}
