#include "matrix/lu_matrix.h"
#include "matrix/determinant_matrix.h"
#include <math.h>

static const double EPS = 1e-6;

// ==================== 能否 LU 分解 ====================

bool can_lu_decompositioni(MatrixI *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        return false;
    }
    int n = m->rows;
    for (int k = 0; k < n; k++)
    {
        MatrixI sub;
        sub.rows = sub.cols = k + 1;
        sub.data = (int *)malloc(sizeof(int) * (k + 1) * (k + 1));
        if (sub.data == NULL)
            return false;
        for (int i = 0; i <= k; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                sub.data[i * (k + 1) + j] = m->data[i * n + j];
            }
        }
        int d = det_matrixi(&sub);
        free(sub.data);
        if (d == 0)
            return false;
    }
    return true;
}

bool can_lu_decompositionf(MatrixF *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        return false;
    }
    int n = m->rows;
    for (int k = 0; k < n; k++)
    {
        MatrixF sub;
        sub.rows = sub.cols = k + 1;
        sub.data = (float *)malloc(sizeof(float) * (k + 1) * (k + 1));
        if (sub.data == NULL)
            return false;
        for (int i = 0; i <= k; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                sub.data[i * (k + 1) + j] = m->data[i * n + j];
            }
        }
        float d = det_matrixf(&sub);
        free(sub.data);
        if (fabs(d) < EPS)
            return false;
    }
    return true;
}

bool can_lu_decompositiond(MatrixD *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        return false;
    }
    int n = m->rows;
    for (int k = 0; k < n; k++)
    {
        MatrixD sub;
        sub.rows = sub.cols = k + 1;
        sub.data = (double *)malloc(sizeof(double) * (k + 1) * (k + 1));
        if (sub.data == NULL)
            return false;
        for (int i = 0; i <= k; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                sub.data[i * (k + 1) + j] = m->data[i * n + j];
            }
        }
        double d = det_matrixd(&sub);
        free(sub.data);
        if (fabs(d) < EPS)
            return false;
    }
    return true;
}

bool can_lu_decompositionc(MatrixC *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        return false;
    }
    int n = m->rows;
    for (int k = 0; k < n; k++)
    {
        MatrixC sub;
        sub.rows = sub.cols = k + 1;
        sub.data = (Complex *)malloc(sizeof(Complex) * (k + 1) * (k + 1));
        if (sub.data == NULL)
            return false;
        for (int i = 0; i <= k; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                sub.data[i * (k + 1) + j] = m->data[i * n + j];
            }
        }
        Complex d = det_matrixc(&sub);
        free(sub.data);
        if (fabs(d.real) < EPS && fabs(d.imag) < EPS)
            return false;
    }
    return true;
}

// ==================== Doolittle 分解 ====================

void doolittle_matrixd(MatrixD *m, MatrixD **L, MatrixD **U)
{
    if (m == NULL || m->data == NULL || L == NULL || U == NULL || (*L) == NULL || (*U) == NULL)
    {
        return;
    }
    int n = m->rows;
    if (m->cols != n || (*L)->rows != n || (*L)->cols != n || (*U)->rows != n || (*U)->cols != n)
    {
        return;
    }

    // (*L) 对角为 1，下三角；U 上三角
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            (*L)->data[i * n + j] = (*U)->data[i * n + j] = 0.0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        (*L)->data[i * n + i] = 1.0;
    }

    for (int i = 0; i < n; i++)
    {
        // (*U) 的第 i 行
        for (int j = i; j < n; j++)
        {
            double sum = 0.0;
            for (int k = 0; k < i; k++)
            {
                sum += (*L)->data[i * n + k] * (*U)->data[k * n + j];
            }
            (*U)->data[i * n + j] = m->data[i * n + j] - sum;
        }
        // (*L) 的第 i 列
        for (int j = i + 1; j < n; j++)
        {
            double sum = 0.0;
            for (int k = 0; k < i; k++)
            {
                sum += (*L)->data[j * n + k] * (*U)->data[k * n + i];
            }
            (*L)->data[j * n + i] = (m->data[j * n + i] - sum) / (*U)->data[i * n + i];
        }
    }
}

// ==================== Cholesky 分解 ====================

void cholesky_matrixd(MatrixD *m, MatrixD **L)
{
    if (m == NULL || m->data == NULL || L == NULL || (*L) == NULL)
    {
        return;
    }
    int n = m->rows;
    if (m->cols != n || (*L)->rows != n || (*L)->cols != n)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            (*L)->data[i * n + j] = 0.0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            double sum = 0.0;
            for (int k = 0; k < j; k++)
            {
                sum += (*L)->data[i * n + k] * (*L)->data[j * n + k];
            }
            if (i == j)
            {
                (*L)->data[i * n + i] = sqrt(m->data[i * n + i] - sum);
            }
            else
            {
                (*L)->data[i * n + j] = (m->data[i * n + j] - sum) / (*L)->data[j * n + j];
            }
        }
    }
}

// ==================== LDU 分解 ====================

void ldu_matrixd(MatrixD *m, MatrixD **L, MatrixD **D, MatrixD **U)
{
    if (m == NULL || m->data == NULL || L == NULL || D == NULL || U == NULL || (*L) == NULL || (*D) == NULL || (*U) == NULL)
    {
        return;
    }
    int n = m->rows;
    if (m->cols != n || (*L)->rows != n || (*L)->cols != n || (*D)->rows != n || (*D)->cols != n || (*U)->rows != n || (*U)->cols != n)
    {
        return;
    }

    // 先做 Doolittle
    doolittle_matrixd(m, *L, *U);

    // (*D) = diag((*U))，U = (*D)^(-1) * (*U)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            (*D)->data[i * n + j] = 0.0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        (*D)->data[i * n + i] = (*U)->data[i * n + i];
        for (int j = i; j < n; j++)
        {
            (*U)->data[i * n + j] /= (*D)->data[i * n + i];
        }
    }
}

// ==================== Crout 分解 ====================

void crout_matrixd(MatrixD *m, MatrixD **L, MatrixD **U)
{
    if (m == NULL || m->data == NULL || L == NULL || U == NULL || (*L) == NULL || (*U) == NULL)
    {
        return;
    }
    int n = m->rows;
    if (m->cols != n || (*L)->rows != n || (*L)->cols != n || (*U)->rows != n || (*U)->cols != n)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            (*L)->data[i * n + j] = (*U)->data[i * n + j] = 0.0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        (*U)->data[i * n + i] = 1.0;
    }

    for (int j = 0; j < n; j++)
    {
        // (*L) 的第 j 列
        for (int i = j; i < n; i++)
        {
            double sum = 0.0;
            for (int k = 0; k < j; k++)
            {
                sum += (*L)->data[i * n + k] * (*U)->data[k * n + j];
            }
            (*L)->data[i * n + j] = m->data[i * n + j] - sum;
        }
        // (*U) 的第 j 行
        for (int i = j + 1; i < n; i++)
        {
            double sum = 0.0;
            for (int k = 0; k < j; k++)
            {
                sum += (*L)->data[j * n + k] * (*U)->data[k * n + i];
            }
            (*U)->data[j * n + i] = (m->data[j * n + i] - sum) / (*L)->data[j * n + j];
        }
    }
}
