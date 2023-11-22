#ifndef DENSE_H
#define DENSE_H

#include "layer.h"

// Define the Feedforward layer structure
typedef struct {
    Layer base;
    // Add Feedforward-specific fields here
} Dense;

void dense_forward(struct Layer* self);
Dense* create_dense();

#endif  // DENSE_H
