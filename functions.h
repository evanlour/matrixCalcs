#include <iostream>
#include <vector>
#include <string>

const std::string version = "0.1";
class matrixFunctions{
    public:
        int functionsCalled = 0;
        matrixFunctions();
        void addRowToRow(std::vector<std::vector<double>> &mat, int source, int dest, double val);
        void addColToCol(std::vector<std::vector<double>> &mat, int source, int dest, double val);
        std::vector<std::vector<double>> addMatrixes(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2);
        std::vector<std::vector<double>> subMatrixes(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2);
        std::vector<std::vector<double>> mulMatrixes(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2);
        std::vector<std::vector<double>> transposeMatrix(std::vector<std::vector<double>> mat);
        std::vector<double> matrixSysSolver(std::vector<std::vector<double>> mat1, std::vector<double> mat2);
        std::vector<double> matrixSysSolver(std::vector<std::vector<double>> mat1, std::vector<double> mat2, bool verbose);
        void printMatrix(std::vector<std::vector<double>> mat);
        void printMatrix(std::vector<double> mat);
};

