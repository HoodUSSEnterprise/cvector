#include "matrix/inv_matrix.h"

MatrixD *inv_matrixi(MatrixI *m)
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
    
}

MatrixD *inv_matrixf(MatrixF *m)
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
    
}

MatrixD *inv_matrixd(MatrixD *m)
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
    
}

MatrixC *inv_matrixc(MatrixC *m)
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
    
}
