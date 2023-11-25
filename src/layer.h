// layer.h
#ifndef LAYER_H
#define LAYER_H

typedef struct Layer {
    void (*forward)(struct Layer*, double*);
    struct Layer** next_layers;
    struct Layer** prev_layers;
    size_t num_next_layers;
    size_t num_prev_layers;
} Layer;

void dfs_forward(Layer* layer, double* input);
void add_layer(Layer* current_layer, Layer* next_layer);

#endif  // LAYER_H
