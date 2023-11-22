#ifndef LAYER_H
#define LAYER_H

#include <stddef.h>

// Define the neural network layer structure
typedef struct NeuralNetworkLayer {
    void (*forward)(struct NeuralNetworkLayer*);
    struct NeuralNetworkLayer** next_layers;  // Array of pointers to next layers
    size_t num_next_layers;  // Number of next layers
} NeuralNetworkLayer;

void dfs_forward(NeuralNetworkLayer* layer);
void add_next_layer(NeuralNetworkLayer* current_layer, NeuralNetworkLayer* next_layer);

#endif  // LAYER_H
