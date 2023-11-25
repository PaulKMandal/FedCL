// dense.c
#include "dense.h"
#include <stdio.h>

Dense* create_dense(size_t input_size, size_t output_size) {
    Dense* dense = (Dense*)malloc(sizeof(Dense));
    dense->base.forward = dense_forward;
    dense->base.next_layers = NULL;
    dense->base.prev_layers = NULL;
    dense->base.num_next_layers = 0;
    dense->base.num_prev_layers = 0;

    dense->input_size = input_size;
    dense->output_size = output_size;

    size_t weight_dims[2] = {input_size, output_size};
    size_t bias_dims[2] = {1, output_size};

    dense->weights = allocate_tensor(weight_dims, DOUBLE);
    dense->biases = allocate_tensor(bias_dims, DOUBLE);

    for (size_t i = 0; i < input_size; ++i) {
        for (size_t j = 0; j < output_size; ++j) {
            *((double*)dense->weights.data[0][i] + j) = 1.0;
        }
    }

    for (size_t i = 0; i < output_size; ++i) {
        *((double*)dense->biases.data[0][0] + i) = 0.0;
    }

    return dense;
}

Tensor dense_forward(Layer* self, Tensor* input) {
    Dense* dense = (Dense*)self;

    Tensor output = allocate_tensor(&(dense->output_size), DOUBLE);

    for (size_t i = 0; i < dense->output_size; ++i) {
        for (size_t j = 0; j < dense->input_size; ++j) {
            *((double*)output.data[0][0] + i) += *((double*)input->data[0][j]) * *((double*)dense->weights.data[0][j] + i);
        }
        *((double*)output.data[0][0] + i) += *((double*)dense->biases.data[0][0] + i);
    }

    printf("Forward pass for Dense layer\n");
    printf("Input: ");
    for (size_t i = 0; i < dense->input_size; ++i) {
        printf("%f ", *((double*)input->data[0][i]));
    }
    printf("\n");

    printf("Output: ");
    for (size_t i = 0; i < dense->output_size; ++i) {
        printf("%f ", *((double*)output.data[0][0] + i));
    }
    printf("\n");

    return output;
}
