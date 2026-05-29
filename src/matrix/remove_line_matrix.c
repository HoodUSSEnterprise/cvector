#include "matrix/remove_line_matrix.h"

MatrixI *remove_matrixi(MatrixI *m, size_t index, int axis) // axis = 0:rows , axis = 1:cols
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (axis == 0)
    {
        if (index == 0 && m->rows == 1)
        {
            return NULL;
        }
        if (index > m->rows - 1)
        {
            printf("Exceeds the matrix row limit.\n");
            return m;
        }
        else
        {
            int data[1] = {0};
            MatrixI *res = create_matrixi(m->rows - 1, m->cols, data, (m->rows - 1) * m->cols);
            for (size_t i = 0, k = 0; i < m->rows; i++)
            {
                if (i == index)
                {
                    continue;
                }
                for (size_t j = 0; j < m->cols; j++)
                {
                    res->data[k * res->cols + j] = m->data[i * m->cols + j];
                }
                k++;
            }
            return res;
        }
    }
    else
    {
        if (index == 0 && m->cols == 1)
        {
            return NULL;
        }
        if (index > m->cols - 1)
        {
            printf("Exceeds the matrix col limit.\n");
            return m;
        }
        else
        {
            int data[1] = {0};
            MatrixI *res = create_matrixi(m->rows, m->cols - 1, data, (m->cols - 1) * m->rows);
            for (size_t i = 0; i < m->rows; i++)
            {
                for (size_t j = 0, k = 0; j < m->cols; j++)
                {
                    if (j == index)
                    {
                        continue;
                    }
                    res->data[i * res->cols + k] = m->data[i * m->cols + j];
                    k++;
                }
            }
            return res;
        }
    }
}

MatrixF *remove_matrixf(MatrixF *m, size_t index, int axis) // axis = 0:rows , axis = 1:cols
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (axis == 0)
    {
        if (index == 0 && m->rows == 1)
        {
            return NULL;
        }
        if (index > m->rows - 1)
        {
            printf("Exceeds the matrix row limit.\n");
            return m;
        }
        else
        {
            float data[1] = {0};
            MatrixF *res = create_matrixf(m->rows - 1, m->cols, data, (m->rows - 1) * m->cols);
            for (size_t i = 0, k = 0; i < m->rows; i++)
            {
                if (i == index)
                {
                    continue;
                }
                for (size_t j = 0; j < m->cols; j++)
                {
                    res->data[k * res->cols + j] = m->data[i * m->cols + j];
                }
                k++;
            }
            return res;
        }
    }
    else
    {
        if (index == 0 && m->cols == 1)
        {
            return NULL;
        }
        if (index > m->cols - 1)
        {
            printf("Exceeds the matrix col limit.\n");
            return m;
        }
        else
        {
            float data[1] = {0};
            MatrixF *res = create_matrixf(m->rows, m->cols - 1, data, (m->cols - 1) * m->rows);
            for (size_t i = 0; i < m->rows; i++)
            {
                for (size_t j = 0, k = 0; j < m->cols; j++)
                {
                    if (j == index)
                    {
                        continue;
                    }
                    res->data[i * res->cols + k] = m->data[i * m->cols + j];
                    k++;
                }
            }
            return res;
        }
    }
}
MatrixD *remove_matrixd(MatrixD *m, size_t index, int axis) // axis = 0:rows , axis = 1:cols
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (axis == 0)
    {
        if (index == 0 && m->rows == 1)
        {
            return NULL;
        }
        if (index > m->rows - 1)
        {
            printf("Exceeds the matrix row limit.\n");
            return m;
        }
        else
        {
            double data[1] = {0};
            MatrixD *res = create_matrixd(m->rows - 1, m->cols, data, (m->rows - 1) * m->cols);
            for (size_t i = 0, k = 0; i < m->rows; i++)
            {
                if (i == index)
                {
                    continue;
                }
                for (size_t j = 0; j < m->cols; j++)
                {
                    res->data[k * res->cols + j] = m->data[i * m->cols + j];
                }
                k++;
            }
            return res;
        }
    }
    else
    {
        if (index == 0 && m->cols == 1)
        {
            return NULL;
        }
        if (index > m->cols - 1)
        {
            printf("Exceeds the matrix col limit.\n");
            return m;
        }
        else
        {
            double data[1] = {0};
            MatrixD *res = create_matrixd(m->rows, m->cols - 1, data, (m->cols - 1) * m->rows);
            for (size_t i = 0; i < m->rows; i++)
            {
                for (size_t j = 0, k = 0; j < m->cols; j++)
                {
                    if (j == index)
                    {
                        continue;
                    }
                    res->data[i * res->cols + k] = m->data[i * m->cols + j];
                    k++;
                }
            }
            return res;
        }
    }
}
MatrixC *remove_matrixc(MatrixC *m, size_t index, int axis) // axis = 0:rows , axis = 1:cols
{
    if (m == NULL || m->data == NULL)
    {
        printf("Invalid param\n");
        return NULL;
    }
    if (axis == 0)
    {
        if (index == 0 && m->rows == 1)
        {
            return NULL;
        }
        if (index > m->rows - 1)
        {
            printf("Exceeds the matrix row limit.\n");
            return m;
        }
        else
        {
            Complex data[1] = {{0 , 0}};
            MatrixC *res = create_matrixc(m->rows - 1, m->cols, data, (m->rows - 1) * m->cols);
            for (size_t i = 0, k = 0; i < m->rows; i++)
            {
                if (i == index)
                {
                    continue;
                }
                for (size_t j = 0; j < m->cols; j++)
                {
                    res->data[k * res->cols + j] = m->data[i * m->cols + j];
                }
                k++;
            }
            return res;
        }
    }
    else
    {
        if (index == 0 && m->cols == 1)
        {
            return NULL;
        }
        if (index > m->cols - 1)
        {
            printf("Exceeds the matrix col limit.\n");
            return m;
        }
        else
        {
            Complex data[1] = {{0, 0}};
            MatrixC *res = create_matrixc(m->rows, m->cols - 1, data, (m->cols - 1) * m->rows);
            for (size_t i = 0; i < m->rows; i++)
            {
                for (size_t j = 0, k = 0; j < m->cols; j++)
                {
                    if (j == index)
                    {
                        continue;
                    }
                    res->data[i * res->cols + k] = m->data[i * m->cols + j];
                    k++;
                }
            }
            return res;
        }
    }
}