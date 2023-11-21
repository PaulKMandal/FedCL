#ifndef LSTM_H
#define LSTM_H

#include "layer.h"

typedef struct {
    Layer base;
    // Add LSTM-specific fields here
} LSTM;

LSTM* create_lstm();

#endif // LSTM_H
