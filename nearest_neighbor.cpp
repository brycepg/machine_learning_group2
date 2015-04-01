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
    int numNeighbors = 1;
    // If any arguments are supplied, use supplied text file for data
    if(argc > 1) {
        data::Load(argv[1], data, true);
    } else {
        data::Load("data.csv", data, true);
    }

    // If there is a third argument, use it for number of neighbors
    if(argc == 3)
        sscanf(argv[2], "%d", &numNeighbors);
    if(numNeighbors >= data.n_cols)
        numNeighbors = data.n_cols-1;

    NeighborSearch<NearestNeighborSort, EuclideanDistance> nn(data);

    arma::Mat<size_t> neighbors;
    arma::mat distances;

    nn.Search(numNeighbors, neighbors, distances);
    const int SIZE = data.n_rows;

    data::Save("neighbors.csv", neighbors, true);
    data::Save("distances.csv", distances, true);

    for(size_t cols = 0; cols < data.n_cols; cols++) {
        if(numNeighbors > 1) {
            cout << "The nearest neighbors of point (";
        } else {
            cout << "The nearest neighbor of point (";
        }
        for(int data_rows = 0; data_rows < data.n_rows; data_rows++) {
            cout << data(data_rows, cols);
            if(data_rows != data.n_rows - 1) {
                cout << ",";
            }
        }
        if(numNeighbors > 1) {
            cout << ") are ";
        } else {
            cout << ") is"; 
        }

        for(int neighbor_rows = 0; neighbor_rows < neighbors.n_rows; neighbor_rows++) {
            cout << "(";
            for(int data_rows = 0; data_rows < data.n_rows; data_rows++) {
                cout << data(data_rows, neighbors(neighbor_rows, cols));
                if(data_rows != data.n_rows - 1) {
                    cout << ",";
                }
            }
            cout << ") with distance " 
            << distances(neighbor_rows, cols) << ". ";
        }
        cout << "\n";

    }
    return 0;
}
