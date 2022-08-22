
#ifndef ML_LIBRARY_MODEL_H
#define ML_LIBRARY_MODEL_H


#include "../utility/Helpers.h"
#include "../data/Data.h"
#include "../metrics/Metrics.h"
#include "../metrics/Distances.h"

class Model {
public:
    Data *data;
    Helpers helpers;
    Metrics metrics;
    Distances distances;

    explicit Model (Data *);
};


#endif //MY_ML_MODEL_H
