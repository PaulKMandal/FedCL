// dense.c
#include <stdio.h>
#include <stdlib.h>
#include "dense.h"

Dense* create_dense(size_t input_size, size_t output_size) {
    Dense* dense = (Dense*)malloc(sizeof(Dense));
    dense->base.forward = dense_forward;
    dense->base.next_layers = NULL;
    dense->base.prev_layers = NULL;
    dense->base.num_next_layers = 0;
    dense->base.num_prev_layers = 0;

    dense->input_size = input_size;
    dense->output_size = output_size;

    dense->weights = (double**)malloc(input_size * sizeof(double*));
    for (size_t i = 0; i < input_size; ++i) {
        dense->weights[i] = (double*)malloc(output_size * sizeof(double));
        for (size_t j = 0; j < output_size; ++j) {
            dense->weights[i][j] = 1.0;
        }
    }

    dense->biases = (double*)malloc(output_size * sizeof(double));
    for (size_t i = 0; i < output_size; ++i) {
        dense->biases[i] = 0.0;
    }

    return dense;
}

void free_dense(Dense* dense) {
    for (size_t i = 0; i < dense->input_size; ++i) {
        free(dense->weights[i]);
    }
    free(dense->weights);
    free(dense->biases);
    free(dense);
}

void dense_forward(Layer* self, double* input) {
    Dense* dense = (Dense*)self;

    double* output = (double*)malloc(dense->output_size * sizeof(double));

    for (size_t i = 0; i < dense->output_size; ++i) {
        output[i] = dense->biases[i];
        for (size_t j = 0; j < dense->input_size; ++j) {
            output[i] += input[j] * dense->weights[j][i];
        }
    }

    printf("Forward pass for Dense layer\n");
    printf("Input: ");
    for (size_t i = 0; i < dense->input_size; ++i) {
        printf("%f ", input[i]);
    }
    printf("\n");

    printf("Output: ");
    for (size_t i = 0; i < dense->output_size; ++i) {
        printf("%f ", output[i]);
    }
    printf("\n");

    free(output);
}
