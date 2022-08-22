#ifndef ML_LIBRARY_DISTANCES_H
#define ML_LIBRARY_DISTANCES_H

#include <vector>

using namespace std;
class Distances {

public:

    vector<vector<float>> eucledian_distance(vector<vector<float>>*);

    vector<vector<float>> cosine_distance(vector<vector<float>> *);
};


#endif //MY_ML_DISTANCES_H
