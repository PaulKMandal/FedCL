#include "cnn.h"
#include <stdio.h>
#include <stdlib.h>

void cnn_forward(Layer* self) {
    CNN* layer = (CNN*)self;
    printf("Forward pass for CNN\n");
    // Add CNN-specific forward pass logic here
}

CNN* create_cnn() {
    CNN* layer = (CNN*)malloc(sizeof(CNN));
    layer->base.forward = cnn_forward;
    layer->base.next_layers = NULL;
    layer->base.num_next_layers = 0;
    // Initialize CNN-specific fields here
    return layer;
}
