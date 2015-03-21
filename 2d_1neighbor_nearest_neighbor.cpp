#include <mlpack/core.hpp>
#include <mlpack/methods/neighbor_search/neighbor_search.hpp> // NeighborSearch
#include <iostream>

// There are two libraries being used
// thing with the arma:: namespace are from the armadillo library and can be
// referenced here ( http://arma.sourceforge.net/docs.html )

// Things in the mlpack namespace build upon doing operations upon these
// Matrices created with the armadillo library

int main() {
    // Dataset matrix loaded from '2d_data.csv'
    arma::mat data;
    mlpack::data::Load("2d_data.csv", data, true); // "2d_data.csv" the comma separated file from which the matrix is loaded from. The matrix is stored with each line being a colum. data is referenced in the Load function and the matrix will be loaded into that mat object. true means this function failes terminated the program if something goes wrong

    mlpack::neighbor::NeighborSearch<mlpack::neighbor::NearestNeighborSort, mlpack::metric::EuclideanDistance> nn(data); // create an object called nn of class NeighborSearch which preforms the nearest neighbor sort and uses euclidean distance(fractional values). The data object is stored in nn

    arma::Mat<size_t> neighbors; // Create a mat object to recieve neighborsfrom search
    arma::mat distances; // Create a mat object to recieve distances relative to each data point

    nn.Search(1, neighbors, distances); // do a nearest neighbor search on the data stored in the mat object 'data'. Only look for the 1st nearest neighbor. Store the nearest neighbor index in the neigbhors mat, and store the distances corresponding to the data matrix in the distances mat
    const int SIZE = data.n_rows;

    // access the matrices and extract the nearest neighbor and distance assuming a 2d array
    // Matrices are squashed into a 1d array
    for(size_t i = 0, j = 0; i < neighbors.n_elem; i++, j+=2) {
        std::cout 
        << "Nearest neighbor of point (" 
            << data[j] << ", " << data[j+1] 
        << ") at " << i 
        << " is point " << neighbors[i] 
        << " at (" 
        << data[neighbors[i] * SIZE] << ", " << data[neighbors[i] * SIZE + 1] 
        <<  ") and the distance is " << distances[i] << ".\n";
    }

    // Serialize matrices to files with comma
    mlpack::data::Save("neighbors.csv", neighbors, true);
    mlpack::data::Save("distances.csv", distances, true);
}
