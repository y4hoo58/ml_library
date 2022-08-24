
#include "RegressionMetrics.h"

#include <vector>
#include <cmath>

using namespace std;

namespace RegressionMetrics{

    float mse(vector<float> *_vec1,vector<float> *_vec2){
        float _error = 0;
        for(int i=0;i<_vec1->size();i++){
            _error = _error + ((_vec2->at(i) - _vec1->at(i))*(_vec2->at(i) - _vec1->at(i)));
        }
        _error = _error / static_cast<float>(_vec1->size());
        return _error;
    }

    float mae(vector<float> *_vec1,vector<float> *_vec2){
        float _error = 0;
        for(int i=0;i<_vec1->size();i++){
            _error = _error + abs((_vec2->at(i) - _vec1->at(i)));
        }
        _error = _error / static_cast<float>(_vec1->size());
        return _error;
    }

    float r2_score(vector<float> *_vec1,vector<float> *_vec2) {
        float _rss = r2_funcs::calc_rss(_vec1,_vec2);
        float _tss = r2_funcs::calc_tss(_vec1,_vec2);
        return 1-(_rss/_tss);
    }

    namespace r2_funcs{
        float calc_rss(vector<float> *_vec1,vector<float> *_vec2) {
            float _rss  = 0;
            for(int i=0;i<_vec1->size();i++){
                _rss = _rss+static_cast<float>(pow(_vec1->at(i)-_vec2->at(i),2));
            }
            return _rss;
        }

        float calc_tss(vector<float> *_vec1,vector<float> *_vec2) {
            float _mean=0;
            for(int i=0;i<_vec1->size();i++){
                _mean=_mean+ _vec1->at(i);
            }
            _mean = _mean / static_cast<float>(_vec1->size());

            float _tss  = 0;
            for(int i=0;i<_vec1->size();i++){
                _tss = _tss+static_cast<float>(pow(_vec2->at(i)-_mean,2));
            }
            return _tss;
        }
    }
}