
#ifndef ML_LIBRARY_LINEARMODEL_H
#define ML_LIBRARY_LINEARMODEL_H



#include "../Model.h"
#include <vector>

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

    // Updates the model parameters
    void update_params();

};


#endif
