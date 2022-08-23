#include "LinearModel.h"

LinearModel::LinearModel(Data *_data,float _learning_rate,float _alpha): Model(_data){
    alpha=_alpha;
    learning_rate = _learning_rate;
    param_num = _data->col_num+1;
}


void LinearModel::init_params(){
    for(int i=0;i<param_num;i++){
        float _rand_num = helpers.random_generator();
        parameters.push_back(_rand_num);
    }
}

void LinearModel::init_params(float _abs_max=1){
    for(int i=0;i<param_num;i++){
        float _rand_num = helpers.random_generator(_abs_max);
        parameters.push_back(_rand_num);
    }
}

void LinearModel::calc_grad(){
    float _grad = 0;
    for(int i=0;i<data->row_num;i++){
        _grad = _grad+calc_row_grad(data,i);
    }
    grad = _grad / (float)data->row_num;
}


float LinearModel::calc_row_grad(Data *data, int _row_num) {
    float _grad=0;
    _grad = _grad + ((data->predictions.at(_row_num)-data->targets->at(_row_num))*1);
    for(int i=0;i<data->col_num;i++){
        _grad = _grad + ((data->predictions.at(_row_num)-data->targets->at(_row_num))*data->inputs->at(_row_num).at(i));
    }
    return _grad;
}

void LinearModel::add_regularization_grad() {
    float _param_sum =0;
    for(int i=0;i<param_num;i++){
        _param_sum = _param_sum + (parameters.at(i));
    }
    _param_sum = 2*alpha*_param_sum;
    grad = grad+_param_sum;
}


void LinearModel::update_params() {
    for(int i=0;i<param_num;i++){
        parameters.at(i) = parameters.at(i)-grad*(learning_rate);
    }
}