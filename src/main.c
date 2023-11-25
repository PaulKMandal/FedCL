// main.c
#include <stdlib.h>
#include "dense.h"
#include "cnn.h"
#include "lstm.h"

int main() {
    // Create layers
    Dense* dense_layer = create_dense(3, 2); // Example: Input size = 3, Output size = 2
    CNN* cnn_layer = create_cnn();
    LSTM* lstm_layer = create_lstm();

    // Connect layers
    add_layer((Layer*)cnn_layer, (Layer*)dense_layer);
    add_layer((Layer*)cnn_layer, (Layer*)lstm_layer);

    // Example input
    double input[3] = {1.0, 2.0, 3.0};

    // Perform forward pass for the entire network using DFS with input
    dfs_forward((Layer*)cnn_layer, input);

    // Cleanup
    free_dense(dense_layer);
    free(cnn_layer);
    free(lstm_layer);

    return 0;
}
