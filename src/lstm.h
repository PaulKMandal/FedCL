#ifndef LSTM_H
#define LSTM_H

#include "layer.h"

// Define the LSTM layer structure
typedef struct {
    Layer base;
    // Add LSTM-specific fields here
} LSTM;

void lstm_forward(struct Layer* self);
LSTM* create_lstm();

#endif  // LSTM_H
