// cnn.c
#include "cnn.h"
#include <stdio.h>

CNN* create_cnn() {
    CNN* cnn = (CNN*)malloc(sizeof(CNN));
    cnn->base.forward = cnn_forward;
    cnn->base.next_layers = NULL;
    cnn->base.prev_layers = NULL;
    cnn->base.num_next_layers = 0;
    cnn->base.num_prev_layers = 0;
    // Initialize CNN-specific fields here
    return cnn;
}

Tensor cnn_forward(Layer* self, Tensor* input) {
    printf("Forward pass for CNN layer\n");
    // Placeholder return
    return *input;
}
