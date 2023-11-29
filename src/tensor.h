// tensor.h
#ifndef TENSOR_H
#define TENSOR_H

#include <stdlib.h>

typedef enum {
    FLOAT,
    DOUBLE,
    BOOL,
    // Add more types as needed
} TensorType;

typedef struct Tensor {
    size_t* dims;
    size_t num_dims;
    TensorType type;
    void*** data;
} Tensor;

Tensor create_tensor(size_t* dims, size_t n_dims, TensorType type, void*** data);
Tensor allocate_tensor(size_t* dims, TensorType type);
Tensor reshape_tensor(Tensor* tensor, size_t new_dimensions);
Tensor permute_tensor(Tensor* tensor);
void free_tensor(Tensor* tensor);

#endif // TENSOR_H
