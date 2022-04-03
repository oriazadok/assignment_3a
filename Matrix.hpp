#include <iostream>
#include <vector>

using namespace std;
namespace zich {
    class Matrix {
        
        private:

            vector<double> _mat;
            int _row;
            int _col;

        public:

        // constructor
        Matrix(vector<double> mat, int row, int col);

        //-------------------------------------
        // getters
        //-------------------------------------
        vector<double> mat() const {
            return _mat;
        }
        int row() const {
            return _row;
        }

        int col() const {
            return _col;
        }


        //----------------------------------
        // unary operator
        //----------------------------------
        Matrix operator+();
        Matrix operator-();


        //----------------------------------------
        // binary operators
        //----------------------------------------
        Matrix operator+(const Matrix &other);
        Matrix operator+=(const Matrix &other);

        Matrix operator-(const Matrix &other);
        Matrix operator-=(const Matrix &other);

        Matrix operator*(const Matrix &other);
        Matrix operator*=(const Matrix &other);

        Matrix operator*(double scalar);
        Matrix operator*=(double scalar);


        //--------------------------------------------
        // prefix and postfix increment and decrement
        //--------------------------------------------
        void operator++();
        void operator--();
        Matrix operator++(int n);
        Matrix operator--(int n);
    

        //----------------------------------------
        // comparison operators
        //----------------------------------------
        bool operator> (Matrix const& other);
        bool operator>= (Matrix const& other);
        bool operator< (Matrix const& other);
        bool operator<= (Matrix const& other);
        bool operator== (Matrix const& other);
        bool operator!= (Matrix const& other);


        //----------------------------------------
        // IO Operators
        //----------------------------------------
        friend istream& operator>> (istream& input, const Matrix& mat); 
        friend ostream& operator<< (ostream& output, const Matrix& mat);
    };
    
    Matrix operator*(const double num, Matrix& mat);
}