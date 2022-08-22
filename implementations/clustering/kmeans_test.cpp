
#include <iostream>

#include "../../data/Data.h"
#include "../../models/kmeans/Kmeans.h"

using namespace std;

int main(){
    /*
     * Load data
     */
    string _file_name = "/Users/yahya/Desktop/cpp_code/ml_library/implementations/clustering/data/two_neighbors.csv";
    Data data;
    data.read_csv(_file_name);

    /*
     * Set parameters
     */

    int _neighbor_num = 5;

    Kmeans kmeans(&data,_neighbor_num);

    data.read_csv(_file_name);
    kmeans.fit();

    float _rand_index= kmeans.metrics.rand_index(data.targets,&kmeans.clusters);
    cout<<"Rand index is "<<_rand_index<<endl;

    return 0;
}