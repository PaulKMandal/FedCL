// lstm.h
#ifndef LSTM_H
#define LSTM_H

#include "layer.h"

typedef struct {
    Layer base;
} LSTM;

LSTM* create_lstm(void);
void lstm_forward(Layer* self, double* input);

#endif  // LSTM_H
