#kmeans.cpp

Note all commands are from the root directory of this repository

From a set of data, based on the number of centroids as input, 
calculates which points in the data belong to which centroids and where 
those centroids are

`./kmeans.out`
reads from data.csv

`./kmeans.out <filename>`
reads the data from `<filename>`



#EMST.cpp

Generate a euclidean minimum spanning tree based on sets of points as input. Outputs each edge and its length corresponding to two points

to compile
`./mlcompile EMST.cpp`

`./EMST.out`
reads from data.csv

`./EMST.out <filename>`
reads the data from <filename>

#nearest_neighbor.cpp

to compile
`./mlcompile nearest_neighbor.cpp`

Calculate the nearest n neighbors of a set of data points and determine their distances.

`./nearest_neigbhor.out`
calculates the nearest neighbor and distances of the data in data.csv

`./nearest_neigbhor.out <filename>`
calculates the nearest neighbor and distances of the data in <filename>

`./nearest_neigbhor.out <filename> <n>`
calculates the nearest neighbor(s) of amount <n> and distances of the data in <filename>


#kmeans_graph/

Generates a graph of colorized 2d data points, differing for each centroid.

## kmeans_generate_assignments

to compile
`./mlcompile kmeans_graph/kmeans_generate_assignments.cpp`

Using input data, generate a file with data points and their corresponding centroid assignment as well as a file for centroid location.
Output is `kmeans_graph/data_n_assignments.csv` and `kmeans_graph/centroids.csv`

compile kmeans_graph/kmeans_generate_assignments.cpp

`./kmeans_graph/kmeans_generate_assignments.out`
use data.example.csv as input for 3 centroids

`./kmeans_graph/kmeans_generate_assignments.out <n>`
Use data.example.csv as input for <n> centroids

`./kmeans_graph/kmeans_generate_assignments.out <n> <filename>`
Use <filename> as input for <n> centroids

## plot.py

Uses python3, python3-matplotlib, and python3-numpy to generate a graph from files kmeans_graph/data_n_assignments.csv and kmeans_graph/centroids.csv

`python3 plot.py`
should display a graph is kmeans_generate_assignments is compiled and ran with valid data

### Example graph
[!kmeans graph](https://github.com/brycepg/machine_learning_group2/blob/master/kmeans_graph/matplotlib_example_graph.png?raw=true)
