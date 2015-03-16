#include <mlpack/core.hpp> // ParseCommand
#include <mlpack/methods/neighbor_search/neighbor_search.hpp> // NeighborSearch
#include <iostream>

using namespace mlpack;
using namespace mlpack::neighbor;
using namespace mlpack::metric;

int main(int argc, char** argv) {
    //CLI::ParseCommandLine(argc, argv);

    // Our dataset matrix, which is column-major
    arma::mat data;
    data::Load("data.csv", data, true);

    NeighborSearch<NearestNeighborSort, EuclideanDistance> nn(data);

    arma::Mat<size_t> neighbors;
    arma::mat distances;

    nn.Search(1, neighbors, distances);
    const int SIZE = data.n_rows    ;

    for(size_t i = 0, j = 0; i < neighbors.n_elem; i++, j+=2) {
    std::cout << "Nearest neighbor of point (" << data[j] << ", " << data[j+1] << ") at " << i << " is point "
        << neighbors[i] << " at (" << data[neighbors[i] * SIZE] << ", " << data[neighbors[i] * SIZE + 1] <<  ") and the distance is " << distances[i] << ".\n";
    }
}
