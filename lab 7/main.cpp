#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

class Matrix {
private:
    std::vector<std::vector<int>> data;

public:

    Matrix(int size) : data(size, std::vector<int>(size)) {}


    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file");
        }
        for (auto& row : data) {
            for (auto& elem : row) {
                file >> elem;
            }
        }
        file.close();
    }


    void display() const {
        for (const auto& row : data) {
            for (const auto& elem : row) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    }


    Matrix operator+(const Matrix& other) const {
        if (data.size() != other.data.size() || data[0].size() != other.data[0].size()) {
            throw std::runtime_error("Matrices dimensions mismatch");
        }
        Matrix result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[i].size(); ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (data[0].size() != other.data.size()) {
            throw std::runtime_error("Matrices dimensions mismatch for multiplication");
        }
        int n = data.size();
        int m = other.data[0].size();
        int p = other.data.size();
        Matrix result(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < p; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }


    int diagonalSum() const {
        int sum = 0;
        int n = data.size();
        for (int i = 0; i < n; ++i) {
            sum += data[i][i];  
            sum += data[i][n-i-1];  
        }
        return sum;
    }


    void swapRows(int row1, int row2) {
        if (row1 >= 0 && row1 < data.size() && row2 >= 0 && row2 < data.size() && row1 != row2) {
            std::swap(data[row1], data[row2]);
        } else {
            throw std::runtime_error("Invalid row indices");
        }
    }
};

int main() {
    Matrix matrix(4); 
    matrix.loadFromFile("matrix-data.txt"); 
    matrix.display();

    Matrix matrix2(4);
    matrix2.loadFromFile("matrix-data.txt"); 
    Matrix sumMatrix = matrix + matrix2;
    Matrix productMatrix = matrix * matrix2;

    sumMatrix.display();
    productMatrix.display();

    std::cout << "Diagonal Sum: " << matrix.diagonalSum() << std::endl;

    matrix.swapRows(0, 1);
    matrix.display();

    return 0;
}
