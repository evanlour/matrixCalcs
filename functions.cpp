#include <iostream>
#include "functions.h"

matrixFunctions::matrixFunctions(){
    std::cout << "Matrix functions version " << version << std::endl;
};

void matrixFunctions::addRowToRow(std::vector<std::vector<double>> &mat, int source, int dest, double val){
    for(int i = 0; i < mat[0].size(); i++){
        mat[dest][i] = mat[dest][i] + mat[source][i] * val;
    }
    functionsCalled++;
};

void matrixFunctions::addColToCol(std::vector<std::vector<double>> &mat, int source, int dest, double val){
    for(int i = 0; i < mat[0].size(); i++){
        mat[i][dest] = mat[i][dest] + mat[i][source] * val;
    }
    functionsCalled++;
};

void matrixFunctions::printMatrix(std::vector<std::vector<double>> mat){
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[i].size(); j++){
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
    functionsCalled++;
};

void matrixFunctions::printMatrix(std::vector<double> mat){
    for(auto i : mat){
        std::cout << i << " ";
    }
    std::cout << std::endl;
};

std::vector<std::vector<double>> matrixFunctions::addMatrixes(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2){
    std::vector<std::vector<double>> retVal = mat1;
    
    if(mat1.size() != mat2.size()){
        std::cout << "Error, matrix sizes differ!\n";
        return retVal;
    }

    
    for(int i = 0; i < mat1.size(); i++){
        if(mat1[i].size() != mat2[i].size()){
            std::cout << "Error, matrix sizes differ!\n";
            retVal.clear();
            return retVal;
        }
        for(int j = 0; j < mat1[i].size(); j++){
            retVal[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return retVal;
};

std::vector<std::vector<double>> matrixFunctions::subMatrixes(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2){
    std::vector<std::vector<double>> retVal = mat1;
    
    if(mat1.size() != mat2.size()){
        std::cout << "Error, matrix sizes differ!\n";
        return retVal;
    }

    
    for(int i = 0; i < mat1.size(); i++){
        if(mat1[i].size() != mat2[i].size()){
            std::cout << "Error, matrix sizes differ!\n";
            retVal.clear();
            return retVal;
        }
        for(int j = 0; j < mat1[i].size(); j++){
            retVal[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return retVal;
};

std::vector<std::vector<double>> matrixFunctions::mulMatrixes(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2){
    std::vector<std::vector<double>> retVal;
    if(mat1.size() != mat2[0].size()){
        std::cout << "Error, matrixes are not multiplication compatible\n";
        return retVal;
    }

    for(int i = 0; i < mat1.size(); i++){
        std::vector<double> temp;
        for(int j = 0; j < mat2[0].size(); j++){
            double val = 0;
            for(int k = 0; k < mat1[0].size(); k++){
                val = val + mat1[i][k] * mat2[k][j];
            }
            temp.push_back(val);
        }
        retVal.push_back(temp);
    }
    return retVal;
};

std::vector<std::vector<double>> matrixFunctions::transposeMatrix(std::vector<std::vector<double>> mat){
    std::vector<std::vector<double>> retVal;
    for(int i = 0; i < mat[0].size(); i++){
        std::vector<double> temp;
        for(int j = 0; j < mat.size(); j++){
            temp.push_back(mat[j][i]);
        }
        retVal.push_back(temp);
    }
    return retVal;
};

std::vector<double> matrixFunctions::matrixSysSolver(std::vector<std::vector<double>> mat1, std::vector<double> mat2){
    if(mat1.size() != mat1[0].size() || mat2.size() != mat1.size()){
        std::cout << "matrix system is not formatted correctly!\n";
        return {0, 0, 0};
    }
    int val = 0;

    while(val < mat1[0].size()){
        for(int i = val; i > 0; i--){
            double mult = (-mat1[i - 1][val]) / (mat1[val][val]);
            addRowToRow(mat1, val, i - 1, mult);
            mat2[i - 1] = mat2[i - 1] + mat2[val] * mult;
        }

        for(int i = val + 1; i < mat1[0].size(); i++){
            double mult = (-mat1[i][val]) / (mat1[val][val]);
            addRowToRow(mat1, val, i, mult);
            mat2[i] = mat2[i] + mat2[val] * mult;
        }

        val++;
    }

    for(int i = 0; i < mat1.size(); i++){
        double val = 1 / mat1[i][i];
        mat1[i][i] = 1;
        mat2[i] = mat2[i] * val;
    }
    return mat2;
};

std::vector<double> matrixFunctions::matrixSysSolver(std::vector<std::vector<double>> mat1, std::vector<double> mat2, bool verbose){
    if(mat1.size() != mat1[0].size() || mat2.size() != mat1.size()){
        std::cout << "matrix system is not formatted correctly!\n";
        return {0, 0, 0};
    }
    int val = 0;

    while(val < mat1[0].size()){
        for(int i = val; i > 0; i--){
            double mult = (-mat1[i - 1][val]) / (mat1[val][val]);
            addRowToRow(mat1, val, i - 1, mult);
            mat2[i - 1] = mat2[i - 1] + mat2[val] * mult;
        }

        for(int i = val + 1; i < mat1[0].size(); i++){
            double mult = (-mat1[i][val]) / (mat1[val][val]);
            addRowToRow(mat1, val, i, mult);
            mat2[i] = mat2[i] + mat2[val] * mult;
        }

        val++;
        if(verbose){
            printMatrix(mat1);
            printMatrix(mat2);
            std::cout << std::endl;
        }
    }

    for(int i = 0; i < mat1.size(); i++){
        double val = 1 / mat1[i][i];
        mat1[i][i] = 1;
        mat2[i] = mat2[i] * val;
    }

    if(verbose){
        printMatrix(mat1);
        printMatrix(mat2);
    }
    return mat2;
};