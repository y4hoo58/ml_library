
#ifndef ML_LIBRARY_MODEL_H
#define ML_LIBRARY_MODEL_H


#include "../utility/Helpers.h"
#include "../data/Data.h"
#include "../metrics/Distances.h"

class Model {
public:
    Data *data;

    explicit Model (Data *);
};


#endif //ML_LIBRARY_MODEL_H
