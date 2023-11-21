#ifndef CNN_H
#define CNN_H

#include "layer.h"

typedef struct {
    Layer base;
    // Add CNN-specific fields here
} CNN;

CNN* create_cnn_layer();

#endif // CNN_H
