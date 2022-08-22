#ifndef ML_LIBRARY_METRICS_H
#define ML_LIBRARY_METRICS_H

#include <vector>

using namespace std;

class Metrics {

public:

    // ?? Static

    float mse(vector<float>*,vector<float>*);
    float mae(vector<float>*,vector<float>*);
    float binary_crossentropy(vector<float>*,vector<float>*);
    float entropy(vector<float> *);


    /*
     * To compare two different clustering methods.
     * Helpful at testing clustering method implementations.
     * Doesnt have to equal to 1 all the time : Random centroid initialization differs rand score.
     */
    float rand_index(vector<float>* ,vector<float>*);

};


#endif //MY_ML_METRICS_H
