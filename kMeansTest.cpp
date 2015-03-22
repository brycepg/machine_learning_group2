#include <mlpack/methods/kmeans/kmeans.hpp>
#include <mlpack/core.hpp> // ParseCommand
#include <iostream>

using namespace mlpack;
using namespace mlpack::metric;
using namespace mlpack::kmeans;

int main(){
	
	// Our dataset matrix, which is column-major
    	arma::mat data;
    	data::Load("data.csv", data, true);
	
	// Get the number of clusters, and make sure it is more than 0 and less than the number of entities in the data
	size_t clusters = 0;
	while(clusters <= 0 || clusters >= data.n_cols){
		std::cout << "Enter the number of clusters you want to use: ";
		std::cin >> clusters;	
	}

	// The assignments will be stored in this vector.
	arma::Col<size_t> assignments;
	// The centroids will be stored in this matrix.
	arma::mat centroids;

	KMeans<> k(500, 1); //allow for 500 iterations and 1 overclusters
	const int SIZE = data.n_rows;

	k.Cluster(data, clusters, assignments, centroids);

	for(size_t i = 0, j = 0; i < assignments.n_elem; i++, j+=3) {
	    std::cout << "Point " << i << "(" << data[j] << ", " << data[j+1] << ", " << data[j+2] <<  ") belongs to cluster " << assignments[i] << ".\n";
    }	

	for(size_t i = 0, j = 0; j < centroids.n_elem; i++, j+=3) {
    		std::cout << "Centroid " << i << " is at (" << centroids[j] << ", " << centroids[j +1] << ", " << centroids[j + 2] << ")\n";
    	}	
	return 0;
}
