#include "../Model.h"
#include "Reg.h"
#include "../../metrics/RegressionMetrics.h"


using namespace std;

Reg::Reg(Data *_data, float _learning_rate, float _alpha ): LinearModel(_data, _learning_rate, _alpha){
}

void Reg::predict(){
    for(int i=0;i<data->train_size; i++){
        float _prediction = parameters.at(0);
        for(int j = 1; j<param_num;j++){
            _prediction = _prediction + (parameters.at(j) * data->train_x->at(i).at(j - 1));
        }
        data->train_pred.at(i) = _prediction;
    }
}


void Reg::fit_model(int _epoch){
    init_params(1.0);
    for(int i=0;i<_epoch;i++){
        predict();
        calc_grad();
        add_regularization_grad();
        update_params();
        error = RegressionMetrics::mse(data->train_y, &data->train_pred);
        r2_score = RegressionMetrics::r2_score(data->train_y, &data->train_pred);
    }
}







