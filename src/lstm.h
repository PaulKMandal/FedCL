#ifndef LSTM_H
#define LSTM_H

#include "layer.h"

// Define the LSTM layer structure
typedef struct {
    NeuralNetworkLayer base;
    // Add LSTM-specific fields here
} LSTMLayer;

void lstm_forward(struct NeuralNetworkLayer* self);
LSTMLayer* create_lstm_layer();

#endif  // LSTM_H
