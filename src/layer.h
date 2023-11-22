#ifndef LAYER_H
#define LAYER_H

#include <stddef.h>

// Define the layer structure
typedef struct Layer {
    void (*forward)(struct Layer*);
    struct Layer** next_layers;  // Array of pointers to next layers
    size_t num_next_layers;  // Number of next layers
} Layer;

void dfs_forward(Layer* layer);
void add_layer(Layer* current_layer, Layer* next_layer);

#endif  // LAYER_H
