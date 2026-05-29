#include "matrix/rank_trace_matrix.h"
#include <math.h>
#include <float.h>
#include <limits.h>

#define TRACE_NONEI INT_MIN
#define TRACE_NONEF (float)INT_MIN
#define TRACE_NONED (double)INT_MIN
#define TRACE_NONEC ((Complex){INT_MIN, INT_MIN})

// ==================== 秩（高斯消元，行阶梯形） ====================

static int rank_matrix_generic(int n, int m, double *data)
{
    // 用 double 做高斯消元
    double *cp = (double *)malloc(sizeof(double) * n * m);
    if (cp == NULL)
    {
        printf("No memory\n");
        return 0;
    }
    for (int i = 0; i < n * m; i++)
    {
        cp[i] = data[i];
    }

    for (int col = 0, row = 0; col < m && row < n; col++)
    {
        // 找主元
        int pivot = row;
        while (pivot < n && fabs(cp[pivot * m + col]) < 1e-6)
        {
            pivot++;
        }
        if (pivot == n)
        {
            continue;
        }

        // 交换行
        if (pivot != row)
        {
            for (int j = col; j < m; j++)
            {
                double temp = cp[row * m + j];
                cp[row * m + j] = cp[pivot * m + j];
                cp[pivot * m + j] = temp;
            }
        }

        // 消去下方行
        for (int i = row + 1; i < n; i++)
        {
            double factor = cp[i * m + col] / cp[row * m + col];
            for (int j = col; j < m; j++)
            {
                cp[i * m + j] -= factor * cp[row * m + j];
            }
        }
        row++;
    }

    // 统计非零行
    int rank = 0;
    for (int i = 0; i < n; i++)
    {
        int is_zero_row = 1;
        for (int j = 0; j < m; j++)
        {
            if (fabs(cp[i * m + j]) >= 1e-6)
            {
                is_zero_row = 0;
                break;
            }
        }
        if (!is_zero_row)
        {
            rank++;
        }
    }
    free(cp);
    return rank;
}

static int rank_matrix_generic_complex(int n, int m, Complex *data)
{
    Complex *cp = (Complex *)malloc(sizeof(Complex) * n * m);
    if (cp == NULL)
    {
        printf("No memory\n");
        return 0;
    }
    for (int i = 0; i < n * m; i++)
    {
        cp[i] = data[i];
    }

    for (int col = 0, row = 0; col < m && row < n; col++)
    {
        // 找主元
        int pivot = row;
        while (pivot < n && is_equal_complex(cp[pivot * m + col], (Complex){0, 0}))
        {
            pivot++;
        }
        if (pivot == n)
        {
            continue;
        }

        // 交换行
        if (pivot != row)
        {
            for (int j = col; j < m; j++)
            {
                Complex temp = cp[row * m + j];
                cp[row * m + j] = cp[pivot * m + j];
                cp[pivot * m + j] = temp;
            }
        }

        // 消去下方行
        for (int i = row + 1; i < n; i++)
        {
            Complex factor = div_complex(cp[i * m + col], cp[row * m + col]);
            for (int j = col; j < m; j++)
            {
                cp[i * m + j] = sub_complex(cp[i * m + j], mul_complex(factor, cp[row * m + j]));
            }
        }
        row++;
    }

    // 统计非零行
    int rank = 0;
    for (int i = 0; i < n; i++)
    {
        int is_zero_row = 1;
        for (int j = 0; j < m; j++)
        {
            if (is_equal_complex(cp[i * m + j], (Complex){0, 0}) == false)
            {
                is_zero_row = 0;
                break;
            }
        }
        if (!is_zero_row)
        {
            rank++;
        }
    }
    free(cp);
    return rank;
}

int rank_matrixi(MatrixI *m)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return 0;
    }
    double *temp = (double *)malloc(sizeof(double) * m->rows * m->cols);
    if (temp == NULL)
    {
        printf("No memory\n");
        return 0;
    }
    for (int i = 0; i < m->rows * m->cols; i++)
    {
        temp[i] = (double)m->data[i];
    }
    int r = rank_matrix_generic(m->rows, m->cols, temp);
    free(temp);
    return r;
}

int rank_matrixf(MatrixF *m)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return 0;
    }
    double *temp = (double *)malloc(sizeof(double) * m->rows * m->cols);
    if (temp == NULL)
    {
        printf("No memory\n");
        return 0;
    }
    for (int i = 0; i < m->rows * m->cols; i++)
    {
        temp[i] = (double)m->data[i];
    }
    int r = rank_matrix_generic(m->rows, m->cols, temp);
    free(temp);
    return r;
}

int rank_matrixd(MatrixD *m)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return 0;
    }
    return rank_matrix_generic(m->rows, m->cols, m->data);
}

int rank_matrixc(MatrixC *m)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return 0;
    }
    return rank_matrix_generic(m->rows, m->cols, m->data);
}

// ==================== 迹 ====================

int trace_matrixi(MatrixI *m)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return 0;
    }
    if (m->rows != m->cols)
    {
        printf("Matrix must be square!\n");
        return TRACE_NONEI;
    }
    int sum = 0;
    for (int i = 0; i < m->rows; i++)
    {
        sum += m->data[i * m->cols + i];
    }
    return sum;
}

float trace_matrixf(MatrixF *m)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return TRACE_NONEF;
    }
    if (m->rows != m->cols)
    {
        printf("Matrix must be square!\n");
        return TRACE_NONEF;
    }
    float sum = 0.0f;
    for (int i = 0; i < m->rows; i++)
    {
        sum += m->data[i * m->cols + i];
    }
    return sum;
}

double trace_matrixd(MatrixD *m)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return TRACE_NONED;
    }
    if (m->rows != m->cols)
    {
        printf("Matrix must be square!\n");
        return TRACE_NONED;
    }
    double sum = 0.0;
    for (int i = 0; i < m->rows; i++)
    {
        sum += m->data[i * m->cols + i];
    }
    return sum;
}

Complex trace_matrixc(MatrixC *m)
{
    Complex zero = {0.0, 0.0};
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param!\n");
        return TRACE_NONEC;
    }
    if (m->rows != m->cols)
    {
        printf("Matrix must be square!\n");
        return TRACE_NONEC;
    }
    Complex sum = zero;
    for (int i = 0; i < m->rows; i++)
    {
        sum = add_complex(sum, m->data[i * m->cols + i]);
    }
    return sum;
}
