// cnn.h
#ifndef CNN_H
#define CNN_H

#include "layer.h"

typedef struct {
    Layer base;
} CNN;

CNN* create_cnn(void);
void cnn_forward(Layer* self, double* input);

#endif  // CNN_H
