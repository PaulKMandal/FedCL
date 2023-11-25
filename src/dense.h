// dense.h
#ifndef DENSE_H
#define DENSE_H

#include "layer.h"

typedef struct {
    Layer base;
    size_t input_size;
    size_t output_size;
    double** weights;
    double* biases;
} Dense;

Dense* create_dense(size_t input_size, size_t output_size);
void free_dense(Dense* dense);
void dense_forward(Layer* self, double* input);

#endif  // DENSE_H
