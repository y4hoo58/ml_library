
#ifndef ML_LIBRARY_KMEANS_H
#define ML_LIBRARY_KMEANS_H

#include "../Model.h"

#include <vector>

/*
 * TODO :
 *  Implement kmeans++ algorithm
 *  Add inertia_ attribute
 *  Implement predict() method
 */
class Kmeans : public Model{

public:
    /*
     * Normally, sklearn.kmeans runs different centroid seeds.
     * The final results are selected based on the best inertia.
     * Instead of taking the best result , i take the average of all results.
     */

    int k_num,n_init,max_iter;
    float centroid_delta;

    std::vector<std::vector<float>> centroids;
    std::vector<std::vector<float>> avg_centroids;
    std::vector<float> clusters;

    Kmeans(Data*,int,int,int);

    void fit();
    void predict();

private:
    std::vector<std::vector<float>> init_centroids();
    void find_cluster();
    void calc_centroids();
    void calc_average_centroids(int);
};


#endif //MY_ML_KMEANS_H
