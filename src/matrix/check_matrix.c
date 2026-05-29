#include "matrix/check_matrix.h"
#include <math.h>

static const double EPS = 1e-6;

// ==================== 单位矩阵判断 ====================

bool is_identity_matrixi(MatrixI *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        return false;
    }
    for (int i = 0; i < m->rows; i++)
        for (int j = 0; j < m->cols; j++)
        {
            if (i == j)
            {
                if (m->data[i * m->cols + j] != 1)
                {
                    return false;
                }
            }
            else
            {
                if (m->data[i * m->cols + j] != 0)
                {
                    return false;
                }
            }
        }
    return true;
}

bool is_identity_matrixf(MatrixF *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        return false;
    }
    for (int i = 0; i < m->rows; i++)
        for (int j = 0; j < m->cols; j++)
        {
            double v = m->data[i * m->cols + j];
            if (i == j)
            {
                if (fabs(v - 1.0) > EPS)
                {
                    return false;
                }
            }
            else
            {
                if (fabs(v) > EPS)
                {
                    return false;
                }
            }
        }
    return true;
}

bool is_identity_matrixd(MatrixD *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        return false;
    }
    for (int i = 0; i < m->rows; i++)
        for (int j = 0; j < m->cols; j++)
        {
            double v = m->data[i * m->cols + j];
            if (i == j)
            {
                if (fabs(v - 1.0) > EPS)
                {
                    return false;
                }
            }
            else
            {
                if (fabs(v) > EPS)
                {
                    return false;
                }
            }
        }
    return true;
}

bool is_identity_matrixc(MatrixC *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        return false;
    }
    for (int i = 0; i < m->rows; i++)
        for (int j = 0; j < m->cols; j++)
        {
            Complex v = m->data[i * m->cols + j];
            if (i == j)
            {
                if (fabs(v.real - 1.0) > EPS || fabs(v.imag) > EPS)
                {
                    return false;
                }
            }
            else
            {
                if (fabs(v.real) > EPS || fabs(v.imag) > EPS)
                {
                    return false;
                }
            }
        }
    return true;
}

// ==================== 可逆判断 ====================

bool is_inv_matrixi(MatrixI *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        return false;
    }
    return det_matrixi(m) != 0;
}

bool is_inv_matrixf(MatrixF *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        return false;
    }
    return fabs(det_matrixf(m)) > EPS;
}

bool is_inv_matrixd(MatrixD *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        return false;
    }
    return fabs(det_matrixd(m)) > EPS;
}

bool is_inv_matrixc(MatrixC *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        return false;
    }
    Complex d = det_matrixc(m);
    return fabs(d.real) > EPS || fabs(d.imag) > EPS;
}

// ==================== 正交判断 ====================

bool is_orth_matrixi(MatrixI *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        return false;
    }
    MatrixI *t = transpose_matrixi(m);
    MatrixI *p = mul_matrixi_i(m, t);
    bool ok = is_identity_matrixi(p);
    free(p->data);
    free(p);
    free(t->data);
    free(t);
    return ok;
}

bool is_orth_matrixf(MatrixF *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        return false;
    }
    MatrixF *t = transpose_matrixf(m);
    MatrixF *p = mul_matrixf_f(m, t);
    bool ok = is_identity_matrixf(p);
    free(p->data);
    free(p);
    free(t->data);
    free(t);
    return ok;
}

bool is_orth_matrixd(MatrixD *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        return false;
    }
    MatrixD *t = transpose_matrixd(m);
    MatrixD *p = mul_matrixd_d(m, t);
    bool ok = is_identity_matrixd(p);
    free(p->data);
    free(p);
    free(t->data);
    free(t);
    return ok;
}

bool is_orth_matrixc(MatrixC *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        return false;
    }
    MatrixC *t = transpose_matrixc(m);
    MatrixC *p = mul_matrixc_c(m, t);
    bool ok = is_identity_matrixc(p);
    free(p->data);
    free(p);
    free(t->data);
    free(t);
    return ok;
}

// ==================== 正定判断 ====================

// 检查所有顺序主子式 > 0
static bool is_positive_matrix_generic_double(MatrixD *m)
{
    int n = m->rows;
    for (int k = 0; k < n; k++)
    {
        // 取左上角 k+1 阶子矩阵
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
        if (d <= EPS)
            return false;
    }
    return true;
}

bool is_positive_matrixi(MatrixI *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        return false;
    }
    MatrixD *temp = (MatrixD *)malloc(sizeof(MatrixD));
    if (temp == NULL)
    {
        return false;
    }
    temp->rows = temp->cols = m->rows;
    temp->data = (double *)malloc(sizeof(double) * m->rows * m->cols);
    if (temp->data == NULL)
    {
        free(temp);
        return false;
    }
    for (int i = 0; i < m->rows * m->cols; i++)
    {
        temp->data[i] = (double)m->data[i];
    }
    bool ok = is_positive_matrix_generic_double(temp);
    free(temp->data);
    free(temp);
    return ok;
}

bool is_positive_matrixf(MatrixF *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        return false;
    }
    MatrixD *temp = (MatrixD *)malloc(sizeof(MatrixD));
    if (temp == NULL)
    {
        return false;
    }
    temp->rows = temp->cols = m->rows;
    temp->data = (double *)malloc(sizeof(double) * m->rows * m->cols);
    if (temp->data == NULL)
    {
        free(temp);
        return false;
    }
    for (int i = 0; i < m->rows * m->cols; i++)
    {
        temp->data[i] = (double)m->data[i];
    }
    bool ok = is_positive_matrix_generic_double(temp);
    free(temp->data);
    free(temp);
    return ok;
}

bool is_positive_matrixd(MatrixD *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        return false;
    }
    return is_positive_matrix_generic_double(m);
}

bool is_positive_matrixc(MatrixC *m)
{
    if (m == NULL || m->data == NULL || m->rows != m->cols)
    {
        return false;
    }
    // Complex 正定：检查实部主子式
    MatrixD *temp = (MatrixD *)malloc(sizeof(MatrixD));
    if (temp == NULL)
    {
        return false;
    }
    temp->rows = temp->cols = m->rows;
    temp->data = (double *)malloc(sizeof(double) * m->rows * m->cols);
    if (temp->data == NULL)
    {
        free(temp);
        return false;
    }
    for (int i = 0; i < m->rows * m->cols; i++)
        temp->data[i] = m->data[i].real;
    bool ok = is_positive_matrix_generic_double(temp);
    free(temp->data);
    free(temp);
    return ok;
}
