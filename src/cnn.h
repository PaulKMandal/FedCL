#ifndef CNN_H
#define CNN_H

#include "layer.h"

// Define the CNN layer structure
typedef struct {
    Layer base;
    // Add CNN-specific fields here
} CNN;

void cnn_forward(struct Layer* self);
CNN* create_cnn();

#endif  // CNN_H
