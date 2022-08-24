#include <iostream>
#include <iomanip>
#include "var.hpp"
#include "mul.hpp"
#include "fun.hpp"
#include "huge.hpp"
#include "dop.hpp"

using namespace my;
int main()
{
    Variable x("x"), y("y"); 
    Function f = y*y - 2*y*y;
    cout << f << endl;
    Variable z("zz");
    cout << f(z) << endl;
    Function h = y + sin(y);
    cout << setprecision(6) << h(1) << endl;
    cout << h(2*y) + h(y*y*y) + h(y*y) + h(cos(y)) << endl;
    h = y + y;
    cout << h << endl;
    Function h1 = y;
    cout << h1(y*y) << endl;
    Function h2 = cos(y)*asin(y);
    cout << y*h1(y)*h2(y) << endl;  
    Function j = 2*x*sin(3*x*sin(x)+cos(2*x)) + 3*x*cos(3*x*x*x);
    cout << h << endl;
    cout << j << endl;
    h1 = h1 + 3*y;
    cout << h1 << endl;
    cout << h1(y*y) << endl;
    cout << h1(3*x*x) << endl;
    cout << h1(6+cos(x)) << endl;
    f = 3*x - 2*x*x;
    cout << f << endl;
    cout << f(x) << endl;
    cout << f(2+x*x) << endl;
    cout << f(y) << endl;
    cout << endl << endl;
    Function g = sin(x)*sin(x) + cos(x)*cos(x);
    h = exp(y) + ln(2 + y*y);
    cout << g << endl;
    cout << h << endl;
    Function g1 = 3*x + sin(x*x);
    Function g2 = asin(x)*x;
    cout << g1(g2) + h(x) << endl;
    cout << h << endl;
    h = h(2*y) + 2*exp(h(y*y)); // doesn't work h = h + 2*exp(h(y*y))
    cout << h << endl; 
    h = y + sin(y);
    cout << h << endl;
    cout << h(y*y) << endl;
    cout << h(cos(y)) << endl;
    cout << h + h << endl;
    cout << h(2*y) + h(y*y) << endl;
    cout << h << endl;
    cout << h - 6*h << endl;
    h = exp(y) + ln(1 - 3*y*y);
    cout << h << endl;
    cout << h << endl;
    h = h + 2*exp(h(y*y))*cos(sin(h))*y;
    cout << h << endl; 
    h = exp(y) + 2*y*cos(y);
    cout << 2 + h(2*y) << endl;
    cout << y + h(2*y) << endl;
    f = 3.7*x*x*cos(x);
    cout << 1 + f(x*x) << endl;
    h = y*y*h(y);
    cout << h << endl;
    h = sin(y)*h(y);
    cout << h << endl;
    h = 2*h(y);
    cout << h << endl;
    h = 3*h(y*y);
    cout << h << endl;
    f = x + cos(x);
    cout << f(cos(y)) << endl; 
    f = 3.7*x*x*cos(x);
    cout << f << endl; 
    cout << f(0.7) << endl;
    h = f(ln(y));
    cout << h << endl;
    cout << h(0.7) << endl;
    h = f(cos(ln(y))) + f(exp(y*y));
    cout << h << endl;
    cout << h(0.7) << endl;
    h = ln(y);
    cout << h(0.7) << endl; 
    f = 3*x*x - 2*x;
    g = sin(x)*sin(x) + cos(x)*cos(x);
    h = exp(y) + ln(1 - y*y);
    h = h + 2.5*exp(h(y*y))*cos(sin(h))*y;
    //h = h + g;  if delete comment, it will be error
    h = h(x) + g(x);
    cout << f(1)  << endl;
    f = asin(x);
    g = exp(x);
    cout << setprecision(5) << 6*f(0.5) << ' ' << endl << g(1) << endl; 
    cout << setprecision(10) << 6*f(0.5) << ' ' << endl << g(1) << endl; 
    cout << setprecision(100) << g(1) << endl;
    cout << setprecision(100) << 6*f(0.5) << endl;
    Huge H(1);
    for (int i = 0; i < 5000; i++)
        H = H * 10;
    cout << H << endl;
    return 0;
}
