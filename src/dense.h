// dense.h
#ifndef DENSE_H
#define DENSE_H

#include "layer.h"

typedef struct {
    Layer base;
    size_t input_size;
    size_t output_size;
    Tensor weights;
    Tensor biases;
} Dense;

Dense* create_dense(size_t input_size, size_t output_size);
Tensor dense_forward(Layer* self, Tensor* input);

#endif // DENSE_H
