#ifndef FUNC
#define FUNC

#include <stdio.h>
#include "var.hpp"
#include "mul.hpp"
#include "huge.hpp"
#include "dop.hpp"
namespace my
{
    class Function
    {
        Multiplier **mul;
        int *length;
        std::string argument; 
        Function *f_argument; 
      public:
        Function(const Function &f);
        Function(Multiplier m);
        Function();
        Function(std::string s);
        Function(Variable x);
        Function(double k);
        friend std::ostream &operator<<(std::ostream &out, Function f);
        friend Function operator+(Multiplier m1, Multiplier m2);
        friend Function operator+(Multiplier m, Function f);
        friend Function operator+(Variable x, double d);
        friend Function operator+(Multiplier m1, Variable x);
        friend Function operator+(Multiplier m1, double x);
        friend Function operator+(Variable x1, Variable x2);
        friend Multiplier operator*(Multiplier m, Function f);
        friend Multiplier operator*(Variable x, Function f);
        friend Multiplier operator*(Function f1, Function f2);
        friend Function operator*(double k, Function f);
        Function operator+(Multiplier m1);
        Function operator+(Function f);
        Function operator-(Function f);
        Function operator+(double k);
        Function operator()(Function f2);
        Huge operator()(const Huge &h, Huge e);
        Huge operator()(const Huge &h);
        Huge operator()(const double &h);
        Huge operator()(const int &h);
        Function operator=(Function f);
        friend Function operator-(Function f, Multiplier m);
        friend void set_argument(Function &f, Function f2);
        std::string get_argument();
    };

}
#endif
