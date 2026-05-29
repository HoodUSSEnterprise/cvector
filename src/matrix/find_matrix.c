#include "matrix/find_matrix.h"

Pos NonePos = {-1, -1};

Pos find_matrixi(MatrixI *m, int elem)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param\n");
        return NonePos;
    }
    Pos res = {0, 0};
    for (size_t i = 0; i < m->rows; i++)
    {
        for (size_t j = 0; j < m->cols; j++)
        {
            if (m->data[i * m->cols + j] == elem)
            {
                res.x = i;
                res.y = j;
                return res;
            }
        }
    }
    return NonePos;
}

Pos find_matrixf(MatrixF *m, float elem)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param\n");
        return NonePos;
    }
    Pos res = {0, 0};
    for (size_t i = 0; i < m->rows; i++)
    {
        for (size_t j = 0; j < m->cols; j++)
        {
            if (fabs(m->data[i * m->cols + j] - elem) < 1e-6)
            {
                res.x = i;
                res.y = j;
                return res;
            }
        }
    }
    return NonePos;
}

Pos find_matrixd(MatrixD *m, double elem)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param\n");
        return NonePos;
    }
    Pos res = {0, 0};
    for (size_t i = 0; i < m->rows; i++)
    {
        for (size_t j = 0; j < m->cols; j++)
        {
            if (fabs(m->data[i * m->cols + j] - elem) < 1e-6)
            {
                res.x = i;
                res.y = j;
                return res;
            }
        }
    }
    return NonePos;
}

Pos find_matrixc(MatrixC *m, Complex elem)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param\n");
        return NonePos;
    }
    Pos res = {0, 0};
    for (size_t i = 0; i < m->rows; i++)
    {
        for (size_t j = 0; j < m->cols; j++)
        {
            if (is_equal_complex(m->data[i * m->cols + j], elem))
            {
                res.x = i;
                res.y = j;
                return res;
            }
        }
    }
    return NonePos;
}
