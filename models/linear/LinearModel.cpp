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

void LinearModel::update_params() {
    for(int i=0;i<param_num;i++){
        parameters.at(i) = parameters.at(i)-grad*(learning_rate);
    }
}