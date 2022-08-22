
#ifndef ML_LIBRARY_KMEANS_H
#define ML_LIBRARY_KMEANS_H


#include "../Model.h"
#include <vector>

/*
 * TODO :
 * - Multiple initializations
 * - Test
 */
class Kmeans : public Model{

public:

    int k_num;
    float centroid_delta;

    vector<vector<float>> centroids;
    vector<float> clusters;

    Kmeans(Data*,int);

    vector<vector<float>> init_centroids();

    void find_cluster();
    void calc_centroids();

    void fit();
    void fit(int);
};


#endif //MY_ML_KMEANS_H
