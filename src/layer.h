// layer.h
#ifndef LAYER_H
#define LAYER_H

#include "tensor.h"

typedef struct Layer {
    Tensor (*forward)(struct Layer*, Tensor*);
    struct Layer** next_layers;
    struct Layer** prev_layers;
    size_t num_next_layers;
    size_t num_prev_layers;
} Layer;

void dfs_forward(Layer* layer, Tensor* input);
void add_layer(Layer* current_layer, Layer* next_layer);

#endif // LAYER_H
