#include <mlpack/core.hpp> // ParseCommand
#include <mlpack/methods/neighbor_search/neighbor_search.hpp> // NeighborSearch
#include <iostream>

using namespace mlpack;
using namespace mlpack::neighbor;
using namespace mlpack::metric;
using namespace std;

int main(int argc, char** argv) {
    // Our dataset matrix, which is column-major
    arma::mat data;
    data::Load(argv[1], data, true);

    NeighborSearch<NearestNeighborSort, EuclideanDistance> nn(data);

    arma::Mat<size_t> neighbors;
    arma::mat distances;

    int numNeighbors = 1;
    if(argc == 3)
        sscanf(argv[2], "%d", &numNeighbors);
    if(numNeighbors >= data.n_cols)
        numNeighbors = data.n_cols-1;
    
    nn.Search(numNeighbors, neighbors, distances);
    const int SIZE = data.n_rows;

    for(size_t i = 0, j = 0, k = 0; i < neighbors.n_elem; i+=numNeighbors, j+=SIZE) {
        cout << "Nearest neighbor(s) of point ("  << data[j];
        for(k = 1; k < SIZE; k++)
            cout << ", " << data[j+k];
        cout  << "), is point(s)";
        for(int h = 0; h < numNeighbors*SIZE; h+=SIZE){
            if (h!=0)
                cout << ", and ";
            cout << " (" << data[neighbors[i] * SIZE + h];
            for(k = 1; k < SIZE; k++)
                cout << ", " << data[neighbors[i] * SIZE + h + k];
            cout <<  ") with distance " << distances[i];
        }
        cout <<".\n";
    }

    data::Save("neighbors.csv", neighbors, true);
    data::Save("distances.csv", distances, true);
}
