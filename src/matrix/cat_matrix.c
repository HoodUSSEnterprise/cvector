#include "matrix/cat_matrix.h"

// ==================== 辅助函数 ====================

static int validate_cat_axis(int axis)
{
    if (axis != 0 && axis != 1)
    {
        printf("Invalid axis! Must be 0 (vertical) or 1 (horizontal)\n");
        return 0;
    }
    return 1;
}

// ==================== 同类型连接 ====================

MatrixI *cat_matrixi_i(MatrixI *m1, MatrixI *m2, int axis)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (!validate_cat_axis(axis))
    {
        return NULL;
    }

    MatrixI *res = (MatrixI *)malloc(sizeof(MatrixI));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }

    if (axis == 0)
    {
        if (m1->cols != m2->cols)
        {
            printf("Column mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows + m2->rows;
        res->cols = m1->cols;
        res->data = (int *)malloc(sizeof(int) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        memcpy(res->data, m1->data, sizeof(int) * m1->rows * m1->cols);
        memcpy(res->data + m1->rows * m1->cols, m2->data, sizeof(int) * m2->rows * m2->cols);
    }
    else // axis == 1
    {
        if (m1->rows != m2->rows)
        {
            printf("Row mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows;
        res->cols = m1->cols + m2->cols;
        res->data = (int *)malloc(sizeof(int) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < res->rows; i++)
        {
            memcpy(res->data + i * res->cols, m1->data + i * m1->cols, sizeof(int) * m1->cols);
            memcpy(res->data + i * res->cols + m1->cols, m2->data + i * m2->cols, sizeof(int) * m2->cols);
        }
    }
    return res;
}

MatrixF *cat_matrixf_f(MatrixF *m1, MatrixF *m2, int axis)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (!validate_cat_axis(axis))
    {
        return NULL;
    }

    MatrixF *res = (MatrixF *)malloc(sizeof(MatrixF));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }

    if (axis == 0)
    {
        if (m1->cols != m2->cols)
        {
            printf("Column mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows + m2->rows;
        res->cols = m1->cols;
        res->data = (float *)malloc(sizeof(float) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        memcpy(res->data, m1->data, sizeof(float) * m1->rows * m1->cols);
        memcpy(res->data + m1->rows * m1->cols, m2->data, sizeof(float) * m2->rows * m2->cols);
    }
    else
    {
        if (m1->rows != m2->rows)
        {
            printf("Row mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows;
        res->cols = m1->cols + m2->cols;
        res->data = (float *)malloc(sizeof(float) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < res->rows; i++)
        {
            memcpy(res->data + i * res->cols, m1->data + i * m1->cols, sizeof(float) * m1->cols);
            memcpy(res->data + i * res->cols + m1->cols, m2->data + i * m2->cols, sizeof(float) * m2->cols);
        }
    }
    return res;
}

MatrixD *cat_matrixd_d(MatrixD *m1, MatrixD *m2, int axis)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (!validate_cat_axis(axis))
    {
        return NULL;
    }

    MatrixD *res = (MatrixD *)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }

    if (axis == 0)
    {
        if (m1->cols != m2->cols)
        {
            printf("Column mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows + m2->rows;
        res->cols = m1->cols;
        res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        memcpy(res->data, m1->data, sizeof(double) * m1->rows * m1->cols);
        memcpy(res->data + m1->rows * m1->cols, m2->data, sizeof(double) * m2->rows * m2->cols);
    }
    else
    {
        if (m1->rows != m2->rows)
        {
            printf("Row mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows;
        res->cols = m1->cols + m2->cols;
        res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < res->rows; i++)
        {
            memcpy(res->data + i * res->cols, m1->data + i * m1->cols, sizeof(double) * m1->cols);
            memcpy(res->data + i * res->cols + m1->cols, m2->data + i * m2->cols, sizeof(double) * m2->cols);
        }
    }
    return res;
}

MatrixC *cat_matrixc_c(MatrixC *m1, MatrixC *m2, int axis)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (!validate_cat_axis(axis))
    {
        return NULL;
    }

    MatrixC *res = (MatrixC *)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }

    if (axis == 0)
    {
        if (m1->cols != m2->cols)
        {
            printf("Column mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows + m2->rows;
        res->cols = m1->cols;
        res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        memcpy(res->data, m1->data, sizeof(Complex) * m1->rows * m1->cols);
        memcpy(res->data + m1->rows * m1->cols, m2->data, sizeof(Complex) * m2->rows * m2->cols);
    }
    else
    {
        if (m1->rows != m2->rows)
        {
            printf("Row mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows;
        res->cols = m1->cols + m2->cols;
        res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < res->rows; i++)
        {
            memcpy(res->data + i * res->cols, m1->data + i * m1->cols, sizeof(Complex) * m1->cols);
            memcpy(res->data + i * res->cols + m1->cols, m2->data + i * m2->cols, sizeof(Complex) * m2->cols);
        }
    }
    return res;
}

// ==================== int + float -> float ====================

MatrixF *cat_matrixi_f(MatrixI *m1, MatrixF *m2, int axis)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (!validate_cat_axis(axis))
    {
        return NULL;
    }

    MatrixF *res = (MatrixF *)malloc(sizeof(MatrixF));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }

    if (axis == 0)
    {
        if (m1->cols != m2->cols)
        {
            printf("Column mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows + m2->rows;
        res->cols = m1->cols;
        res->data = (float *)malloc(sizeof(float) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < m1->rows * m1->cols; i++)
            res->data[i] = (float)m1->data[i];
        for (int i = 0; i < m2->rows * m2->cols; i++)
            res->data[m1->rows * m1->cols + i] = m2->data[i];
    }
    else
    {
        if (m1->rows != m2->rows)
        {
            printf("Row mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows;
        res->cols = m1->cols + m2->cols;
        res->data = (float *)malloc(sizeof(float) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < res->rows; i++)
        {
            for (int j = 0; j < m1->cols; j++)
                res->data[i * res->cols + j] = (float)m1->data[i * m1->cols + j];
            for (int j = 0; j < m2->cols; j++)
                res->data[i * res->cols + m1->cols + j] = m2->data[i * m2->cols + j];
        }
    }
    return res;
}

MatrixF *cat_matrixf_i(MatrixF *m1, MatrixI *m2, int axis)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (!validate_cat_axis(axis))
    {
        return NULL;
    }

    MatrixF *res = (MatrixF *)malloc(sizeof(MatrixF));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }

    if (axis == 0)
    {
        if (m1->cols != m2->cols)
        {
            printf("Column mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows + m2->rows;
        res->cols = m1->cols;
        res->data = (float *)malloc(sizeof(float) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        memcpy(res->data, m1->data, sizeof(float) * m1->rows * m1->cols);
        for (int i = 0; i < m2->rows * m2->cols; i++)
            res->data[m1->rows * m1->cols + i] = (float)m2->data[i];
    }
    else
    {
        if (m1->rows != m2->rows)
        {
            printf("Row mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows;
        res->cols = m1->cols + m2->cols;
        res->data = (float *)malloc(sizeof(float) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < res->rows; i++)
        {
            memcpy(res->data + i * res->cols, m1->data + i * m1->cols, sizeof(float) * m1->cols);
            for (int j = 0; j < m2->cols; j++)
                res->data[i * res->cols + m1->cols + j] = (float)m2->data[i * m2->cols + j];
        }
    }
    return res;
}

// ==================== int + double -> double ====================

MatrixD *cat_matrixi_d(MatrixI *m1, MatrixD *m2, int axis)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (!validate_cat_axis(axis))
    {
        return NULL;
    }

    MatrixD *res = (MatrixD *)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }

    if (axis == 0)
    {
        if (m1->cols != m2->cols)
        {
            printf("Column mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows + m2->rows;
        res->cols = m1->cols;
        res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < m1->rows * m1->cols; i++)
            res->data[i] = (double)m1->data[i];
        memcpy(res->data + m1->rows * m1->cols, m2->data, sizeof(double) * m2->rows * m2->cols);
    }
    else
    {
        if (m1->rows != m2->rows)
        {
            printf("Row mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows;
        res->cols = m1->cols + m2->cols;
        res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < res->rows; i++)
        {
            for (int j = 0; j < m1->cols; j++)
                res->data[i * res->cols + j] = (double)m1->data[i * m1->cols + j];
            memcpy(res->data + i * res->cols + m1->cols, m2->data + i * m2->cols, sizeof(double) * m2->cols);
        }
    }
    return res;
}

MatrixD *cat_matrixd_i(MatrixD *m1, MatrixI *m2, int axis)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (!validate_cat_axis(axis))
    {
        return NULL;
    }

    MatrixD *res = (MatrixD *)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }

    if (axis == 0)
    {
        if (m1->cols != m2->cols)
        {
            printf("Column mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows + m2->rows;
        res->cols = m1->cols;
        res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        memcpy(res->data, m1->data, sizeof(double) * m1->rows * m1->cols);
        for (int i = 0; i < m2->rows * m2->cols; i++)
            res->data[m1->rows * m1->cols + i] = (double)m2->data[i];
    }
    else
    {
        if (m1->rows != m2->rows)
        {
            printf("Row mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows;
        res->cols = m1->cols + m2->cols;
        res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < res->rows; i++)
        {
            memcpy(res->data + i * res->cols, m1->data + i * m1->cols, sizeof(double) * m1->cols);
            for (int j = 0; j < m2->cols; j++)
                res->data[i * res->cols + m1->cols + j] = (double)m2->data[i * m2->cols + j];
        }
    }
    return res;
}

// ==================== int + Complex -> Complex ====================

MatrixC *cat_matrixi_c(MatrixI *m1, MatrixC *m2, int axis)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (!validate_cat_axis(axis))
    {
        return NULL;
    }

    MatrixC *res = (MatrixC *)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }

    if (axis == 0)
    {
        if (m1->cols != (int)m2->cols)
        {
            printf("Column mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows + m2->rows;
        res->cols = m1->cols;
        res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < m1->rows * m1->cols; i++)
            res->data[i] = (Complex){(double)m1->data[i], 0.0};
        memcpy(res->data + m1->rows * m1->cols, m2->data, sizeof(Complex) * m2->rows * m2->cols);
    }
    else
    {
        if (m1->rows != (int)m2->rows)
        {
            printf("Row mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows;
        res->cols = m1->cols + m2->cols;
        res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < res->rows; i++)
        {
            for (int j = 0; j < m1->cols; j++)
                res->data[i * res->cols + j] = (Complex){(double)m1->data[i * m1->cols + j], 0.0};
            memcpy(res->data + i * res->cols + m1->cols, m2->data + i * m2->cols, sizeof(Complex) * m2->cols);
        }
    }
    return res;
}

MatrixC *cat_matrixc_i(MatrixC *m1, MatrixI *m2, int axis)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (!validate_cat_axis(axis))
    {
        return NULL;
    }

    MatrixC *res = (MatrixC *)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }

    if (axis == 0)
    {
        if ((int)m1->cols != m2->cols)
        {
            printf("Column mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows + m2->rows;
        res->cols = m1->cols;
        res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        memcpy(res->data, m1->data, sizeof(Complex) * m1->rows * m1->cols);
        for (int i = 0; i < m2->rows * m2->cols; i++)
            res->data[m1->rows * m1->cols + i] = (Complex){(double)m2->data[i], 0.0};
    }
    else
    {
        if ((int)m1->rows != m2->rows)
        {
            printf("Row mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows;
        res->cols = m1->cols + m2->cols;
        res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < res->rows; i++)
        {
            memcpy(res->data + i * res->cols, m1->data + i * m1->cols, sizeof(Complex) * m1->cols);
            for (int j = 0; j < m2->cols; j++)
                res->data[i * res->cols + m1->cols + j] = (Complex){(double)m2->data[i * m2->cols + j], 0.0};
        }
    }
    return res;
}

// ==================== float + double -> double ====================

MatrixD *cat_matrixf_d(MatrixF *m1, MatrixD *m2, int axis)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (!validate_cat_axis(axis))
    {
        return NULL;
    }

    MatrixD *res = (MatrixD *)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }

    if (axis == 0)
    {
        if ((int)m1->cols != m2->cols)
        {
            printf("Column mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows + m2->rows;
        res->cols = m1->cols;
        res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < m1->rows * m1->cols; i++)
            res->data[i] = (double)m1->data[i];
        memcpy(res->data + m1->rows * m1->cols, m2->data, sizeof(double) * m2->rows * m2->cols);
    }
    else
    {
        if ((int)m1->rows != m2->rows)
        {
            printf("Row mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows;
        res->cols = m1->cols + m2->cols;
        res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < res->rows; i++)
        {
            for (int j = 0; j < m1->cols; j++)
                res->data[i * res->cols + j] = (double)m1->data[i * m1->cols + j];
            memcpy(res->data + i * res->cols + m1->cols, m2->data + i * m2->cols, sizeof(double) * m2->cols);
        }
    }
    return res;
}

MatrixD *cat_matrixd_f(MatrixD *m1, MatrixF *m2, int axis)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (!validate_cat_axis(axis))
    {
        return NULL;
    }

    MatrixD *res = (MatrixD *)malloc(sizeof(MatrixD));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }

    if (axis == 0)
    {
        if (m1->cols != (int)m2->cols)
        {
            printf("Column mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows + m2->rows;
        res->cols = m1->cols;
        res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        memcpy(res->data, m1->data, sizeof(double) * m1->rows * m1->cols);
        for (int i = 0; i < m2->rows * m2->cols; i++)
            res->data[m1->rows * m1->cols + i] = (double)m2->data[i];
    }
    else
    {
        if (m1->rows != (int)m2->rows)
        {
            printf("Row mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows;
        res->cols = m1->cols + m2->cols;
        res->data = (double *)malloc(sizeof(double) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < res->rows; i++)
        {
            memcpy(res->data + i * res->cols, m1->data + i * m1->cols, sizeof(double) * m1->cols);
            for (int j = 0; j < m2->cols; j++)
                res->data[i * res->cols + m1->cols + j] = (double)m2->data[i * m2->cols + j];
        }
    }
    return res;
}

// ==================== float + Complex -> Complex ====================

MatrixC *cat_matrixf_c(MatrixF *m1, MatrixC *m2, int axis)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (!validate_cat_axis(axis))
    {
        return NULL;
    }

    MatrixC *res = (MatrixC *)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }

    if (axis == 0)
    {
        if ((int)m1->cols != m2->cols)
        {
            printf("Column mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows + m2->rows;
        res->cols = m1->cols;
        res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < m1->rows * m1->cols; i++)
            res->data[i] = (Complex){(double)m1->data[i], 0.0};
        memcpy(res->data + m1->rows * m1->cols, m2->data, sizeof(Complex) * m2->rows * m2->cols);
    }
    else
    {
        if ((int)m1->rows != m2->rows)
        {
            printf("Row mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows;
        res->cols = m1->cols + m2->cols;
        res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < res->rows; i++)
        {
            for (int j = 0; j < m1->cols; j++)
                res->data[i * res->cols + j] = (Complex){(double)m1->data[i * m1->cols + j], 0.0};
            memcpy(res->data + i * res->cols + m1->cols, m2->data + i * m2->cols, sizeof(Complex) * m2->cols);
        }
    }
    return res;
}

MatrixC *cat_matrixc_f(MatrixC *m1, MatrixF *m2, int axis)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (!validate_cat_axis(axis))
    {
        return NULL;
    }

    MatrixC *res = (MatrixC *)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }

    if (axis == 0)
    {
        if ((int)m1->cols != m2->cols)
        {
            printf("Column mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows + m2->rows;
        res->cols = m1->cols;
        res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        memcpy(res->data, m1->data, sizeof(Complex) * m1->rows * m1->cols);
        for (int i = 0; i < m2->rows * m2->cols; i++)
            res->data[m1->rows * m1->cols + i] = (Complex){(double)m2->data[i], 0.0};
    }
    else
    {
        if ((int)m1->rows != m2->rows)
        {
            printf("Row mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows;
        res->cols = m1->cols + m2->cols;
        res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < res->rows; i++)
        {
            memcpy(res->data + i * res->cols, m1->data + i * m1->cols, sizeof(Complex) * m1->cols);
            for (int j = 0; j < m2->cols; j++)
                res->data[i * res->cols + m1->cols + j] = (Complex){(double)m2->data[i * m2->cols + j], 0.0};
        }
    }
    return res;
}

// ==================== double + Complex -> Complex ====================

MatrixC *cat_matrixd_c(MatrixD *m1, MatrixC *m2, int axis)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (!validate_cat_axis(axis))
    {
        return NULL;
    }

    MatrixC *res = (MatrixC *)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }

    if (axis == 0)
    {
        if (m1->cols != m2->cols)
        {
            printf("Column mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows + m2->rows;
        res->cols = m1->cols;
        res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < m1->rows * m1->cols; i++)
            res->data[i] = (Complex){m1->data[i], 0.0};
        memcpy(res->data + m1->rows * m1->cols, m2->data, sizeof(Complex) * m2->rows * m2->cols);
    }
    else
    {
        if (m1->rows != m2->rows)
        {
            printf("Row mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows;
        res->cols = m1->cols + m2->cols;
        res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < res->rows; i++)
        {
            for (int j = 0; j < m1->cols; j++)
                res->data[i * res->cols + j] = (Complex){m1->data[i * m1->cols + j], 0.0};
            memcpy(res->data + i * res->cols + m1->cols, m2->data + i * m2->cols, sizeof(Complex) * m2->cols);
        }
    }
    return res;
}

MatrixC *cat_matrixc_d(MatrixC *m1, MatrixD *m2, int axis)
{
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("Invalid param!\n");
        return NULL;
    }
    if (!validate_cat_axis(axis))
    {
        return NULL;
    }

    MatrixC *res = (MatrixC *)malloc(sizeof(MatrixC));
    if (res == NULL)
    {
        printf("No memory\n");
        return NULL;
    }

    if (axis == 0)
    {
        if (m1->cols != m2->cols)
        {
            printf("Column mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows + m2->rows;
        res->cols = m1->cols;
        res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        memcpy(res->data, m1->data, sizeof(Complex) * m1->rows * m1->cols);
        for (int i = 0; i < m2->rows * m2->cols; i++)
            res->data[m1->rows * m1->cols + i] = (Complex){m2->data[i], 0.0};
    }
    else
    {
        if (m1->rows != m2->rows)
        {
            printf("Row mismatch! m1(%d,%d) vs m2(%d,%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
            free(res);
            return NULL;
        }
        res->rows = m1->rows;
        res->cols = m1->cols + m2->cols;
        res->data = (Complex *)malloc(sizeof(Complex) * res->rows * res->cols);
        if (res->data == NULL)
        {
            printf("No memory\n");
            free(res);
            return NULL;
        }
        for (int i = 0; i < res->rows; i++)
        {
            memcpy(res->data + i * res->cols, m1->data + i * m1->cols, sizeof(Complex) * m1->cols);
            for (int j = 0; j < m2->cols; j++)
                res->data[i * res->cols + m1->cols + j] = (Complex){m2->data[i * m2->cols + j], 0.0};
        }
    }
    return res;
}