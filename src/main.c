#include "cnn.h"
#include "dense.h"
#include "lstm.h"

// Example usage
int main() {
    // Create layers
    CNNLayer* cnn_layer = create_cnn_layer();
    FeedforwardLayer* ff_layer = create_feedforward_layer();
    LSTMLayer* lstm_layer = create_lstm_layer();

    // Connect layers
    add_next_layer((NeuralNetworkLayer*)cnn_layer, (NeuralNetworkLayer*)ff_layer);
    add_next_layer((NeuralNetworkLayer*)cnn_layer, (NeuralNetworkLayer*)lstm_layer);
    add_next_layer((NeuralNetworkLayer*)ff_layer, (NeuralNetworkLayer*)lstm_layer);

    // Perform forward pass for the entire network using DFS
    dfs_forward((NeuralNetworkLayer*)cnn_layer);

    // Cleanup
    free(cnn_layer);
    free(ff_layer);
    free(lstm_layer);

    return 0;
}
