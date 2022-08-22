
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../../data/Data.h"
#include "../../models/linear/Reg.h"

using namespace std;

void load_data(vector<vector<float>> *_inputs,vector<float> *_targets,string _file_name ){
    string _line,_word;
    fstream file(_file_name,ios::in);

    while(getline(file,_line)){

        stringstream str(_line);
        bool _is_input=true;
        while(getline(str, _word, ',')){
            double _num = std::stod(_word);
            if(_is_input){
                vector<float> _num2d;
                _num2d.push_back((float)_num);
                _inputs->push_back(_num2d);
                _is_input = false;

            }else{
                _targets->push_back((float)_num);
            }
        }
    }
}


int main(){

    /*
     * Load the data
     */
    vector<float> targets;
    vector<vector<float>> inputs;
    string _file_name = "/Users/yahya/Desktop/cpp_code/my_ml/test_datas/regression_data.csv";
    load_data(&inputs,&targets,_file_name);

    /*
     * Set parameters
     */
    int _row_num = (int)(inputs.size());
    int _col_num = 1;
    int _print_size = 5;
    int _epoch_num = 50;
    float _learning_rate = 0.1;

    /*
     * Instance initializations
     */
    Data _data(_row_num,_col_num,&inputs,&targets);
    Reg my_reg(&_data,0.01,0);

    /*
     * Train the model
     */
    my_reg.fit_model(_epoch_num);

    /*
     * Output results
     */
    _data.print_targets(_print_size);
    _data.print_predictions(_print_size);

    /*
     * Calculate model error
     */
    //float _model_error = my_reg.calc_error();
    float _model_error = my_reg.calc_error(_data.targets,&_data.predictions);
    cout << "Model error is "<<_model_error<<endl;


}





