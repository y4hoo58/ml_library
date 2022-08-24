
#include <iostream>

#include "../../data/Data.h"
#include "../../models/kmeans/Kmeans.h"

using namespace std;

int main(){
    /*
     * Load data
     */
    string _file_name = "/Users/yahya/Desktop/cpp_code/ml_library/implementations/clustering/data/five_neighbors.csv";
    Data _data;
    _data.read_csv(_file_name);

    /*
     * Set parameters
     */

    int _neighbor_num = 2;
    int _n_init = 1;
    int _max_iter = 5;

    /*
     * Initialize model
     */
    Kmeans _kmeans(&_data,_neighbor_num,_n_init,_max_iter);
    _kmeans.fit();

    float _rand_index= _kmeans.metrics.rand_index(_data.train_y, &_kmeans.clusters);
    cout<<"Rand index is "<<_rand_index<<endl;

    return 0;
}