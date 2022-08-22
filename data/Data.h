#ifndef ML_LIBRARY_DATA_H
#define ML_LIBRARY_DATA_H


#include <vector>
#include <string>

class Data {
public:

    int row_num,col_num;

    std::vector<std::vector<float>> *inputs;
    std::vector<float> *targets;
    std::vector<float> predictions;

    /*
     * There are different possibilities :
     * - Dataset already in the ram
     * - Dataset in the disk, we might load it after the initialization of the Data class
     * - We dont have targets -> Clustering
     */
    Data();
    Data(int,int,std::vector<std::vector<float>> *);
    Data(int ,int ,std::vector<std::vector<float>> *,std::vector<float> *);

    ~Data();

    void read_csv(std::string);

    void print_inputs(int);
    void print_targets(int);
    void print_predictions(int);

private:
    int find_col_num(std::string);

};

#endif //MY_ML_DATA_H
