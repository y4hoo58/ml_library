#include "../Model.h"
#include "Reg.h"


Reg::Reg(Data *_data, float _learning_rate, float _alpha ): LinearModel(_data, _learning_rate, _alpha){

}

void Reg::predict(){
    for(int i=0;i<data->row_num;i++){
        float _prediction = parameters.at(0);
        for(int j = 1; j<param_num;j++){
            _prediction = _prediction + (parameters.at(j) * data->inputs->at(i).at(j-1));
        }
        data->predictions.at(i) = _prediction;
    }
}


float Reg::calc_error(vector<float> *_targets, vector<float> *_predictions) {
    return metrics.mse(_targets,_predictions);
}

void Reg::calc_grad(){
    float _grad = 0;
    for(int i=0;i<data->row_num;i++){
        _grad = _grad+calc_row_grad(data,i);
    }
    grad = _grad / (float)data->row_num;
}


float Reg::calc_row_grad(Data *data, int _row_num) {
    float _grad=0;
    _grad = _grad + ((data->predictions.at(_row_num)-data->targets->at(_row_num))*1);
    for(int i=0;i<data->col_num;i++){
        _grad = _grad + ((data->predictions.at(_row_num)-data->targets->at(_row_num))*data->inputs->at(_row_num).at(i));
    }
    return _grad;
}

void Reg::fit_model(int _epoch){
    init_params(1.0);
    for(int i=0;i<_epoch;i++){
        predict();
        calc_grad();
        update_params();
    }
}







