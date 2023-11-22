#include "dense.h"
#include <stdio.h>
#include <stdlib.h>

void feedforward_forward(struct NeuralNetworkLayer* self) {
    FeedforwardLayer* layer = (FeedforwardLayer*)self;
    printf("Forward pass for Feedforward layer\n");
    // Add Feedforward-specific forward pass logic here
}

FeedforwardLayer* create_feedforward_layer() {
    FeedforwardLayer* layer = (FeedforwardLayer*)malloc(sizeof(FeedforwardLayer));
    layer->base.forward = feedforward_forward;
    layer->base.next_layers = NULL;
    layer->base.num_next_layers = 0;
    // Initialize Feedforward-specific fields here
    return layer;
}
