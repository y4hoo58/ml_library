
#include "Knn.h"
#include <vector>

using namespace std;

kmeans_test::kmeans_test(Data *_data, int _k_neighbors): Model(_data){
    // Set k_neighbors parameter
    k_neighbors = _k_neighbors;

    // Initialize neighbors matrix with zeros
    vector<vector<int>> _neighbors(_data->row_num,vector<int>(_k_neighbors,0));
    neighbors = _neighbors;
}

void kmeans_test::calc_distances() {
    // Calculate distance matrix.
    // Diagonals are zeros.
    distance_matrix =  distances.eucledian_distance(data->inputs);
}

void kmeans_test::find_neighbors() {

    vector<float> _row(distance_matrix.at(0).size(),0.0);

    // For each data point
    for(int i = 0;i<data->row_num;i++){

        // Set the row for the data point
        for(int j = 0;j<_row.size();j++){
            _row.at(j) = distance_matrix.at(i).at(j);
        }

        // Find "k_neighbors"
        for(int j=0;j<k_neighbors;j++){

            // Finds min distance and its index
            float _min = _row.at(0);
            int _min_index = 0;
            for(int k=1;k<_row.size();k++){
                float _val = _row.at(k);
                if(_val < _min){
                    _min = _val;
                    _min_index = k;
                }
            }

            // Set neighbor
            neighbors.at(i).at(j) = _min_index;

            // Set minimum value to max.
            _row.at(_min_index) = numeric_limits<float>::max();
        }
    }
}


void kmeans_test::predict(){
    // Predict for each data point
    for(int i=0;i<data->predictions.size();i++){
        // Loop for each neighbors.
        // Skips itself.
        float _prediction =0;
        for(int j=1;j<k_neighbors;j++){
            _prediction = _prediction + data->targets->at(neighbors.at(i).at(j));
        }

        // Take average  and set the prediction
        data->predictions.at(i)=_prediction/(float)(k_neighbors-1);
    }
}



void kmeans_test::classify() {

}





