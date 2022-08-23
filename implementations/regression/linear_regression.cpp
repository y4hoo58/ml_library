
#include <iostream>

#include "../../data/Data.h"
#include "../../models/linear/Reg.h"

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
    int _epoch_num = 50;
    float _learning_rate = 0.01;
    float _alpha=0.1;

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
     * Calculate model error
     */
    float _model_error = _my_reg.metrics.mse(_data.targets,&_data.predictions);
    cout << "Model error is "<<_model_error<<endl;


}





