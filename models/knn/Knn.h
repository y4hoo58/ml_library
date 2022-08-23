
#ifndef ML_LIBRARY_KNN_H
#define ML_LIBRARY_KNN_H


#include "../Model.h"

/*
 * TODO:
 * - Implement classification
 * - Regression -> Simple Average or Weighted Average?
 */

class Knn: public Model {
public:
    int k_neighbors;
    std::vector<std::vector<float>> distance_matrix;
    std::vector<std::vector<int>> neighbors;
    Knn(Data * , int);

    void fit();
    void regression();
    void classification();

private:

    // Calculates distance matrix
    void calc_distances();

    // Finds the closest neighbors with respect to each data point
    void find_neighbors();
};
#endif //MY_ML_KNN_H
