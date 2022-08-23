
#include "Distances.h"
#include <vector>
#include <cmath>

using namespace std;

vector<vector<float>> Distances::eucledian_distance(vector<vector<float>> *_vec){
    vector<vector<float>> _distance_matrix(_vec->size(),vector<float>(_vec->size(),0)) ;
    for(int i=0;i<_vec->size();i++){
        for(int j=0;j<_vec->size();j++){
            float _distance = 0;
            for(int k = 0 ;k< _vec->at(0).size();k++){
                float _m = _vec->at(i).at(k) - _vec->at(j).at(k);
                _m = pow(_m,2);
                _distance = _distance + _m;
            }
            _distance_matrix.at(i).at(j) = sqrt(_distance);
        }
    }

    return _distance_matrix;
}

