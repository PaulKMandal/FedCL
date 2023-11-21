#ifndef LAYER_H
#define LAYER_H

#include <stddef.h>

typedef struct Layer {
    void (*forward)(struct Layer*);
    struct Layer** next_layers;
    size_t num_next_layers;
} Layer;

void add_next_layer(Layer* current_layer, Layer* next_layer);
void dfs_forward(Layer* layer);

#endif // LAYER_H
