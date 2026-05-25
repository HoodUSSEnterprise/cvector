#ifndef BASE_VECTOR_H
#define BASE_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "complex/base_complex.h"

typedef struct Vector2i
{
    int x;
    int y;
} Vector2i;

typedef struct Vector2f
{
    float x;
    float y;
} Vector2f;

typedef struct Vector2d
{
    double x;
    double y;
} Vector2d;

typedef struct Vector2c
{
    Complex x;
    Complex y;
} Vector2c;

typedef struct Vector3i
{
    int x;
    int y;
    int z;
} Vector3i;

typedef struct Vector3f
{
    float x;
    float y;
    float z;
} Vector3f;

typedef struct Vector3d
{
    double x;
    double y;
    double z;
} Vector3d;

typedef struct Vector3c
{
    Complex x;
    Complex y;
    Complex z;
} Vector3c;

typedef struct Vectori
{
    size_t len;
    int *data;
} Vectori;

typedef struct Vectorf
{
    size_t len;
    float *data;
} Vectorf;

typedef struct Vectord
{
    size_t len;
    double *data;
} Vectord;

typedef struct Vectorc
{
    size_t len;
    Complex *data;
} Vectorc;

extern Vectori *Nonei;
extern Vectorf *Nonef;
extern Vectord *Noned;
extern Vectorc *Nonec;

#endif // BASE_VECTOR_H