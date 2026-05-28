#include "matrix/free_matrix.h"

void free_matrixi(MatrixI *m)
{
    free(m->data);
    free(m);
}

void free_matrixf(MatrixF *m)
{
    free(m->data);
    free(m);
}


void free_matrixd(MatrixD *m)
{
    free(m->data);
    free(m);
}


void free_matrixc(MatrixC *m)
{
    free(m->data);
    free(m);
}
