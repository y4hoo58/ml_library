#include "../Model.h"
#include "Logistic.h"
#include <cmath>
#include <iostream>

Logistic::Logistic(Data *_data, float _learning_rate, float _alpha): LinearModel(_data, _learning_rate, _alpha){}


void Logistic::predict(){
    for(int i=0;i<data->row_num;i++){
        float _prediction = exp(parameters.at(0));
        for(int j = 1; j<param_num;j++){
            _prediction = _prediction * exp(parameters.at(j)*data->inputs->at(i).at(j-1));
        }
        _prediction = _prediction/(1+_prediction);
        data->predictions.at(i) = _prediction;
    }
}


float Logistic::calc_error(){
    float _error = metrics.binary_crossentropy(data->targets,&data->predictions);
    error = _error;
    return _error;
}


void Logistic::fit_model(int _epoch){
    init_params(1.0);
    for(int i=0;i<_epoch;i++){
        //predict();
        //calc_error();
        //calc_grad();
        //update_params();
    }
}







