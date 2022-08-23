
#ifndef ML_LIBRARY_REG_H
#define ML_LIBRARY_REG_H

#include "LinearModel.h"
#include <vector>

class Reg : public LinearModel  {
public :

    Reg(Data *, float, float);

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

};


#endif //MY_ML_REG_H
