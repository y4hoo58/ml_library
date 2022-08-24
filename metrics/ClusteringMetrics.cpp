
#include "ClusteringMetrics.h"

#include <vector>
#include <cmath>

using namespace std;

namespace ClusteringMetrics{

    float rand_index(vector<float> *_vec1,vector<float> *_vec2){
        int _same_class=0;
        int _diff_class =0;
        int _total_pairs = 0;
        for(int i=0;i<_vec1->size();i++){
            float _element1 = _vec1->at(i);
            float _element2 = _vec2->at(i);
            for(int j=0;j<_vec1->size();j++){
                float _element1_ = _vec1->at(j);
                float _element2_ = _vec2->at(j);

                if((_element1 == _element1_) && (_element2 == _element2_)){
                    _same_class++;
                }

                if((_element1!= _element1_)&&(_element2!= _element2_)){
                    _diff_class++;
                }

                _total_pairs++;
            }
        }
        return ((float)_diff_class+(float)_same_class)/(float)_total_pairs;
    }



}
