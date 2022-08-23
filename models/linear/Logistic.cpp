#include "../Model.h"
#include "Logistic.h"
#include <cmath>
#include <iostream>

Logistic::Logistic(Data *_data, float _learning_rate, float _alpha): LinearModel(_data, _learning_rate, _alpha){}


void Logistic::predict(){
    for(int i=0;i<data->row_num;i++){
        float _exp_term = exp(parameters.at(0));
        for(int j=1;j<param_num;j++){
            _exp_term = _exp_term * (exp(parameters.at(j)*data->inputs->at(i).at(j-1)));
        }
        data->predictions.at(i) = _exp_term/(1+_exp_term);
    }
}


void Logistic::fit_model(int _epoch){
    init_params(1.0);
    for(int i=0;i<_epoch;i++){
        predict();
        calc_grad();
        add_regularization_grad();
        update_params();
        error = metrics.binary_crossentropy(data->targets,&data->predictions);
    }
}







