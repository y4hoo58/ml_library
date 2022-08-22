
#ifndef ML_LIBRARY_REG_H
#define ML_LIBRARY_REG_H

#include "LinearModel.h"
#include <vector>

class Reg : public LinearModel  {
public :


    Reg(Data *, float, float);

    // Calculate the model error
    float calc_error(std::vector<float> *,std::vector<float> *);

    //Training loop
    void fit_model(int);

    /*
     * TODO : Implement later
     */
    std::vector<float> predict(Data *data);
    std::vector<float> predict(std::vector<float> *);

private:
    // Predict
    void predict();

    // Calculates the total gradient
    void calc_grad();

    // Calculates gradients for a row
    float calc_row_grad(Data *,int);
};


#endif //MY_ML_REG_H
