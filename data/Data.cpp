
#include "Data.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <vector>
#include "../utility/Helpers.h"

using namespace std;

Data::Data() {

}

Data::Data(int _row_num,int _col_num,vector<vector<float>> *_inputs){
    // Copy vector
    train_x = _inputs;

    train_size = _row_num;
    feature_size = _col_num;

    vector<float> _vec(_row_num,0.0);
    train_pred = _vec;

}
Data::Data(int _row_num,int _col_num, vector<vector<float>> *_inputs,vector<float> *_targets){
    // Copy vectors
    train_x = _inputs;
    train_y = _targets;

    train_size = _row_num;
    feature_size = _col_num;

    vector<float> _vec(_row_num,0.0);
    train_pred = _vec;
}

Data::~Data() {
    delete train_x,train_y,test_x,test_y;
}

/*
 * DATA READING
 *
 *
 */

int Data::find_col_num(string _file_name){
    int _col_num = 0;

    string _line,_word;
    fstream _file(_file_name,ios::in);

    getline(_file,_line);
    stringstream str(_line);

    // Count the delimiters
    while(getline(str, _word, ',')){
        _col_num++;
    }
    return _col_num;
}

void Data::read_csv(string _file_name) {
    vector<vector<float>> _inputs;
    vector<float> _targets;

    int _col_num = find_col_num(_file_name);

    string _line,_word;
    fstream file(_file_name,ios::in);

    while(getline(file,_line)){
        stringstream str(_line);
        vector<float> _num2d;
        int _read_col_num = 0;
        while(getline(str, _word, ',')){
            _read_col_num++;
            double _num = std::stod(_word);
            if(_read_col_num ==_col_num ){
                _inputs.push_back(_num2d);
                _targets.push_back((float)_num);
            }else{
                _num2d.push_back((float)_num);
            }
        }
    }

    data_features = new vector<vector<float>>(_inputs);
    data_targets = new vector<float>(_targets);
}


/*
 * SPLITTING
 *
 *
 */
void Data::select_test_indexes(vector<int> *_indexes,vector<int> *_test_indexes,int _dataset_size,int _test_size){
    while(_test_indexes->size()<_test_size){
        int _rand_index=Helpers::random_generator(_dataset_size);
        if(_indexes->at(_rand_index) != -1){
            _test_indexes->push_back(_indexes->at(_rand_index));
            _indexes->at(_rand_index) =-1;
        }
    }
}

void Data::set_elements(vector<vector<float>> *_x,vector<float> *_y,vector<int> *_indexes){
    for(int i=0;i<_indexes->size();i++){
        _x->at(i)=data_features->at(_indexes->at(i));
        _y->at(i)=data_targets->at(_indexes->at(i));
    }
}

void Data::assign_train_indexes(vector<int> *_indexes,vector<int> *_train_indexes,int _dataset_size){
    for(int i=0;i<_dataset_size;i++){
        if(_indexes->at(i) != -1){
            _train_indexes->push_back(_indexes->at(i));
        }
    }
}

void Data::random_split(float _test_ratio) {

    // Set parameters for split operation
    int _dataset_size = static_cast<int>(data_features->size());
    int _train_size =static_cast<int>(static_cast<float>(_dataset_size)*(1-_test_ratio));
    int _test_size = _dataset_size-_train_size;

    // Start new vectors on the heap
    train_x = new vector<vector<float>>(_train_size);
    test_x = new vector<vector<float>>(_test_size);

    train_y = new vector<float>(_train_size);
    test_y = new vector<float>(_test_size);

    // Start a ranged vector to hold indexes
    vector<int> _indexes(_dataset_size,0);
    for(int i=0;i<_dataset_size;i++){
        _indexes.at(i)=i;
    }

    vector<int> _test_indexes,_train_indexes;

    // Selects test_indexes randomly
    select_test_indexes(&_indexes,&_test_indexes,_dataset_size,_test_size);

    // Assigns remaining indexes to "_train_indexes" vector
    assign_train_indexes(&_indexes,&_train_indexes,_dataset_size);

    // Copy elements
    set_elements(train_x,train_y,&_train_indexes);
    set_elements(test_x,test_y,&_test_indexes);

    train_size = static_cast<int>(train_x->size());
    feature_size=static_cast<int>(train_x->at(0).size());

    vector<float> _vec(train_size, 0.0);
    train_pred = _vec;

    vector<float> _vec2(test_size,0.0);
    test_pred = _vec2;
}

void Data::interpolated_split(float _test_ratio){}




/*
 * PRINTING
 *
 *
 */

void Data::print_inputs(int _max_rows){
    cout<<"[OUTP] Printing "<<_max_rows<<" rows of input data: "<<endl;

    for(int i=0;i<_max_rows;i++){

        for(int j = 0; j < feature_size; j++){
            cout << "[OUTP] Row number "<< i<< " : ";
            cout << train_x->at(i).at(j) << " ";
        }
        cout<<endl;
    }
    cout<<"_____________________________________"<<endl;
}

void Data::print_targets(int _max_rows){
    cout<<"[OUTP] Printing "<<_max_rows<<" rows of target data: "<<endl;

    for(int i=0;i<_max_rows;i++){
        cout << "[OUTP] Row number "<< i<< " : ";
        cout << train_y->at(i) << endl;
    }
    cout<<"_____________________________________"<<endl;
}

void Data::print_predictions(int _max_rows){
    cout<< "[OUTP] Printing predicted data: "<<endl;
    for(int i=0;i<_max_rows;i++){
        cout << "[OUTP] Row number "<< i<< " : ";
        cout << train_pred.at(i) << endl;
    }
    cout<<"_____________________________________"<<endl;
}




