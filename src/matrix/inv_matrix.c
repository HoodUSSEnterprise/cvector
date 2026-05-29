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

    int d = det_matrix(m);
    if (d == 0)
    {
        printf("The matrix is singular, cannot invert.\n");
        return NULL;
    }

    MatrixI *adj = adjugate_matrix(m);
    if (adj == NULL)
    {
        return NULL;
    }

    double data[1] = {0};
    MatrixD *res = create_matrixd(adj->rows, adj->cols, data, 1);
    int n = adj->rows * adj->cols;
    for (int i = 0; i < n; i++)
    {
        res->data[i] = (double)adj->data[i] / d;
    }

    free_matrix(adj);
    return res;
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

    float d = det_matrix(m);
    if (d == 0.0f)
    {
        printf("The matrix is singular, cannot invert.\n");
        return NULL;
    }

    MatrixF *adj = adjugate_matrix(m);
    if (adj == NULL)
    {
        return NULL;
    }

    double data[1] = {0};
    MatrixD *res = create_matrixd(adj->rows, adj->cols, data, 1);
    int n = adj->rows * adj->cols;
    for (int i = 0; i < n; i++)
    {
        res->data[i] = (double)adj->data[i] / d;
    }

    free_matrix(adj);
    return res;
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

    double d = det_matrix(m);
    if (d == 0.0)
    {
        printf("The matrix is singular, cannot invert.\n");
        return NULL;
    }

    MatrixD *adj = adjugate_matrix(m);
    if (adj == NULL)
    {
        return NULL;
    }

    double data[1] = {0};
    MatrixD *res = create_matrixd(adj->rows, adj->cols, data, 1);
    int n = adj->rows * adj->cols;
    for (int i = 0; i < n; i++)
    {
        res->data[i] = adj->data[i] / d;
    }

    free_matrix(adj);
    return res;
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

    Complex d = det_matrix(m);
    if (d.real == 0.0 && d.imag == 0.0)
    {
        printf("The matrix is singular, cannot invert.\n");
        return NULL;
    }

    MatrixC *adj = adjugate_matrix(m);
    if (adj == NULL)
    {
        return NULL;
    }

    Complex data[1] = {{0, 0}};
    MatrixC *res = create_matrixc(adj->rows, adj->cols, data, 1);
    int n = adj->rows * adj->cols;
    for (int i = 0; i < n; i++)
    {
        res->data[i] = div_complex(adj->data[i], d);
    }

    free_matrix(adj);
    return res;
}
