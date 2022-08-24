
#ifndef ML_LIBRARY_CLUSTERINGMETRICS_H
#define ML_LIBRARY_CLUSTERINGMETRICS_H

#include <vector>

namespace ClusteringMetrics{

    /*
     * To compare two different clustering methods.
     * Helpful at testing clustering method implementations.
     * Doesnt have to equal to 1 all the time : Random centroid initialization differs rand score.
     */
    float rand_index(std::vector<float>* ,std::vector<float>*);


}

#endif //ML_LIBRARY_CLUSTERINGMETRICS_H
