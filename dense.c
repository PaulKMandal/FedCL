#include "dense.h"
#include <stdio.h>
#include <stdlib.h>

void dense_forward(Layer* self) {
    Dense* layer = (Dense*)self;
    printf("Forward pass for Dense\n");
    // Add Dense-specific forward pass logic here
}

Dense* create_dense() {
    Dense* layer = (Dense*)malloc(sizeof(Dense));
    layer->base.forward = dense_forward;
    layer->base.next_layers = NULL;
    layer->base.num_next_layers = 0;
    // Initialize Dense-specific fields here
    return layer;
}
