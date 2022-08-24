
#include "ClassificationMetrics.h"

#include <vector>
#include <cmath>

using namespace std;

namespace ClassificationMetrics{

    float binary_crossentropy(vector<float> *_vec1, vector<float> *_vec2) {
        float _error =0;
        for(int i=0;i<_vec1->size();i++){
            _error = _error + (_vec1->at(i)*log(_vec2->at(i)));
            _error = _error + ((1-_vec1->at(i)) * log(1-_vec2->at(i)));
        }
        _error = - _error / static_cast<float>(_vec1->size());
        return _error;
    }

    // TODO: split
    float entropy(vector<float> *_vec) {

        float _class_num=_vec->at(0);
        for(int i=1;i<_vec->size();i++){
            if(_vec->at(i)>_class_num){
                _class_num = _vec->at(i);
            }
        }

        vector<float> _counts(static_cast<int>(_class_num),0.0);

        for(int i=0;i<_vec->size();i++){
            int _class =static_cast<int>(_vec->at(i));
            _counts.at(_class)=_counts.at(_class)+1;
        }

        float _sum = 0;
        for(int i=0;i<static_cast<int>(_class_num);i++){
            _sum = _sum + _counts.at(i);
        }

        float _entropy = 0;
        for(int i=0;i<static_cast<int>(_class_num);i++){
            _entropy = _entropy - ((_counts.at(i)/_sum)*log(_counts.at(i)/_sum));
        }
        return _entropy;
    }

}

