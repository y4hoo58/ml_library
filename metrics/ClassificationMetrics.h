
#ifndef ML_LIBRARY_CLASSIFICATIONMETRICS_H
#define ML_LIBRARY_CLASSIFICATIONMETRICS_H

#include <vector>

namespace ClassificationMetrics{

    float binary_crossentropy(std::vector<float>*,std::vector<float>*);
    float entropy(std::vector<float> *);

    float accuracy();
    float f1_score();
    float recall();
    float precision();
}

#endif //ML_LIBRARY_CLASSIFICATIONMETRICS_H
