#include "matrix/replace_matrix.h"

MatrixI *replace_matrixi_elem(MatrixI *m, int old_elem, int new_elem)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (find_matrix(m, old_elem).x == NonePos.x)
    {
        printf("No number %d\n", old_elem);
        return m;
    }
    MatrixI *res = copy_matrix(m);
    while (find_matrix(res, old_elem).x != NonePos.x)
    {
        Pos p = find_matrix(res, old_elem);
        res->data[p.x * res->cols + p.y] = new_elem;
    }
    return res;
}

MatrixF *replace_matrixf_elem(MatrixF *m, float old_elem, float new_elem)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (find_matrix(m, old_elem).x == NonePos.x)
    {
        printf("No number %f\n", old_elem);
        return m;
    }
    MatrixF *res = copy_matrix(m);
    while (find_matrix(res, old_elem).x != NonePos.x)
    {
        Pos p = find_matrix(res, old_elem);
        res->data[p.x * res->cols + p.y] = new_elem;
    }
    return res;
}

MatrixD *replace_matrixd_elem(MatrixD *m, int old_elem, int new_elem)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (find_matrix(m, old_elem).x == NonePos.x)
    {
        printf("No number %lf\n", old_elem);
        return m;
    }
    MatrixD *res = copy_matrix(m);
    while (find_matrix(res, old_elem).x != NonePos.x)
    {
        Pos p = find_matrix(res, old_elem);
        res->data[p.x * res->cols + p.y] = new_elem;
    }
    return res;
}

MatrixC *replace_matrixc_elem(MatrixC *m, Complex old_elem, Complex new_elem)
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (find_matrix(m, old_elem).x == NonePos.x)
    {
        printf("No number ");
        print_complex(old_elem);
        return m;
    }
    MatrixC *res = copy_matrix(m);
    while (find_matrix(res, old_elem).x != NonePos.x)
    {
        Pos p = find_matrix(res, old_elem);
        res->data[p.x * res->cols + p.y] = new_elem;
    }
    return res;
}