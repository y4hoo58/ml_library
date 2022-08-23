
#include "Kmeans.h"
#include <cmath>
#include <vector>

Kmeans::Kmeans(Data *_data, int _k_num,int _n_init ,int _max_iter) : Model(_data){
    k_num = _k_num;
    n_init = _n_init;
    max_iter=_max_iter;
    centroid_delta = std::numeric_limits<float>::max();

    centroids=init_centroids();

    vector<float> _clusters(data->row_num,0.0);
    clusters = _clusters;
}

vector<vector<float>> Kmeans::init_centroids(){
    vector<vector<float>> _centroids;
    for(int i=0;i<k_num;i++){
        // Select an input randomly
        int _rand_index=helpers.random_generator( data->row_num);

        // Assign it as a centroid
        _centroids.push_back(data->inputs->at(_rand_index));
    }
    return _centroids;
}

void Kmeans::find_cluster() {
    for(int i=0;i<data->row_num;i++){
        vector<float> _val = data->inputs->at(i);
        int _cluster_index=0;
        float _min_cluster_distance=0;
        for(int j=0;j<k_num;j++){
            float _distance = 0;
            for(int k=0;k<data->col_num;k++){
                _distance = _distance + (float)pow((centroids.at(j).at(k) - data->inputs->at(i).at(k)),2 );
            }
            _distance = sqrt(_distance);

            if(j==0){
                _min_cluster_distance=_distance;
            }else{
                if(_distance<_min_cluster_distance){
                    _min_cluster_distance = _distance;
                    _cluster_index = j;
                }
            }
        }
        clusters.at(i)=(float)_cluster_index;

    }
}

void Kmeans::calc_centroids(){

    centroid_delta=0;

    for(int i=0;i<k_num;i++){
        vector<float> _centroid(data->col_num,0.0);
        float _counter =0;
        // Loop over all rows.
        // Find where i == cluster number.
        // Sum all rows column wise that belongs to ith cluster.
        for(int j=0;j<data->row_num;j++){
            if(clusters.at(j) == (float)i){
                _counter = _counter+1;
                for(int k=0;k<data->col_num;k++){
                    _centroid.at(k) =_centroid.at(k)+data->inputs->at(j).at(k);
                }
            }
        }

        // Take average of all the columns of the centroid.
        // Assign each averaged columns to the global centroids vector.
        for(int j=0;j<data->col_num;j++){
            centroid_delta = centroid_delta+ (centroids.at(i).at(j) - (_centroid.at(j)/_counter));
            centroids.at(i).at(j) =_centroid.at(j)/_counter;
        }
    }
}

void Kmeans::calc_average_centroids(int _i){
    /*
     * If first ->> init avg_centroids vector
     * Else ->> sum
     */
    if(_i==0){
        avg_centroids = centroids;
    }else {
        for(int j=0;j<centroids.size();j++){
            for(int k=0;k<centroids.at(j).size();k++){
                avg_centroids.at(j).at(k) = avg_centroids.at(j).at(k)+centroids.at(j).at(k);
            }
        }
    }

    // if last init ->> take average
    if(_i == n_init-1){
        for(int i=0;i<centroids.size();i++){
            for(int j=0;j<centroids.at(i).size();j++){
                avg_centroids.at(i).at(j) = avg_centroids.at(i).at(j)/(float)n_init;
            }
        }
    }
}


void Kmeans::fit(){

    for(int i=0;i<n_init;i++){
        int _iter_count = 0;
        init_centroids();
        while((centroid_delta!=0)&(_iter_count<max_iter)){
            find_cluster();
            calc_centroids();
            _iter_count++;
        }
        calc_average_centroids(i);
    }
}


void Kmeans::predict() {

}