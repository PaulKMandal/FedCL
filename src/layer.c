// layer.c
#include <stdio.h>
#include <stdlib.h>
#include "layer.h"

void dfs_forward(Layer* layer, double* input) {
    // DFS forward pass logic
    // Call the forward method for each layer in a DFS manner
    layer->forward(layer, input);
    for (size_t i = 0; i < layer->num_next_layers; ++i) {
        dfs_forward(layer->next_layers[i], input);
    }
}

void add_layer(Layer* current_layer, Layer* next_layer) {
    current_layer->next_layers = realloc(current_layer->next_layers, (current_layer->num_next_layers + 1) * sizeof(Layer*));
    current_layer->next_layers[current_layer->num_next_layers] = next_layer;

    next_layer->prev_layers = realloc(next_layer->prev_layers, (next_layer->num_prev_layers + 1) * sizeof(Layer*));
    next_layer->prev_layers[next_layer->num_prev_layers] = current_layer;

    current_layer->num_next_layers++;
    next_layer->num_prev_layers++;
}
