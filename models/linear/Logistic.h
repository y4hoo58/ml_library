
#ifndef ML_LIBRARY_LOGISTIC_H
#define ML_LIBRARY_LOGISTIC_H


#include "LinearModel.h"

class Logistic : public LinearModel{
public:

    float accuracy;

    Logistic(Data *, float, float);

    // Training loop
    void fit_model(int);

private:
    //Predict
    void predict();
};


#endif //MY_ML_LOGISTIC_H
