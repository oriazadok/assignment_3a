
#include "doctest.h"
#include "Matrix.hpp"
#include <iostream>
#include <sstream>
using namespace zich;

#include <string>
#include <algorithm>
using namespace std;


TEST_CASE("Illegal Input") {
    vector<double> mat;
    
    SUBCASE("Empty Matrix") {
        CHECK(mat.empty() == false);
    }

    for(double i=0; i<105; i++) {
        mat.push_back(i * 3.5); 
        
    }
    
    SUBCASE("Illegal Numbers Of Rows") {
        CHECK_THROWS(Matrix m(mat, -1, 4));
        CHECK_THROWS(Matrix m(mat, 0, -3));
        CHECK_THROWS(Matrix m(mat, -2, 0));
        CHECK_THROWS(Matrix m(mat, 0, 4));
        CHECK_THROWS(Matrix m(mat, 0, 0));
    }

    SUBCASE("Illegal Numbers Of Columns") {
        CHECK_THROWS(Matrix m(mat, 1, -4));
        CHECK_THROWS(Matrix m(mat, 0, -3));
        CHECK_THROWS(Matrix m(mat, -2, 0));
        CHECK_THROWS(Matrix m(mat, 3, 0));
    }

    SUBCASE("Not Suitable Sizes") {
        Matrix m(mat, 15, 7);
        CHECK(mat.size() % (size_t)m.row() == 0);
        CHECK(mat.size() % (size_t)m.col() == 0);
    }
    
}

TEST_CASE("Undefined Calculation") {
    vector<double> a;    // 17 X 13
    vector<double> b;    // 13 X 17
    vector<double> c;    // 19 X 23
    vector<double> d;    // 23 X 19
    vector<double> zero; // 19 X 23
    
    for(double i=0; i<437; i++) {
        if(i < 221){
            a.push_back(i * 3.5); 
            b.push_back(i * 3.5); 
        }
        c.push_back(i * 3.5); 
        d.push_back(i * 3.5); 
        zero.push_back(0); 

    }
    Matrix ma(a, 17, 13);
    Matrix mb(b, 13, 17);
    Matrix mc(c, 19, 23);
    Matrix md(d, 23, 19);
    Matrix mz(zero, 19, 23);

    SUBCASE("Undefined Addition") {
        CHECK_THROWS(ma + mb);
        CHECK_THROWS(ma + mc);
        CHECK_THROWS(ma += md);
        CHECK_THROWS(ma + mz);
        CHECK_THROWS(mb += mc);
        CHECK_THROWS(mz += md);
       
    }
    SUBCASE("Undefined Subtraction") {
        CHECK_THROWS(ma - mb);
        CHECK_THROWS(ma -= mc);
        CHECK_THROWS(ma - md);
        CHECK_THROWS(ma -= mz);
        CHECK_THROWS(mb -= mc);
        CHECK_THROWS(mz - md);

    }
    SUBCASE("Undefined Multiplication") {
        CHECK_THROWS(ma *= mc);
        CHECK_THROWS(ma * md);
        CHECK_THROWS(ma *= mz);
        CHECK_THROWS(mb *= mc);
        CHECK_THROWS(mb *= mz);
        CHECK_THROWS(mc * mz);
    }
}

TEST_CASE("Calculation") {
    vector<double> A1;    // 17 X 13
    vector<double> A2;    // 17 X 13
    vector<double> A3;    // 17 X 13
    vector<double> A4;    // 17 X 13
    vector<double> z;     // 17 X 13

    vector<double> M1;    // 5 X 3
    vector<double> M2;    // 3 X 5
    vector<double> M3 = {25, 28, 31, 34, 37, 70, 82, 94, 106, 118, 115, 136, 157, 178, 199, 160, 190, 220, 250, 280, 205, 244, 283, 322, 361};    // 5 X 5
    
    for(double i=0; i<221; i++) {
        A1.push_back(i); 
        A2.push_back(i); 
        A3.push_back(-i); 
        A4.push_back(i * 2); 
        z.push_back(0); 

        if(i < 15) {
            M1.push_back(i); 
            M2.push_back(i); 
            
        }
    }
    Matrix ma1(A1, 17, 13);
    Matrix ma2(A2, 17, 13);
    Matrix ma3(A3, 17, 13);
    Matrix ma4(A4, 17, 13);
    Matrix mz(A4, 17, 13);

    Matrix mm1(M1, 5, 3);
    Matrix mm2(M2, 3, 5);
    Matrix mm3(M3, 5, 5);

    SUBCASE("Addition Calculation") {
        ma1 += ma2;
        ma2 += ma3;
        for(size_t i=0; i<221; i++) {
            CHECK(ma1.mat()[i] == ma4.mat()[i]);
            CHECK(ma2.mat()[i] == mz.mat()[i]);
        }
    }
    SUBCASE("Subtraction Calculation") {
        ma1 -= ma2;
        ma2 -= ma3;
        for(size_t i=0; i<221; i++) {
            CHECK(ma1.mat()[i] == mz.mat()[i]);
            CHECK(ma2.mat()[i] == ma4.mat()[i]);
        }
    }
    
    SUBCASE("Multiplication Calculation") {
        ma1 *= mz;
        ma2 *= 3;
        mm1 *= mm2; 
        for(size_t i=0; i<221; i++) {
            CHECK(ma1.mat()[i] == mz.mat()[i]);
            CHECK(ma2.mat()[i] == ma3.mat()[i] * -3);
            if (i < 15) {
                CHECK(mm1.mat()[i] == mm3.mat()[i]);
            }
        }
      
    }

    SUBCASE("comparison operators") {
        CHECK((ma1 > ma2) == false);
        CHECK((ma1 >= ma2) == true);
        CHECK((ma1 < ma2) == false);
        CHECK((ma1 <= ma2) == true);
        CHECK((ma1 == ma2) == true);
        CHECK((ma1 != ma2) == false);
    }
}

TEST_CASE("IO Operators") {
    vector<double> in;    // 3 X 4
    vector<double> out;    // 3 X 4
    
    for(double i=0; i<12; i++) {
        out.push_back(i); 
    }
    Matrix min(in, 3, 4);
    Matrix mout(out, 3, 4);

    SUBCASE("Input Operator") {
        istringstream in{"[0 1 2 3 ], [4 5 6 7], [8 9 10 11]"};
        in >> min;

        CHECK((min == mout) == true);
    }
    SUBCASE("Output operator") {
        ostringstream output;

        output << mout;
        CHECK(output.str() == "[0 1 2 3]\n[4 5 6 7]\n[8 9 10 11]");
    }
}
