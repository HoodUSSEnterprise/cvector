#include "matrix/eigen_matrix.h"

static const double EPS = 1e-6;

// ==================== 特征值（QR 迭代法） ====================

double *eigenvalue_matrixd(MatrixD *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        printf("Matrix must be square!\n");
        return NULL;
    }

    int n = m->rows;

    // 复制矩阵
    MatrixD Ak;
    Ak.rows = n;
    Ak.cols = n;
    Ak.data = (double *)malloc(sizeof(double) * n * n);
    for (int i = 0; i < n * n; i++)
    {
        Ak.data[i] = m->data[i];
    }

    MatrixD Q, R;
    Q.rows = n;
    Q.cols = n;
    Q.data = (double *)malloc(sizeof(double) * n * n);
    R.rows = n;
    R.cols = n;
    R.data = (double *)malloc(sizeof(double) * n * n);

    if (Q.data == NULL || R.data == NULL)
    {
        free(Ak.data);
        free(Q.data);
        free(R.data);
        printf("No memory\n");
        return NULL;
    }

    int max_iter = 1000;
    for (int iter = 0; iter < max_iter; iter++)
    {
        if (qr_iter_stop_matrixd(&Ak))
        {
            break;
        }

        // QR 分解
        qr_householder_matrixd(&Ak, &Q, &R);

        // Ak = R * Q
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                double sum = 0.0;
                for (int k = 0; k < n; k++)
                {
                    sum += R.data[i * n + k] * Q.data[k * n + j];
                }
                Ak.data[i * n + j] = sum;
            }
    }

    // 提取对角线作为特征值
    double *ev = (double *)malloc(sizeof(double) * n);
    if (ev == NULL)
    {
        printf("No memory\n");
        free(Ak.data);
        free(Q.data);
        free(R.data);
        return NULL;
    }
    for (int i = 0; i < n; i++)
    {
        ev[i] = Ak.data[i * n + i];
    }

    free(Ak.data);
    free(Q.data);
    free(R.data);
    return ev;
}

Complex *eigenvalue_matrixc(MatrixC *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        printf("Matrix must be square!\n");
        return NULL;
    }

    int n = m->rows;

    // 复制矩阵
    MatrixC Ak;
    Ak.rows = n;
    Ak.cols = n;
    Ak.data = (Complex *)malloc(sizeof(Complex) * n * n);
    for (int i = 0; i < n * n; i++)
    {
        Ak.data[i] = m->data[i];
    }

    MatrixC Q, R;
    Q.rows = n;
    Q.cols = n;
    Q.data = (Complex *)malloc(sizeof(Complex) * n * n);
    R.rows = n;
    R.cols = n;
    R.data = (Complex *)malloc(sizeof(Complex) * n * n);

    if (Q.data == NULL || R.data == NULL)
    {
        free(Ak.data);
        free(Q.data);
        free(R.data);
        printf("No memory\n");
        return NULL;
    }

    int max_iter = 1000;
    for (int iter = 0; iter < max_iter; iter++)
    {
        if (qr_iter_stop_matrixc(&Ak))
        {
            break;
        }

        // QR 分解
        qr_householder_matrixc(&Ak, &Q, &R);

        // Ak = R * Q
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                Complex sum = {0.0, 0.0};
                for (int k = 0; k < n; k++)
                {
                    // sum += R[i][k] * Q[k][j]
                    Complex temp = mul_complex(R.data[i * n + k], Q.data[k * n + j]);
                    sum = add_complex(sum, temp);
                }
                Ak.data[i * n + j] = sum;
            }
    }

    // 提取对角线作为特征值
    Complex *ev = (Complex *)malloc(sizeof(Complex) * n);
    if (ev == NULL)
    {
        printf("No memory\n");
        free(Ak.data);
        free(Q.data);
        free(R.data);
        return NULL;
    }
    for (int i = 0; i < n; i++)
    {
        ev[i] = Ak.data[i * n + i];
    }

    free(Ak.data);
    free(Q.data);
    free(R.data);
    return ev;
}

// ==================== 特征向量（通过解齐次线性方程组） ====================

// 简单的 Gaussian elimination 求解 (A - λI)x = 0
// 返回 n×n 矩阵，每列为一个特征向量
MatrixD *eigenvector_matrixd(MatrixD *m, const double *eigenvalues, int num_ev)
{
    if (m == NULL || m->data == NULL || eigenvalues == NULL || m->rows != m->cols)
    {
        printf("Invalid param!\n");
        return NULL;
    }

    int n = m->rows;

    MatrixD *result = (MatrixD *)malloc(sizeof(MatrixD));
    if (result == NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    result->rows = n;
    result->cols = num_ev;
    result->data = (double *)calloc(n * num_ev, sizeof(double));
    if (result->data == NULL)
    {
        printf("No memory\n");
        free(result);
        return NULL;
    }

    for (int ei = 0; ei < num_ev; ei++)
    {
        double lambda = eigenvalues[ei];

        // 检查是否与前一个特征值相同（重复特征值只算一次的方法简化处理）
        if (ei > 0 && fabs(lambda - eigenvalues[ei - 1]) < EPS)
        {
            // 简单跳过重复
            continue;
        }

        // 构建增广矩阵 (A - λI | 0)
        double *aug = (double *)malloc(sizeof(double) * n * (n + 1));
        if (aug == NULL)
            continue;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                aug[i * (n + 1) + j] = m->data[i * n + j] - (i == j ? lambda : 0.0);

        // 最后一列全 0
        for (int i = 0; i < n; i++)
            aug[i * (n + 1) + n] = 0.0;

        // 高斯消元
        for (int col = 0, row = 0; col < n && row < n; col++)
        {
            int pivot = row;
            while (pivot < n && fabs(aug[pivot * (n + 1) + col]) < EPS)
                pivot++;
            if (pivot == n)
                continue;

            // 交换行
            if (pivot != row)
                for (int j = col; j <= n; j++)
                {
                    double temp = aug[row * (n + 1) + j];
                    aug[row * (n + 1) + j] = aug[pivot * (n + 1) + j];
                    aug[pivot * (n + 1) + j] = temp;
                }

            // 归一化主元行
            double piv_val = aug[row * (n + 1) + col];
            for (int j = col; j <= n; j++)
                aug[row * (n + 1) + j] /= piv_val;

            // 消去
            for (int i = 0; i < n; i++)
            {
                if (i == row)
                    continue;
                double factor = aug[i * (n + 1) + col];
                for (int j = col; j <= n; j++)
                    aug[i * (n + 1) + j] -= factor * aug[row * (n + 1) + j];
            }
            row++;
        }

        // 找自由变量，取第一个自由变量为 1
        double *vec = (double *)calloc(n, sizeof(double));
        int found_free = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int pivot_col = -1;
            for (int j = 0; j < n; j++)
                if (fabs(aug[i * (n + 1) + j]) >= EPS)
                {
                    pivot_col = j;
                    break;
                }

            if (pivot_col == -1)
                continue;

            // 检查是否为自由变量
            int is_free = 1;
            for (int j = 0; j < n; j++)
                if (j != pivot_col && fabs(aug[i * (n + 1) + j]) >= EPS)
                {
                    is_free = 0;
                    break;
                }

            if (is_free && !found_free)
            {
                vec[pivot_col] = 1.0;
                found_free = 1;
                // 消去该变量在其他行的值
                for (int r = 0; r < i; r++)
                    if (fabs(aug[r * (n + 1) + pivot_col]) >= EPS)
                        aug[r * (n + 1) + n] -= aug[r * (n + 1) + pivot_col];
            }
            else
            {
                // 回代
                double val = aug[i * (n + 1) + n];
                for (int j = pivot_col + 1; j < n; j++)
                    val -= aug[i * (n + 1) + j] * vec[j];
                if (fabs(aug[i * (n + 1) + pivot_col]) > EPS)
                    vec[pivot_col] = val / aug[i * (n + 1) + pivot_col];
            }
        }

        // 归一化特征向量
        double norm = 0.0;
        for (int i = 0; i < n; i++)
            norm += vec[i] * vec[i];
        norm = sqrt(norm);
        if (norm > EPS)
            for (int i = 0; i < n; i++)
                vec[i] /= norm;

        for (int i = 0; i < n; i++)
            result->data[i * num_ev + ei] = vec[i];

        free(vec);
        free(aug);
    }

    return result;
}
