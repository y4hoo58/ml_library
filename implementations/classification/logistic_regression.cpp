
#include <iostream>

#include "../../data/Data.h"
#include "../../models/linear/Logistic.h"

using namespace std;


int main(){

    /*
     * Load the data
     */
    string _file_name = "/Users/yahya/Desktop/cpp_code/ml_library/implementations/classification/data/classification_data.csv";
    Data _data;
    _data.read_csv(_file_name);

    /*
     * Set parameters
     */
    int _print_size = 100;
    int _epoch_num = 50;
    float _learning_rate = 0.01;
    float _alpha=1;

    /*
     * Initialize model
     */
    Logistic _my_log(&_data,_learning_rate,_alpha);
    _my_log.fit_model(_epoch_num);

    /*
     * Output results
     */
    _data.print_targets(_print_size);
    _data.print_predictions(_print_size);

    /*
     * Calculate model error
     */

    float _model_error = _my_log.metrics.binary_crossentropy(_data.train_y, &_data.train_pred);
    cout << "Model error is "<<_model_error<<endl;


}



