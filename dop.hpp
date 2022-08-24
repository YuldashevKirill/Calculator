#ifndef FUNCTIONS
#define FUNCTIONS

#include <iostream>
#include "huge.hpp"

namespace my {
    class Multiplier;
    class Function;
    class Variable;
    using namespace std;
    void not_equal(string s1, string s2);
    Multiplier sin(Variable x);
    Multiplier sin(Multiplier m);
    Multiplier cos(Variable x);
    Multiplier cos(Multiplier m);
    Multiplier exp(Variable x);
    Multiplier exp(Multiplier m);
    Multiplier ln(Variable x);
    Multiplier ln(Multiplier m);
    Multiplier asin(Variable x);
    Multiplier asin(Multiplier m);
    Multiplier sin(Function f);
    Multiplier cos(Function f);
    Multiplier exp(Function f);
    Multiplier ln(Function f);
    Multiplier asin(Function f);
    int max(int k1, int k2);
    int min(int k1, int k2);
    int min_no_nul(int *a, int len);
    Huge operator*(const int &k, const Huge &h);
    int length_double(const double &d);
    int length_int(const int &d);
    int sign(const double &k);
    Huge sin(const Huge &y, const Huge &e);
    Huge cos(const Huge &y, const Huge &e);
    Huge exp(const Huge &y, const Huge &e);
    Huge ln(const Huge &y, const Huge &e);
    Huge asin(const Huge &y, const Huge &e);
    Multiplier operator*(double k, Variable y);
    Function operator+(Variable x, double d);
    Function operator+(Multiplier m1, Multiplier m2);
    Function operator+(Multiplier m1, double d);
    Function operator+(Multiplier m1, Variable x);
    Function operator+(Variable x1, Variable x2);
    int min_nul(int *length);
    Function operator-(Function f, Multiplier m);
    Function operator+(double d, Variable x);
    Function operator+(Multiplier m, Function f);
    Multiplier operator*(Function f1, Function f2);
    void set_argument(Function &f, Function f2);
    Multiplier operator*(double k, Multiplier m);
    Multiplier operator*(Variable x1, Variable x2);
    Multiplier operator*(Variable x, Multiplier m);
    Function operator*(double k, Function f);
    Multiplier operator*(Variable x, Function f);
    Multiplier operator*(Multiplier m, Function f);
    std::ostream &operator<<(std::ostream &out, Huge h);
    std::ostream &operator<<(std::ostream &out, Function f);
}

#endif
