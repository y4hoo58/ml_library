//
// Created by yahya on 18.08.2022.
//

#include "Helpers.h"
#include <cmath>

#include <iostream>
using namespace std;

float Helpers::random_generator(){
    // Generate a random number between 0 and 1
    float _rand = ((float) rand()/(float)RAND_MAX);

    // Scale the random number between -_abs_max and _abs_max
    _rand = (float)((_rand-0.5)*2);

    return _rand;
}

float Helpers::random_generator(float _abs_max=1){
    // Generate a random number between 0 and 1
    float _rand = ((float) rand()/(float)RAND_MAX);

    // Scale the random number between -_abs_max and _abs_max
    _rand = (float)((_rand-0.5)*2)*_abs_max;

    return _rand;
}

int Helpers::random_generator(int _max_value) {
    // Generate a random number between 0 and 1
    float _rand = ((float) rand()/(float)RAND_MAX);

    // Scale the random number up to the max value.
    _rand = _rand * (float)_max_value;

    // Round to the floor
    _rand = floor(_rand);

    return (int)_rand;
}

float Helpers::max_value(vector<float> *_vec){
    float _max_val=_vec->at(0);
    for(int i=1;i<_vec->size();i++){
        if(_vec->at(i)>_max_val){
            _max_val = _vec->at(i);
        }
    }
    return _max_val;
}

float Helpers::min_value(vector<float> *_vec){
    float _min_val = _vec->at(0);
    for(int i=1;i<_vec->size();i++){
        if(_vec->at(i)<_min_val){
            _min_val = _vec->at(i);
        }
    }
    return _min_val;
}


