
#include "Metrics.h"
#include <vector>
#include <cmath>

using namespace std;

namespace Metrics{
    float mse(vector<float> *_targets,vector<float> *_predictions){
        float _error = 0;
        for(int i=0;i<_targets->size();i++){
            _error = _error + ((_predictions->at(i) - _targets->at(i))*(_predictions->at(i) - _targets->at(i)));
        }
        _error = _error / (float)_targets->size();
        return _error;
    }

    float mae(vector<float> *_targets,vector<float> *_predictions){
        float _error = 0;
        for(int i=0;i<_targets->size();i++){
            _error = _error + abs((_predictions->at(i) - _targets->at(i)));
        }
        _error = _error / (float)_targets->size();
        return _error;
    }

    float binary_crossentropy(vector<float> *_targets, vector<float> *_predictions) {
        float _error =0;
        for(int i=0;i<_targets->size();i++){
            _error = _error + (_targets->at(i)*log(_predictions->at(i)));
            _error = _error + ((1-_targets->at(i)) * log(1-_predictions->at(i)));
        }
        _error = - _error / (float)_targets->size();
        return _error;
    }


    float entropy(vector<float> *_targets) {

        float _class_num=_targets->at(0);
        for(int i=1;i<_targets->size();i++){
            if(_targets->at(i)>_class_num){
                _class_num = _targets->at(i);
            }
        }

        vector<float> _counts((int)_class_num,0.0);

        for(int i=0;i<_targets->size();i++){
            int _class =(int) _targets->at(i);
            _counts.at(_class)=_counts.at(_class)+1;
        }

        float _sum = 0;
        for(int i=0;i<(int)_class_num;i++){
            _sum = _sum + _counts.at(i);
        }

        float _entropy = 0;
        for(int i=0;i<(int) _class_num;i++){
            _entropy = _entropy - ((_counts.at(i)/_sum)*log(_counts.at(i)/_sum));
        }
        return _entropy;
    }


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

