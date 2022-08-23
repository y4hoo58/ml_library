#include "../Model.h"
#include "Reg.h"
#include <cmath>


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


void Reg::fit_model(int _epoch){
    init_params(1.0);
    for(int i=0;i<_epoch;i++){
        predict();
        calc_grad();
        add_regularization_grad();
        update_params();
        error = metrics.mse(data->targets,&data->predictions);
    }
}







