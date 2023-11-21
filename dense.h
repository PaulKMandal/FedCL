#ifndef DENSE_H
#define DENSE_H

#include "layer.h"

typedef struct {
    Layer base;
    // Add Dense-specific fields here
} Dense;

Dense* create_dense();

#endif // DENSE_H
