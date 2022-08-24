#include "LinearModel.h"

LinearModel::LinearModel(Data *_data,float _learning_rate,float _alpha): Model(_data){
    alpha=_alpha;
    learning_rate = _learning_rate;
    param_num = _data->feature_size + 1;
}


void LinearModel::init_params(){
    for(int i=0;i<param_num;i++){
        float _rand_num = Helpers::random_generator();
        parameters.push_back(_rand_num);
    }
}

void LinearModel::init_params(float _abs_max=1){
    for(int i=0;i<param_num;i++){
        float _rand_num = Helpers::random_generator(_abs_max);
        parameters.push_back(_rand_num);
    }
}

void LinearModel::calc_grad(){
    float _grad = 0;
    for(int i=0;i<data->train_size; i++){
        _grad = _grad+calc_row_grad(data,i);
    }
    grad = _grad / (float)data->train_size;
}


float LinearModel::calc_row_grad(Data *data, int _row_num) {
    float _grad=0;
    _grad = _grad + ((data->train_pred.at(_row_num) - data->train_y->at(_row_num)) * 1);
    for(int i=0;i<data->feature_size; i++){
        _grad = _grad + ((data->train_pred.at(_row_num) - data->train_y->at(_row_num)) * data->train_x->at(_row_num).at(i));
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