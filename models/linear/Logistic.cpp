#include "../Model.h"
#include "Logistic.h"
#include "../../metrics/ClassificationMetrics.h"

#include <cmath>
#include <iostream>

Logistic::Logistic(Data *_data, float _learning_rate, float _alpha): LinearModel(_data, _learning_rate, _alpha){}


void Logistic::predict(){
    for(int i=0;i<data->train_size; i++){
        float _exp_term = exp(parameters.at(0));
        for(int j=1;j<param_num;j++){
            _exp_term = _exp_term * (exp(parameters.at(j)*data->train_x->at(i).at(j - 1)));
        }
        data->train_pred.at(i) = _exp_term / (1 + _exp_term);
    }
}


void Logistic::fit_model(int _epoch){
    init_params(1.0);
    for(int i=0;i<_epoch;i++){
        predict();
        calc_grad();
        add_regularization_grad();
        update_params();
        error = ClassificationMetrics::binary_crossentropy(data->train_y, &data->train_pred);
    }
}







