#include <mlpack/methods/emst/dtb.hpp>
#include <mlpack/core.hpp> // ParseCommand
#include <iostream>

using namespace mlpack;
using namespace mlpack::metric;
using namespace mlpack::emst;
using namespace std;

int main(int argc, char *argv[]){
	// Our dataset matrix, which is column-major
    	arma::mat data;
    if(argc == 2) {
    	data::Load(argv[1], data, true);
    } else {
    	data::Load("data.csv", data, true);
    }

	
	//set up variables
	arma::mat tree;
	DualTreeBoruvka<> dtb(data);	
	const int SIZE = data.n_rows;

	//do the calculations
	dtb.ComputeMST(tree);

    data::Save("emst_tree.csv", tree);
    
    for(size_t tree_cols = 0; tree_cols < tree.n_cols; tree_cols++) {
        cout << "point (";
        for(size_t data_rows = 0; data_rows < data.n_rows; data_rows++){
            cout << data(data_rows, tree(0,tree_cols));
            if(data_rows != data.n_rows - 1) {
                cout << ", ";
            }
        }
        cout << ") connects to " << "(" ;
        for(size_t data_rows = 0; data_rows < data.n_rows; data_rows++){
            cout << data(data_rows, tree(1,tree_cols));
            if(data_rows != data.n_rows - 1) {
                cout << ", ";
            }
        }
        cout << ") with a length of " << tree(2, tree_cols) << "\n";
    }
	return 0;
}
