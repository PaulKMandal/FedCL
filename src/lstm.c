// lstm.c
#include "lstm.h"
#include <stdio.h>

LSTM* create_lstm() {
    LSTM* lstm = (LSTM*)malloc(sizeof(LSTM));
    lstm->base.forward = lstm_forward;
    lstm->base.next_layers = NULL;
    lstm->base.prev_layers = NULL;
    lstm->base.num_next_layers = 0;
    lstm->base.num_prev_layers = 0;
    // Initialize LSTM-specific fields here
    return lstm;
}

Tensor lstm_forward(Layer* self, Tensor* input) {
    printf("Forward pass for LSTM layer\n");
    // Placeholder return
    return *input;
}
