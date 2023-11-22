#ifndef CNN_H
#define CNN_H

#include "layer.h"

// Define the CNN layer structure
typedef struct {
    NeuralNetworkLayer base;
    // Add CNN-specific fields here
} CNNLayer;

void cnn_forward(struct NeuralNetworkLayer* self);
CNNLayer* create_cnn_layer();

#endif  // CNN_H
