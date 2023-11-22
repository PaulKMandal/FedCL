#include "dense.h"
#include <stdio.h>
#include <stdlib.h>

void dense_forward(struct Layer* self) {
    Dense* dense = (Dense*)self;
    printf("Forward pass for Dense layer\n");
    // Add Feedforward-specific forward pass logic here
}

Dense* create_dense() {
    Dense* dense = (Dense*)malloc(sizeof(Dense));
    dense->base.forward = dense_forward;
    dense->base.next_layers = NULL;
    dense->base.num_next_layers = 0;
    // Initialize Feedforward-specific fields here
    return dense;
}
