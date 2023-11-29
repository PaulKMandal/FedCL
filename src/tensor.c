// tensor.c
#include "tensor.h"
#include <stdio.h>

/*Tensor create_tensor(size_t* dims, size_t n_dims, TensorType type, void*** data) {
    // Implement create tensor
}
*/

Tensor allocate_tensor(size_t* dims, TensorType type) {
    Tensor tensor;
    size_t num_dims = sizeof(dims) / sizeof(dims[0]);
    tensor.dims = (size_t*)malloc(num_dims * sizeof(size_t));
    tensor.num_dims = num_dims;
    tensor.type = type;

    for (size_t i = 0; i < num_dims; ++i) {
        tensor.dims[i] = dims[i];
    }

    tensor.data = (void***)malloc(num_dims * sizeof(void**));
    for (size_t i = 0; i < num_dims; ++i) {
        tensor.data[i] = (void**)malloc(dims[i] * sizeof(void*));
        for (size_t j = 0; j < dims[i]; ++j) {
            switch (type) {
                case FLOAT:
                    tensor.data[i][j] = (float*)malloc(sizeof(float));
                    break;
                case DOUBLE:
                    tensor.data[i][j] = (double*)malloc(sizeof(double));
                    break;
                case BOOL:
                    tensor.data[i][j] = (int*)malloc(sizeof(int));
                    break;
                // Add more cases as needed
            }
        }
    }

    return tensor;
}

/*Tensor reshape_tensor(Tensor* tensor, size_t new_dimensions) {
    // Implement reshape tensor
}
*/

/*
Tensor permute_tensor(Tensor* tensor) {
  // Implement reshape tensor
}
*/

void free_tensor(Tensor* tensor) {
    for (size_t i = 0; i < tensor->num_dims; ++i) {
        for (size_t j = 0; j < tensor->dims[i]; ++j) {
            free(tensor->data[i][j]);
        }
        free(tensor->data[i]);
    }
    free(tensor->data);
    free(tensor->dims);
}
