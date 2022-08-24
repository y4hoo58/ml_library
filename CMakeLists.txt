cmake_minimum_required(VERSION 3.21)
project(ml_library)

set(CMAKE_CXX_STANDARD 20)

add_library(ml_library data/Data.cpp data/Data.h metrics/Distances.cpp metrics/Distances.h models/linear/LinearModel.cpp models/linear/LinearModel.h models/linear/Reg.cpp models/linear/Reg.h models/linear/Logistic.cpp models/linear/Logistic.h models/Model.cpp models/Model.h models/knn/Knn.cpp models/knn/Knn.h models/kmeans/Kmeans.cpp models/kmeans/Kmeans.h utility/Helpers.cpp utility/Helpers.h models/ensemble/RandomForest.cpp models/ensemble/RandomForest.h metrics/RegressionMetrics.cpp metrics/RegressionMetrics.h metrics/ClassificationMetrics.cpp metrics/ClassificationMetrics.h metrics/ClusteringMetrics.cpp metrics/ClusteringMetrics.h)

add_executable(linear_regression implementations/regression/linear_regression.cpp)
add_executable(logistic_regression implementations/classification/logistic_regression.cpp)
add_executable(kmeans_test implementations/clustering/kmeans_test.cpp)
add_executable(knn_regression implementations/regression/knn_regression.cpp)

find_library(ML_LIBRARY ml_library cmake-build-debug)

target_link_libraries(linear_regression ${ML_LIBRARY})
target_link_libraries(logistic_regression ${ML_LIBRARY})
target_link_libraries(kmeans_test ${ML_LIBRARY})
target_link_libraries(knn_regression ${ML_LIBRARY})