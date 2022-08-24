#ifndef MUL
#define MUL

#include <iostream>
#include "var.hpp"
#include "fun.hpp"
namespace my 
{
    class Multiplier
    {
        double num;
        int a[7];
        std::string var;
        Function *f_arg;
        Function *arg[6];
      public:
        Multiplier();
        Multiplier(double k);
        Multiplier(double k, Variable x);
        Multiplier(int *b, std::string s, Multiplier m, int num);
        Multiplier(int *b, std::string s, Function fx, int num);
        Multiplier(Variable x);
        Multiplier(const Multiplier &m);
        friend Function operator-(Function f, Multiplier m1);
        friend Multiplier operator*(double k, Variable y);
        friend Multiplier operator*(double k, Multiplier m);
        friend Multiplier operator*(Variable x1, Variable x2);
        friend Multiplier operator*(Variable x, Multiplier m);
        friend Multiplier operator*(Multiplier m, Function f);
        friend Multiplier operator*(Function f1, Function f2);
        friend Function operator*(double k, Function f);
        friend void set_argument(Function &f, Function f2);
        Multiplier operator*(Variable x);
        Multiplier operator*(Multiplier m);
        Multiplier operator=(Multiplier m);
        Huge operator()(const Huge &d, Huge e);
        string get_var();
        bool check_farg();
        Function get_f_arg();
        void set_var(Function f2);
        void put_minus();
        friend std::ostream &operator<<(std::ostream &out, Function f);
        //~Multiplier();
    };

}
#endif
