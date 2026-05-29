#include "matrix/pow_matrix.h"

MatrixD *pow_matrixi(MatrixI *m, int index)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (m->rows != m->cols)
    {
        printf("The matrix is not square.\n");
        return NULL;
    }
    if (index == 0)
    {
        return indentity_matrixd(m->rows);
    }
    else if (index > 0)
    {
        MatrixD *res = create_matrixd(m->rows, m->cols, m->data, m->rows * m->cols);
        for (size_t i = 0; i < index - 1; i++)
        {
            res = mul_matrix(res, m);
        }
        return res;
    }
    else
    {
        if (inv_matrixi(m) == NULL)
        {
            printf("The matrix is singular\n");
            return NULL;
        }
        MatrixD *res = inv_matrix(m);
        MatrixD *inv = inv_matrix(m);
        for (size_t i = 0; i < index - 1; i++)
        {
            res = mul_matrix(res, inv);
        }
        return res;
    }
}

MatrixD *pow_matrixf(MatrixF *m, int index)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (m->rows != m->cols)
    {
        printf("The matrix is not square.\n");
        return NULL;
    }
    if (index == 0)
    {
        return indentity_matrixd(m->rows);
    }
    else if (index > 0)
    {
        MatrixD *res = create_matrixd(m->rows, m->cols, m->data, m->rows * m->cols);
        for (size_t i = 0; i < index - 1; i++)
        {
            res = mul_matrix(res, m);
        }
        return res;
    }
    else
    {
        if (inv_matrixf(m) == NULL)
        {
            printf("The matrix is singular\n");
            return NULL;
        }
        MatrixD *res = inv_matrix(m);
        MatrixD *inv = inv_matrix(m);
        for (size_t i = 0; i < index - 1; i++)
        {
            res = mul_matrix(res, inv);
        }
        return res;
    }
}

MatrixD *pow_matrixd(MatrixD *m, int index)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (m->rows != m->cols)
    {
        printf("The matrix is not square.\n");
        return NULL;
    }
    if (index == 0)
    {
        return indentity_matrixd(m->rows);
    }
    else if (index > 0)
    {
        MatrixD *res = create_matrixd(m->rows, m->cols, m->data, m->rows * m->cols);
        for (size_t i = 0; i < index - 1; i++)
        {
            res = mul_matrix(res, m);
        }
        return res;
    }
    else
    {
        if (inv_matrixd(m) == NULL)
        {
            printf("The matrix is singular\n");
            return NULL;
        }
        MatrixD *res = inv_matrix(m);
        MatrixD *inv = inv_matrix(m);
        for (size_t i = 0; i < index - 1; i++)
        {
            res = mul_matrix(res, inv);
        }
        return res;
    }
}

MatrixC *pow_matrixc(MatrixC *m, int index)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (m->rows != m->cols)
    {
        printf("The matrix is not square.\n");
        return NULL;
    }
    if (index == 0)
    {
        return indentity_matrixd(m->rows);
    }
    else if (index > 0)
    {
        MatrixD *res = create_matrixd(m->rows, m->cols, m->data, m->rows * m->cols);
        for (size_t i = 0; i < index - 1; i++)
        {
            res = mul_matrix(res, m);
        }
        return res;
    }
    else
    {
        if (inv_matrixc(m) == NULL)
        {
            printf("The matrix is singular\n");
            return NULL;
        }
        MatrixD *res = inv_matrix(m);
        MatrixD *inv = inv_matrix(m);
        for (size_t i = 0; i < index - 1; i++)
        {
            res = mul_matrix(res, inv);
        }
        return res;
    }
}