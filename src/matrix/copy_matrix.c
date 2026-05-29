#include "matrix/copy_matrix.h"

MatrixI *copy_matrixi(MatrixI *m)
{
    if(m == NULL || m->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    return create_matrixi(m->rows, m->cols, m->data, m->rows * m->cols); //在create_matrix中，会重新内存分配
}

MatrixF *copy_matrixf(MatrixF *m)
{
    if(m == NULL || m->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    return create_matrixf(m->rows, m->cols, m->data, m->rows * m->cols);
}

MatrixD *copy_matrixd(MatrixD *m)
{
    if(m == NULL || m->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    return create_matrixd(m->rows, m->cols, m->data, m->rows * m->cols);
}

MatrixC *copy_matrixc(MatrixC *m)
{
    if(m == NULL || m->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    return create_matrixc(m->rows, m->cols, m->data, m->rows * m->cols);
}