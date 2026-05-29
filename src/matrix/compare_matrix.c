#include "matrix/compare_matrix.h"
#include <math.h>

static const double EPS = 1e-6;

// ==================== 同类型比较 ====================

bool is_equal_matrixi_i(MatrixI *m1, MatrixI *m2)
{
    if (m1 == NULL || m2 == NULL)
    {
        return false;
    }
    if (m1->rows != m2->rows || m1->cols != m2->cols)
    {
        return false;
    }
    if (m1->data == NULL || m2->data == NULL)
    {
        return false;
    }
    for (int i = 0; i < m1->rows * m1->cols; i++)
    {
        if (m1->data[i] != m2->data[i])
        {
            return false;
        }
    }
    return true;
}

bool is_equal_matrixf_f(MatrixF *m1, MatrixF *m2)
{
    if (m1 == NULL || m2 == NULL)
    {
        return false;
    }
    if (m1->rows != m2->rows || m1->cols != m2->cols)
    {
        return false;
    }
    if (m1->data == NULL || m2->data == NULL)
    {
        return false;
    }
    for (int i = 0; i < m1->rows * m1->cols; i++)
    {
        if (fabs(m1->data[i] - m2->data[i]) > EPS)
        {
            return false;
        }
    }
    return true;
}

bool is_equal_matrixd_d(MatrixD *m1, MatrixD *m2)
{
    if (m1 == NULL || m2 == NULL)
    {
        return false;
    }
    if (m1->rows != m2->rows || m1->cols != m2->cols)
    {
        return false;
    }
    if (m1->data == NULL || m2->data == NULL)
    {
        return false;
    }
    for (int i = 0; i < m1->rows * m1->cols; i++)
    {
        if (fabs(m1->data[i] - m2->data[i]) > EPS)
        {
            return false;
        }
    }
    return true;
}

bool is_equal_matrixc_c(MatrixC *m1, MatrixC *m2)
{
    if (m1 == NULL || m2 == NULL)
    {
        return false;
    }
    if (m1->rows != m2->rows || m1->cols != m2->cols)
    {
        return false;
    }
    if (m1->data == NULL || m2->data == NULL)
    {
        return false;
    }
    for (int i = 0; i < m1->rows * m1->cols; i++)
    {
        if (!is_equal_complex(m1->data[i], m2->data[i]))
        {
            return false;
        }
    }
    return true;
}

// ==================== 跨类型比较辅助 ====================

bool is_equal_matrixi_f(MatrixI *m1, MatrixF *m2)
{
    if (m1 == NULL || m2 == NULL || m1->rows != m2->rows || m1->cols != m2->cols)
    {
        return false;
    }
    for (int i = 0; i < m1->rows * m1->cols; i++)
    {
        if (fabs(m1->data[i] - m2->data[i]) > EPS)
        {
            return false;
        }
    }
    return true;
}

bool is_equal_matrixi_d(MatrixI *m1, MatrixD *m2)
{
    if (m1 == NULL || m2 == NULL || m1->rows != m2->rows || m1->cols != m2->cols)
    {
        return false;
    }
    if (m1->data == NULL || m2->data == NULL)
    {
        return false;
    }
    for (int i = 0; i < m1->rows * m1->cols; i++)
    {
        if (fabs((double)m1->data[i] - m2->data[i]) > EPS)
        {
            return false;
        }
    }
    return true;
}

bool is_equal_matrixi_c(MatrixI *m1, MatrixC *m2)
{
    return false;
}

bool is_equal_matrixf_i(MatrixF *m1, MatrixI *m2)
{
    return is_equal_matrixi_f(m2, m1);
}

bool is_equal_matrixf_d(MatrixF *m1, MatrixD *m2)
{
    if (m1 == NULL || m2 == NULL || m1->rows != m2->rows || m1->cols != m2->cols)
    {
        return false;
    }
    if (m1->data == NULL || m2->data == NULL)
    {
        return false;
    }
    for (int i = 0; i < m1->rows * m1->cols; i++)
    {
        if (fabs((double)m1->data[i] - m2->data[i]) > EPS)
        {
            return false;
        }
    }
    return true;
}

bool is_equal_matrixf_c(MatrixF *m1, MatrixC *m2)
{
    return false;
}

bool is_equal_matrixd_i(MatrixD *m1, MatrixI *m2)
{
    return is_equal_matrixi_d(m2, m1);
}
bool is_equal_matrixd_f(MatrixD *m1, MatrixF *m2)
{
    return is_equal_matrixf_d(m2, m1);
}

bool is_equal_matrixd_c(MatrixD *m1, MatrixC *m2)
{
    return false;
}

bool is_equal_matrixc_i(MatrixC *m1, MatrixI *m2)
{
    return false;
}
bool is_equal_matrixc_f(MatrixC *m1, MatrixF *m2)
{
    return false;
}
bool is_equal_matrixc_d(MatrixC *m1, MatrixD *m2)
{
    return false;
}
