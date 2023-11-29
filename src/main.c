// main.c
#include "dense.h"
#include "cnn.h"
#include "lstm.h"
#include "tensor.h"

int main() {
    // Create layers
    Dense* dense_layer = create_dense(3, 2);
    CNN* cnn_layer = create_cnn();
    LSTM* lstm_layer = create_lstm();

    // Connect layers
    add_layer((Layer*)cnn_layer, (Layer*)dense_layer);
    add_layer((Layer*)cnn_layer, (Layer*)lstm_layer);

    // Example input
    double input[3] = {1.0, 2.0, 3.0};

    // Perform forward pass for the entire network using DFS with input
    size_t input_dims[1] = {3};
    Tensor input_tensor = allocate_tensor(input_dims, DOUBLE);

    // Copy input data to the tensor
    for (size_t i = 0; i < input_dims[0]; ++i) {
        *((double*)input_tensor.data[0][i]) = input[i];
    }

    dfs_forward((Layer*)cnn_layer, &input_tensor);

    // Cleanup
    free(dense_layer);
    free(cnn_layer);
    free(lstm_layer);
    free_tensor(&input_tensor);

    return 0;
}
