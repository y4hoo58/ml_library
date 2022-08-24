
#ifndef ML_LIBRARY_REGRESSIONMETRICS_H
#define ML_LIBRARY_REGRESSIONMETRICS_H

#include <vector>

namespace RegressionMetrics{

    float mse(std::vector<float>*,std::vector<float>*);
    float mae(std::vector<float>*,std::vector<float>*);
    float r2_score(std::vector<float> *,std::vector<float> *);

    namespace r2_funcs{
        float calc_rss(std::vector<float> *,std::vector<float> *);
        float calc_tss(std::vector<float> *,std::vector<float> *);
    }
}

#endif //ML_LIBRARY_REGRESSIONMETRICS_H
