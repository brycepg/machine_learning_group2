CC=g++
CFLAGS=--std=c++11
INCLUDES=-I/usr/include/libxml2/
LDLIBS=-lmlpack -larmadillo
LDOPTIONS=-Wl,-rpath=/usr/local/lib
SOURCES=test.cpp 2d_1neighbor_nearest_neighbor.cpp nd_nearest_neighbor.cpp randcsv.cpp kmeans_graph/kmeans.cpp
EXECUTABLES=$(SOURCES:.cpp=.out)

all: $(EXECUTABLES)

test.out: test.cpp
	$(CC) $(CFLAGS) $(INCLUDES) test.cpp -o test.out $(LDLIBS) $(LDOPTIONS)

2d_1neighbor_nearest_neighbor.out: 2d_1neighbor_nearest_neighbor.cpp
	$(CC) $(CFLAGS) $(INCLUDES) 2d_1neighbor_nearest_neighbor.cpp -o 2d_1neighbor_nearest_neighbor.out $(LDLIBS) $(LDOPTIONS)

nd_nearest_neighbor.out: nd_nearest_neighbor.cpp
	$(CC) $(CFLAGS) $(INCLUDES) nd_nearest_neighbor.cpp -o nd_nearest_neighbor.out $(LDLIBS) $(LDOPTIONS)

randcsv.out: randcsv.cpp
	$(CC) $(CFLAGS) $(INCLUDES) randcsv.cpp -o randcsv.out $(LDLIBS) $(LDOPTIONS)

kmeans_graph/kmeans.out : kmeans_graph/kmeans.cpp
	$(CC) $(CFLAGS) $(INCLUDES) kmeans_graph/kmeans.cpp -o kmeans_graph/kmeans.out $(LDLIBS) $(LDOPTIONS)


clean:
	rm $(EXECUTABLES)
