
#include <iostream>

#include "../../data/Data.h"
#include "../../models/knn/Knn.h"

using namespace std;


int main(){

    /*
     * Load the data
     */
    string _file_name = "/Users/yahya/Desktop/cpp_code/ml_library/implementations/regression/data/regression_data.csv";
    Data _data;
    _data.read_csv(_file_name);

    /*
     * Set parameters
     */
    int _print_size = 5;
    int _k_neighbors = 10;

    /*
     * Initialize model
     */
    Knn knn(&_data,_k_neighbors);

    knn.fit();
    knn.regression();

    /*
     * Output results
     */
    _data.print_targets(_print_size);
    _data.print_predictions(_print_size);


    /*
     * Calculate model error
     */
    float _model_error = knn.metrics.mse(_data.targets,&_data.predictions);
    cout << "Model error is "<<_model_error<<endl;


}





