
#include <iostream>

#include "../../data/Data.h"
#include "../../models/knn/Knn.h"
#include "../../metrics/RegressionMetrics.h"

using namespace std;


int main(){
    /*
     * Set parameters
     */
    int _print_size = 5;
    int _k_neighbors = 10;
    float _test_ratio = 0.2;

    /*
     * Load the data
     */
    string _file_name = "/Users/yahya/Desktop/cpp_code/ml_library/implementations/regression/data/regression_data.csv";
    Data _data;
    _data.read_csv(_file_name);
    _data.random_split(_test_ratio);


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
    float _r2_score = RegressionMetrics::r2_score(_data.train_y,&_data.train_pred);
    float _model_error = RegressionMetrics::mse(_data.train_y, &_data.train_pred);

    cout<<"R2 score is "<<_r2_score<<endl;
    cout << "MSE is "<<_model_error<<endl;

}





