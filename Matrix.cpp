#include "Matrix.hpp"

using namespace std;
namespace zich {

    // constructor
    Matrix::Matrix(vector<double> mat, int row, int col)
        : _mat(mat), _row(row), _col(col) {
    }

    //----------------------------------
    // unary operator
    //----------------------------------

    Matrix Matrix::operator+() {
        vector<double> m = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        return Matrix(m, 3, 3);
    }
    Matrix Matrix::operator-() {
        vector<double> m = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        return Matrix(m, 3, 3);
    }

    
    //----------------------------------------
    // binary operators
    //----------------------------------------
   
    Matrix Matrix::operator+(const Matrix &other) {
        vector<double> m = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        return Matrix(m, 3, 3);
    }
    Matrix Matrix::operator+=(const Matrix &other) {
        vector<double> m = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        return Matrix(m, 3, 3);
    }

    Matrix Matrix::operator-(const Matrix &other) {
        vector<double> m = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        return Matrix(m, 3, 3);
    }
    Matrix Matrix::operator-=(const Matrix &other) {
        vector<double> m = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        return Matrix(m, 3, 3);
    }

    Matrix Matrix::operator*(const Matrix &other) {
        vector<double> m = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        return Matrix(m, 3, 3);
    }
    Matrix Matrix::operator*=(const Matrix &other) {
        vector<double> m = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        return Matrix(m, 3, 3);
    }

    Matrix Matrix::operator*(double scalar) {
        vector<double> m = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        return Matrix(m, 3, 3);
    }
    Matrix Matrix::operator*=(double scalar) {
        vector<double> m = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        return Matrix(m, 3, 3);
    }
    
    //--------------------------------------------
    // prefix and postfix increment and decrement
    //--------------------------------------------
    void Matrix::operator++() {
    }
    void Matrix::operator--() {
    }
    
    Matrix Matrix::operator++(int n) {
        vector<double> m = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        return Matrix(m, 3, 3);
    }
    Matrix Matrix::operator--(int n) {
        vector<double> m = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        return Matrix(m, 3, 3);
    }
    

    //----------------------------------------
    // comparison operators
    //----------------------------------------
    bool Matrix::operator> (Matrix const& other) {
        return true;
    }
    bool Matrix::operator>= (Matrix const& other) {
        return true;
    }
    bool Matrix::operator< (Matrix const& other) {
        return true;
    }
    bool Matrix::operator<= (Matrix const& other) {
        return true;
    }
    bool Matrix::operator== (Matrix const& other) {
        return true;
    }
    bool Matrix::operator!= (Matrix const& other) {
        return true;
    }


    //----------------------------------------
    // IO Operators
    //----------------------------------------
    istream& operator>> (istream& input, const Matrix& mat) {
        return input;
    }
    ostream& operator<< (ostream& output, const Matrix& other) {
        return output;
    }


    Matrix operator*(double num, Matrix &mat) {
        vector<double> m = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        return Matrix(m, 3, 3);
    }
}