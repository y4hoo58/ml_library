
#include <iostream>

#include "../../data/Data.h"
#include "../../models/linear/Reg.h"
#include "../../metrics/RegressionMetrics.h"

using namespace std;

int main(){

    /*
     * Set parameters
     */
    int _print_size = 5;
    int _epoch_num = 50;
    float _learning_rate = 0.01;
    float _alpha=0.5;
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
    Reg _my_reg(&_data,_learning_rate,_alpha);
    _my_reg.fit_model(_epoch_num);


    /*
     * Print model parameters
     */
    cout << "Model parameters are : "<<endl;
    for(int i=0;i<_my_reg.parameters.size();i++){
        cout << _my_reg.parameters.at(i)<<" ";
    }
    cout<<endl;

    /*
     * Output results
     */
    _data.print_targets(_print_size);
    _data.print_predictions(_print_size);


    /*
     * Model evaluation
     */
    float _r2_score = RegressionMetrics::r2_score(_data.train_y,&_data.train_pred);
    float _model_error = RegressionMetrics::mse(_data.train_y, &_data.train_pred);

    cout<<"R2 score is "<<_r2_score<<endl;
    cout << "MSE is "<<_model_error<<endl;


}





