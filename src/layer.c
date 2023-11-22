#include "layer.h"
#include <stdio.h>
#include <stdlib.h>

void dfs_forward(NeuralNetworkLayer* layer) {
    if (layer == NULL) {
        return;
    }

    layer->forward(layer);

    for (size_t i = 0; i < layer->num_next_layers; ++i) {
        dfs_forward(layer->next_layers[i]);
    }
}

void add_next_layer(NeuralNetworkLayer* current_layer, NeuralNetworkLayer* next_layer) {
    current_layer->next_layers = realloc(current_layer->next_layers, (current_layer->num_next_layers + 1) * sizeof(NeuralNetworkLayer*));
    current_layer->next_layers[current_layer->num_next_layers++] = next_layer;
}
