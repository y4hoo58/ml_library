#include "../Model.h"
#include "Reg.h"
#include <cmath>
#include <iostream>

using namespace std;

Reg::Reg(Data *_data, float _learning_rate, float _alpha ): LinearModel(_data, _learning_rate, _alpha){
}

void Reg::predict(){
    for(int i=0;i<data->train_size; i++){
        cout<<i<<" : ";
        float _prediction = parameters.at(0);
        for(int j = 1; j<param_num;j++){
            cout<<j<<" : ";
            _prediction = _prediction + (parameters.at(j) * data->train_x->at(i).at(j - 1));
        }
        cout<<"x";
        data->train_pred.at(i) = _prediction;
        cout<<"y"<<endl;
    }
}


void Reg::fit_model(int _epoch){
    cout<<2.1<<endl;
    init_params(1.0);
    for(int i=0;i<_epoch;i++){
        cout<<2.2<<endl;
        predict();
        cout<<2.3<<endl;
        calc_grad();
        cout<<2.4<<endl;
        add_regularization_grad();
        cout<<2.5<<endl;
        update_params();
        cout<<2.6<<endl;
        error = metrics.mse(data->train_y, &data->train_pred);
    }
}







