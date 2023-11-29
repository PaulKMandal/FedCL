// cnn.h
#ifndef CNN_H
#define CNN_H

#include "layer.h"

typedef struct {
    Layer base;
} CNN;

CNN* create_cnn();
Tensor cnn_forward(Layer* self, Tensor* input);

#endif // CNN_H
