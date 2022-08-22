
#ifndef ML_LIBRARY_KNN_H
#define ML_LIBRARY_KNN_H


#include "../Model.h"

class kmeans_test: public Model {
public:
    int k_neighbors;
    std::vector<std::vector<float>> distance_matrix;
    std::vector<std::vector<int>> neighbors;
    kmeans_test(Data * , int);

    // Calculates distance matrix
    void calc_distances();

    // Finds determined number of neighbors, including itself
    void find_neighbors();

    // Regression
    // Average ??
    // Weighted Average??
    void predict();

    // Implement later.
    void classify();

};


#endif //MY_ML_KNN_H
