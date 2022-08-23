
#include "Data.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <vector>

using namespace std;

Data::Data() {}

Data::Data(int _row_num,int _col_num,vector<vector<float>> *_inputs){
    // Copy vector
    inputs = _inputs;

    row_num = _row_num;
    col_num = _col_num;

    vector<float> _vec(_row_num,0.0);
    predictions = _vec;

}
Data::Data(int _row_num,int _col_num, vector<vector<float>> *_inputs,vector<float> *_targets){
    // Copy vectors
    inputs = _inputs;
    targets = _targets;

    row_num = _row_num;
    col_num = _col_num;

    vector<float> _vec(_row_num,0.0);
    predictions = _vec;
}

Data::~Data() {
    delete inputs;
    delete targets;
}


void Data::print_inputs(int _max_rows){
    cout<<"[OUTP] Printing "<<_max_rows<<" rows of input data: "<<endl;

    for(int i=0;i<_max_rows;i++){

        for(int j = 0;j<col_num;j++){
            cout << "[OUTP] Row number "<< i<< " : ";
            cout<<inputs->at(i).at(j)<<" ";
        }
        cout<<endl;
    }
    cout<<"_____________________________________"<<endl;
}

void Data::print_targets(int _max_rows){
    cout<<"[OUTP] Printing "<<_max_rows<<" rows of target data: "<<endl;

    for(int i=0;i<_max_rows;i++){
        cout << "[OUTP] Row number "<< i<< " : ";
        cout<<targets->at(i)<<endl;
    }
    cout<<"_____________________________________"<<endl;
}

void Data::print_predictions(int _max_rows){
    cout<< "[OUTP] Printing predicted data: "<<endl;
    for(int i=0;i<_max_rows;i++){
        cout << "[OUTP] Row number "<< i<< " : ";
        cout<<predictions.at(i)<<endl;
    }
    cout<<"_____________________________________"<<endl;
}

void Data::read_csv(string _file_name ) {
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

    inputs = new vector<vector<float>>(_inputs);
    targets = new vector<float>(_targets);
    predictions = *targets;

    row_num = inputs->size();
    col_num = inputs->at(0).size();
}

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





