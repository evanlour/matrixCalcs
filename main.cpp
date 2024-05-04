#include <iostream>
#include "functions.cpp"
#include <vector>

int main(){
    matrixFunctions mat;
    std::vector<std::vector<double>> mat1 = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<double>> mat2 = {{7, 8}, {9, 10}, {11, 12}};
    std::vector<std::vector<double>> mat3 = mat.mulMatrixes(mat1, mat2);
    std::vector<std::vector<double>> mat4 = {{1, 3}, {11, 22}};
    std::vector<double> mat5 = {5, 88};
    std::vector<std::vector<double>> mat6 = {{1, 4, 9, 55},
                                            {20, 3, -65, 3},
                                            {9, 1, 5, 3},
                                            {-4, 6, 7, 8}};
    std::vector<double> mat7 = {100, 0, 22, 9};
    std::vector<double> mat8 = mat.matrixSysSolver(mat6, mat7, false);
    mat.printMatrix(mat8);
    return 0;
}