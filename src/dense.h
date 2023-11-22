#ifndef DENSE_H
#define DENSE_H

#include "layer.h"

// Define the Feedforward layer structure
typedef struct {
    NeuralNetworkLayer base;
    // Add Feedforward-specific fields here
} FeedforwardLayer;

void feedforward_forward(struct NeuralNetworkLayer* self);
FeedforwardLayer* create_feedforward_layer();

#endif  // DENSE_H
