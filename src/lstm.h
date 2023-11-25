// lstm.h
#ifndef LSTM_H
#define LSTM_H

#include "layer.h"

typedef struct {
    Layer base;
} LSTM;

LSTM* create_lstm();
Tensor lstm_forward(Layer* self, Tensor* input);

#endif // LSTM_H
