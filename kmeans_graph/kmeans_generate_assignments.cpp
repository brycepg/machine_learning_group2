#include <mlpack/methods/kmeans/kmeans.hpp>
#include <iostream>
#include <fstream>
#include <string>

// Generates a csv file based on input csv file and how many clusters are
//  specified. Run by ./kmeans.cpp [cluster_amt] [input_file.csv] 
//  where [input_file.csv] is a filename without quotes
//  [cluster_amt] is an unsigned integer

int main(int argc, char** argv) {
    arma::mat data;


    // Default cluster amount
    size_t clusters = 3;

    if(argc > 1) {
        clusters = atoi(argv[1]);
    }

    // Default filename
    std::string infile = "data.example.csv";

    if(argc > 2) {
        infile = argv[2];
    }
    mlpack::data::Load(infile, data);
    

    arma::Col<size_t> assignments;
    arma::mat centroids;
    mlpack::kmeans::KMeans<> k;
    k.Cluster(data, clusters, assignments, centroids);

    // Output for stdout
    for(int cols = 0; cols < data.n_cols; cols++) {
        std::cout << cols << " (";
        for(int rows = 0; rows < data.n_rows; rows++) {
            std::cout << data(rows, cols);
            if(rows != data.n_rows-1) {
                std::cout << ",";
            }
        }
        std::cout << ")\n";
    }
    
    // Output x,y,centroid assignment for gnuplot
    std::ofstream output("data_n_assignments.csv");
    for(int cols = 0; cols < data.n_cols; cols++) {
        for(int rows = 0; rows < data.n_rows; rows++) {
            output << data(rows, cols);
            if(rows != data.n_rows-1) {
                output << ",";
            }
        }
        output << "," << assignments[cols] << "\n";
    }

    // Data::Save uses scientific notation which doesn't work for gnuplot[
    // So output centroids as their double type
    std::ofstream centroids_file("centroids.csv");
    for(int cols = 0; cols < centroids.n_cols; cols++) {
        for(int rows = 0; rows < centroids.n_rows; rows++) {
            centroids_file << centroids(rows, cols);
            if(rows != centroids.n_rows - 1) {
                centroids_file << ",";
            }
        }
        centroids_file << "\n";
    }

    centroids_file.close();
    output.close();

    return 0;
}
