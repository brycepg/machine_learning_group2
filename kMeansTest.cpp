#include <mlpack/methods/kmeans/kmeans.hpp>
#include <mlpack/core.hpp> // ParseCommand
#include <iostream>

using namespace mlpack;
using namespace mlpack::metric;
using namespace mlpack::kmeans;
using namespace std;

int main(){
	
	// Our dataset matrix, which is column-major
    	arma::mat data;
    	data::Load("data.csv", data, true);
	
	// Get the number of clusters, and make sure it is more than 0 and less than the number of entities in the data
	size_t clusters = 0;
	while(clusters <= 0 || clusters >= data.n_cols){
		cout << "Enter the number of clusters you want to use: ";
		cin >> clusters;	
	}

	// The assignments will be stored in this vector.
	arma::Col<size_t> assignments;
	// The centroids will be stored in this matrix.
	arma::mat centroids;

	KMeans<> k(500, 1); //allow for 500 iterations and 1 overclusters
	const int SIZE = data.n_rows;

	//do the calculations
	k.Cluster(data, clusters, assignments, centroids);

	//prints what data point belong to what cluster
	for(size_t i = 0, j = 0, l = 0; i < assignments.n_elem; i++, j+=SIZE) {
		cout << "Point " << i << "(" << data[j];
		for(l = 1; l < SIZE; l++)
            		cout << ", " << data[j+l];
		cout << ") belongs to cluster " << assignments[i] << ".\n";
    	}	

	//prints the centroids
	for(size_t i = 0, j = 0, l = 0; j < centroids.n_elem; i++, j+=SIZE) {
    		cout << "Centroid " << i << " is at (" << centroids[j];
    		for(l = 1; l < SIZE; l++)
                        cout << ", " << centroids[j+l];
		cout << ")\n";

	}	
	return 0;
}
