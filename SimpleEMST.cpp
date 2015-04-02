#include <mlpack/methods/emst/dtb.hpp>
#include <mlpack/core.hpp> // ParseCommand
#include <iostream>

using namespace mlpack;
using namespace mlpack::metric;
using namespace mlpack::emst;
using namespace std;

int main(int argc, char *argv[]){
	if(argc != 2){
		cout << "This program needs one file input, and only one input!\n";
		return 1;
	}

	// Our dataset matrix, which is column-major
    	arma::mat data;
    	data::Load(argv[1], data, true);
	
	//set up variables
	arma::mat tree;
	DualTreeBoruvka<> dtb(data);	
	const int SIZE = data.n_rows;

	//do the calculations
	dtb.ComputeMST(tree);

	//prints the tree structure
	for(size_t i = 0, j = 0, l = 0; i < tree.n_cols; i++) {
    		cout << "Line " << i << " connects points " << tree(0, i);
		cout << "(" << data[tree(0 , i) * SIZE];
                for(j = tree(0 , i) * SIZE, l = 1; l < SIZE; l++)
                        cout << ", " << data[j+l];
 		cout << ") and point " << tree(1, i) << "(" << data[tree(1, i) * SIZE];
                for(j = tree(1 , i) * SIZE, l = 1; l < SIZE; l++)
                        cout << ", " << data[j+l];
		cout << ") and the line is " << tree(2, i) << " units long.\n";

	}	
	return 0;
}
