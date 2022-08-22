
#ifndef ML_LIBRARY_LOGISTIC_H
#define ML_LIBRARY_LOGISTIC_H


#include "LinearModel.h"

class Logistic : public LinearModel{
public:

    Logistic(Data *, float, float);

    // Calculate the model error
    float calc_error();

    // Training loop
    void fit_model(int);

private:
    //Predict
    void predict();

    // Calculates the total gradient
    void calc_grad();

    // Calculates gradients for a row
    float calc_row_grad(Data *,int);

};


#endif //MY_ML_LOGISTIC_H
