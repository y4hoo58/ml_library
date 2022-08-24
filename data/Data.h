#ifndef ML_LIBRARY_DATA_H
#define ML_LIBRARY_DATA_H


#include <vector>
#include <string>

class Data {
public:

    int train_size,test_size,feature_size;

    std::vector<std::vector<float>> *train_x;
    std::vector<float> *train_y;

    std::vector<std::vector<float>> *test_x;
    std::vector<float> *test_y;

    std::vector<float> train_pred;
    std::vector<float> test_pred;


    /*
     * There are different possibilities :
     * - Dataset already in the memory
     * - Dataset in the disk, we might load it after the initialization of the Data class
     * - We don't have train_y -> Clustering
     */
    Data();
    Data(int,int,std::vector<std::vector<float>> *);
    Data(int ,int ,std::vector<std::vector<float>> *,std::vector<float> *);

    ~Data();

    void read_csv(std::string);
    void random_split(float);
    void interpolated_split(float);

    void print_inputs(int) ;
    void print_targets(int) ;
    void print_predictions(int) ;

private:
    std::vector<std::vector<float>> *data_features;
    std::vector<float> *data_targets;


    int find_col_num(std::string);
    void set_elements(std::vector<std::vector<float>>*,std::vector<float>*,std::vector<int>*);
    void select_test_indexes(std::vector<int> *,std::vector<int>*,int,int);
    void assign_train_indexes(std::vector<int> *,std::vector<int> *,int);
};

#endif //ML_LIBRARY_DATA_H
