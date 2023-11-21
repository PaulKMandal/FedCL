#include "layer.h"
#include "cnn.h"
#include "dense.h"
#include "lstm.h"

int main() {
    // Create layers
    CNN* cnn_layer = create_cnn();
    Dense* dense_layer = create_dense();
    LSTM* lstm_layer = create_lstm();

    // Connect layers
    add_next_layer((Layer*)cnn_layer, (Layer*)dense_layer);
    add_next_layer((Layer*)cnn_layer, (Layer*)lstm_layer);
    add_next_layer((Layer*)dense_layer, (Layer*)lstm_layer);

    // Perform forward pass for the entire network using DFS
    dfs_forward((Layer*)cnn_layer);

    // Cleanup
    free(cnn_layer);
    free(dense_layer);
    free(lstm_layer);

    return 0;
}
