
#ifndef ML_LIBRARY_HELPERS_H
#define ML_LIBRARY_HELPERS_H
#include <vector>

namespace Helpers{
    float random_generator();
    float random_generator(float);
    int random_generator(int);

    float max_value(std::vector<float> *);
    float min_value(std::vector<float> *);
}

#endif //MY_ML_HELPERS_H
