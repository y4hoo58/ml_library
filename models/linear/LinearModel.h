
#ifndef ML_LIBRARY_LINEARMODEL_H
#define ML_LIBRARY_LINEARMODEL_H



#include "../Model.h"
#include <vector>

/*
 *
 * NOTES:
 * - Only supports L2 regularization currently.
 * - Only uses simple gradient descent currently.
 *
 * MAYBE LATER:
 * - L1 reg.
 * - SGD.
 * - OLS.
 */

class LinearModel:public Model {
public:
    int param_num;
    float learning_rate,alpha;
    std::vector<float> parameters;

    LinearModel(Data *,float,float);

protected:

    float error,grad;

    //Initialization of model parameters
    void init_params();
    void init_params(float);


    // Calculates the total gradient
    void calc_grad();

    // Calculates gradients for a row
    float calc_row_grad(Data *,int);

    // Updates the model parameters
    void update_params();

    void add_regularization_grad();

};


#endif
