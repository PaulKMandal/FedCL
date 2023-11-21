CC = gcc
CFLAGS = -Wall

all: neural_network

neural_network: layer.o cnn.o dense.o lstm.o main.o
	$(CC) $^ -o $@

layer.o: layer.c layer.h
	$(CC) $(CFLAGS) -c $< -o $@

cnn.o: cnn.c cnn.h layer.h
	$(CC) $(CFLAGS) -c $< -o $@

dense.o: dense.c dense.h layer.h
	$(CC) $(CFLAGS) -c $< -o $@

lstm.o: lstm.c lstm.h layer.h
	$(CC) $(CFLAGS) -c $< -o $@

main.o: main.c layer.h cnn.h dense.h lstm.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o neural_network
