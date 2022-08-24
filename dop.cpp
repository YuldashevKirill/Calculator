#include <iostream>
#include "var.hpp"
#include "mul.hpp"
#include "fun.hpp"
#include "huge.hpp"
#include "dop.hpp"
namespace my
{
    using std::cout;
    using std::string;
    void not_equal(string s1, string s2)
    {
        if (s1.empty() || s2.empty())
            return;
        if (s1 != s2)
        {
            cout << "Error! Different variables!!!" << endl;
            exit(0);
        }
    }
    Multiplier sin(Variable x) {
        Multiplier m(x);
        int a[7] = {0, 1, 0, 0, 0, 0, 0};
        Multiplier m1(a, x.get_name(), m, 1);
        return m1;
    }
    Multiplier sin(Multiplier m)
    {
        int a[7] = {0, 1, 0, 0, 0, 0, 0};
        Multiplier m1(a, m.get_var(), m, 1);
        return m1;
    }
    Multiplier cos(Variable x) 
    {
        Multiplier m(x);
        int a[7] = {0, 0, 1, 0, 0, 0, 0};
        Multiplier m1(a, x.get_name(), m, 2);
        return m1;
    }
    Multiplier cos(Multiplier m)
    {
        int a[7] = {0, 0, 1, 0, 0, 0, 0};
        Multiplier m1(a, m.get_var(), m, 2);
        return m1;
    }
    Multiplier exp(Variable x) 
    {
        Multiplier m(x);
        int a[7] = {0, 0, 0, 1, 0, 0, 0};
        Multiplier m1(a, x.get_name(), m, 3);
        return m1;
    }
    Multiplier exp(Multiplier m)
    {
        int a[7] = {0, 0, 0, 1, 0, 0, 0};
        Multiplier m1(a, m.get_var(), m, 3);
        return m1;
    }
    Multiplier ln(Variable x) 
    {
        Multiplier m(x);
        int a[7] = {0, 0, 0, 0, 1, 0, 0};
        Multiplier m1(a, x.get_name(), m, 4);
        return m1;
    }
    Multiplier ln(Multiplier m)
    {
        int a[7] = {0, 0, 0, 0, 1, 0, 0};
        Multiplier m1(a, m.get_var(), m, 4);
        return m1;
    }
    Multiplier asin(Variable x) 
    {
        Multiplier m(x);
        int a[7] = {0, 0, 0, 0, 0, 1, 0};
        Multiplier m1(a, x.get_name(), m, 5);
        return m1;
    }
    Multiplier asin(Multiplier m)
    {
        int a[7] = {0, 0, 0, 0, 0, 1, 0};
        Multiplier m1(a, m.get_var(), m, 5);
        return m1;
    }
    Multiplier sin(Function f)
    {
        int a[7] = {0, 1, 0, 0, 0, 0, 0};
        Multiplier m(a, f.get_argument(), f, 1);
        return m;
    }
    Multiplier cos(Function f)
    {
        int a[7] = {0, 0, 1, 0, 0, 0, 0};
        Multiplier m(a, f.get_argument(), f, 2);
        return m;
    }
    Multiplier exp(Function f)
    {
        int a[7] = {0, 0, 0, 1, 0, 0, 0};
        Multiplier m(a, f.get_argument(), f, 3);
        return m;
    }
    Multiplier ln(Function f)
    {
        int a[7] = {0, 0, 0, 0, 1, 0, 0};
        Multiplier m(a, f.get_argument(), f, 4);
        return m;
    }
    Multiplier asin(Function f)
    {
        int a[7] = {0, 0, 0, 0, 0, 1, 0};
        Multiplier m(a, f.get_argument(), f, 5);
        return m;
    }
    int max(int k1, int k2)
    {
        if (k1 > k2)
            return k1;
        return k2;
    }
    int min(int k1, int k2)
    {
        if (k1 < k2)
            return k1;
        return k2;
    }
    int min_no_nul(int *a, int len)
    {
        int i = 0;
        for (int i = 0; i < len; i++)
            if (a[i])
                return i;
        return -1;
    } 
    Huge operator*(const int &k, const Huge &h)
    {
        return h*k;
    }
    int length_double(const double &d)
    {
        int l = 0;
        int k = (int) d;
        double re = d - k;
        while (k)
        {
            k = k/10;
            l++;
        }
        while (re)
        {
            re *= 10;
            k = (int) re;
            re = re - k;
            l++;
        }
        return l;
    }
    int length_int(const int &d)
    {
        int k = 0, r = d;
        while (r)
        {
            r /= 10;
            k++;
        }
        return k;
    }
    int sign(const double &k)
    {
        if (k < 0)
            return -1;
        if (!k)
            return 0;
        return 1;
    }
    Huge sin(const Huge &y, const Huge &e)
    {
        Huge res(0), tmp(y), accur(y);
        int k = 2;
        while (accur.modul() > e.modul())
        {
            res = res + tmp;
            tmp = tmp*(-y)*y/(k*(k + 1));
            accur = accur*y*y/(k*(k + 1));
            k += 2;
        }
        return res;
    }
    Huge cos(const Huge &y, const Huge &e)
    {
        Huge res(0), tmp(1), accur(1);
        int k = 1;
        while (accur.modul() > e.modul())
        {
            res = res + tmp;
            tmp = tmp * (-y) * y / (k * (k + 1));
            accur = accur*y*y/(k*(k+1));
            k += 2;
        }
        return res;
    }
    Huge exp(const Huge &y, const Huge &e)
    {
        Huge res(0), tmp(1), accur(1);
        int k = 1;
        while (accur.modul() > e.modul())
        {
            res = res + tmp;
            tmp = tmp * y / k;
            accur = accur * y / k;
            k++;
        }
        return res;
    }
    Huge ln(const Huge &y, const Huge &e)
    {
        if (y == 1)
        {
            Huge res(0);
            return res;
        }
        if (y > 2)
        {
            cout << "You are going outside radius, wrong answer: ";
            return 0; //?
        }
        if (y < 0 || y == 0)
        {
            cout << " ln doesn't live,  wrong answer: ";
            return 0;
        }
        Huge res(0), tmp(y - 1), mn(y - 1), accur;
        int k = 2; bool fl = 0;
        if (mn > 0)
        {
            fl = 1;
            accur = mn;
        }
        else
            accur = mn/((-y) + 1);
        while (accur.modul() > e.modul())
        {
            res = res + tmp;
            tmp = tmp * (-mn) * (k - 1)/ k;
            if (fl)
                accur = accur * mn * (k - 1) / k;
            else
                accur = accur * mn;
            k++;
        }
        return res;
    }
    Huge asin(const Huge &y, const Huge &e)
    {
        if (y.modul() > 1)
        {
            cout << "You are going outside radius. Wrong answer: ";
            return 0; //???
        }
        Huge res(0), tmp(y), accur(1);
        int k = 1;
        while (accur.modul() > e.modul())
        {
            res = res + tmp;
            tmp = tmp * y * y * k * k / ((k + 1)*(k + 2));
            accur = accur * y * k / (k + 1);
            k += 2;
        }
        return res;
    }
    Multiplier operator*(double k, Variable y)
    {
        Multiplier tmp(k, y);
        tmp.var = y.get_name();
        return tmp;
    }
    Function operator+(Variable x, double d)
    {
        Function w(x.get_name());
        w.length = new int [2];
        w.length[0] = 2;
        w.length[1] = 0;
        w.mul = new Multiplier* [1];
        w.mul[0] = new Multiplier [6];
        w.mul[0][0] = x;
        w.mul[0][1] = d;
        return w;
    }
    Function operator+(Multiplier m1, Multiplier m2)
    {
        not_equal(m1.get_var(), m2.get_var());
        string s;
        if (m1.get_var() != "")
            s = m1.get_var();
        else 
            s = m2.get_var();
        Function w(s);
        w.length = new int [2];
        w.length[0] = 2;
        w.length[1] = 0;
        w.mul = new Multiplier* [1];
        w.mul[0] = new Multiplier [6];
        w.mul[0][0] = m1;
        w.mul[0][1] = m2;
        return w;
    }
    Function operator+(Multiplier m1, double d)
    {
        Multiplier m2(d);
        return m1 + m2;
    }
    Function operator+(Multiplier m1, Variable x)
    {
        Multiplier m2(x);
        return m1 + m2;
    }
    Function operator+(Variable x1, Variable x2)
    {
        Multiplier m1(x1), m2(x2);
        return m1 + m2;
    }
    int min_nul(int *length)
    {
        int i = 0;
        while (length[i])
           i++;
        return i;
    } 
    Function operator-(Function f, Multiplier m)
    {
        not_equal(f.get_argument(), m.get_var());
        Function tmpf = f;
        if (f.argument == "")
            tmpf.argument = m.get_var();
        m.num *= -1;
        if (f.f_argument != nullptr)
        {
            Function tm(m);
            return f + tm;
        }
        tmpf.mul[0][tmpf.length[0]] = m;
        tmpf.length[0]++;
        return tmpf; 
    }
    Function operator+(double d, Variable x)
    {
        Function tmpf(x);
        tmpf = tmpf + d;
        return tmpf;
    }
    Function operator+(Multiplier m, Function f)
    {
        if (f.f_argument != nullptr)
        {
            Function tm(m);
            return f + tm;
        }
        Function tmpf(f);
        tmpf = tmpf + m;
        return tmpf;
    }
    Multiplier operator*(Function f1, Function f2)
    {
        not_equal(f1.argument, f2.argument);
        Multiplier m;
        m.var = f1.argument;
        m.a[6] = 2;
        m.arg[5] = new Function [2];
        m.arg[5][0] = f1;
        m.arg[5][1] = f2;
        return m;
    }
    void set_argument(Function &f, Function f2)
    {
        if (f2.get_argument() == "")
            return;
        int l = min_nul(f.length);
        f.argument = f2.argument;
        if (f.f_argument == nullptr)
            f.f_argument = new Function [l];
        for (int i = 0; i < l; i++)
            f.f_argument[i] = f2;
        int num = 0;
        while (f.length[num])
        {
            for (int i = 0; i < f.length[num]; i++)  
                f.mul[num][i].set_var(f2);
            num++;
        }
    }
    Multiplier operator*(double k, Multiplier m)
    {
        Multiplier tmp;
        tmp = m;
        tmp.num *= k;
        return tmp;
    }
    Multiplier operator*(Variable x1, Variable x2)
    {
        not_equal(x1.get_name(), x2.get_name());
        Multiplier tmp(x1);
        tmp = tmp * x2;
        return tmp;
    }
    Multiplier operator*(Variable x, Multiplier m)
    {
        not_equal(x.get_name(), m.get_var());
        Multiplier tmp;
        tmp = m;
        tmp.a[0]++;
        return tmp;
    }
    Function operator*(double k, Function f)
    {
        Function tmpf(f);
        int n = 0;
        while (tmpf.length[n])
        {
            for (int i = 0; i < tmpf.length[n]; i++)
                tmpf.mul[n][i].num *= k;
            n++;
        }
        return tmpf;
    }
    Multiplier operator*(Variable x, Function f)
    {
        Multiplier m(x);
        m = m * f;
        return m;
    }

    Multiplier operator*(Multiplier m, Function f)
    {
        int i;
        not_equal(m.get_var(), f.get_argument());
        Function *pf = new Function [m.a[6] + 1];
        for (i = 0; i < m.a[6]; i++)
            pf[i] = m.arg[5][i];
        pf[i] = f;
        if (m.a[6])
            delete [] m.arg[5];
        m.arg[5] = pf;
        m.a[6]++;
        return m;
    }
    std::ostream &operator<<(std::ostream &out, Huge h)
    {
        int i, l, r;
        int accur = std::cout.precision();
        int ac = 0;
        if (!h.len)
        {
            out << 0;
            return out;
        }
        if (h.sgn < 0)
            out << "-";
        if (h.exp <= 0)
        {
            out << "0,";
            for (i = h.exp; i < 0; i++)
            {
                ac++;
                out << 0;
                if (ac >= accur)
                    return out;
            }
            for (i = 0; i < h.len; i++)
            {
                ac++;
                out << h.ar[i];
                if (ac >= accur)
                    return out;
            }
        }
        else
        {
            for (i = 0; i < h.len; i++)
            {
                if (i == h.exp)
                    break;
                out << h.ar[i];
            }
            if (h.len == h.exp)
                return out;
            if (h.len < h.exp)
            {
                for (i = 0; i < h.exp - h.len; i++)
                    out << "0";
                return out;
            }    
            out << ",";
            for (i = h.exp; i < h.len; i++)
            {
                ac++;
                out << h.ar[i];
                if (ac >= accur)
                    return out;
            }
        }
        return out;
    } 
    std::ostream &operator<<(std::ostream &out, Function f) 
    {
        int w[7], i, fl;
        int qw = 0;
        while (f.length[qw])
        {
            if (f.f_argument != nullptr && f.f_argument[qw].length[0] && f.f_argument[qw].mul[0][0].num
                && !(f.f_argument[qw].mul[0][0].num == 1 && f.f_argument[qw].mul[0][0].a[0] == 1 && 
                    !(f.f_argument[qw].mul[0][0].a[1] + f.f_argument[qw].mul[0][0].a[2] +
                     f.f_argument[qw].mul[0][0].a[3] + f.f_argument[qw].mul[0][0].a[4] +
                     f.f_argument[qw].mul[0][0].a[5] + f.f_argument[qw].mul[0][0].a[6])))
            {
                Function ar;
                ar = f.f_argument[qw];
                for (int j = 0; j < f.length[qw]; j++)
                {
                    fl = 1;
                    for (i = 0; i < 7; i++)
                        w[i] = f.mul[qw][j].a[i];
                    if (f.mul[qw][j].num)
                        if (f.mul[qw][j].num != 1)
                            out << f.mul[qw][j].num;
                        else
                            if (!(w[0]+w[1]+w[2]+w[3]+w[4]+w[5]+w[6]))
                               out << f.mul[qw][j].num;
                            else
                               fl = 0;
                    if (w[0])
                    {
                        if (fl)
                            out << "*";
                        else 
                            fl = 1;
                        out << '(' << ar << ')';
                        for (i = 1; i < w[0]; i++)
                            out << "*" << '(' << ar << ')';
                    }
                    if (w[1])
                    {
                        if (fl)
                            out << "*";
                        else 
                            fl = 1;
                        out << "sin(" << f.mul[qw][j].arg[0][0]  << ")";
                        for (i = 1; i < w[1]; i++)
                            out << "*sin(" << f.mul[qw][j].arg[0][i]  << ")";
                    }
                    if (w[2])
                    {
                        if (fl)
                            out << "*";
                        else 
                            fl = 1;
                        out << "cos(" << f.mul[qw][j].arg[1][0]  << ")";
                        for (i = 1; i < w[2]; i++)
                            out << "*cos(" << f.mul[qw][j].arg[1][i] << ")";
                    }
                    if (w[3])
                    {
                        if (fl)
                        out << "*";
                        else 
                            fl = 1;
                        out << "exp(" << f.mul[qw][j].arg[2][0]  << ")";
                       for (i = 1; i < w[3]; i++)
                            out << "*exp(" << f.mul[qw][j].arg[2][i] << ")";
                    }
                    if (w[4])
                    {
                        if (fl)
                            out << "*";
                        else 
                            fl = 1;
                        out << "ln(" << f.mul[qw][j].arg[3][0]  << ")";
                        for (i = 1; i < w[4]; i++)
                            out << "*ln(" << f.mul[qw][j].arg[3][i] << ")";
                    }
                    if (w[5])
                    { 
                        
                        if (fl)
                            out << "*";
                        else 
                            fl = 1;
                        out << "asin(" << f.mul[qw][j].arg[4][0]  << ")";
                        for (i = 1; i < w[5]; i++)
                            out << "*asin(" << f.mul[qw][j].arg[4][i] << ")";
                    }
                    if (w[6])
                    {
                        if (fl)
                            out << "*";
                        else
                            fl = 1;
                        out << "(" << f.mul[qw][j].arg[5][0] << ")";
                        for (i = 1; i < w[6]; i++)
                            out << "*(" << f.mul[qw][j].arg[5][i] << ")";
                    }
                    if (((f.length[qw] - j) != 1) && (f.mul[qw][j + 1].num > 0))
                        out << '+';
                }
                if (((f.length[qw+1])) && (f.mul[qw+1][0].num > 0))
                    out << '+';
            }   
            else
            {
                string st = f.argument;
                for (int j = 0; j < f.length[qw]; j++)
                {
                    fl = 1;
                    for (i = 0; i < 7; i++)
                        w[i] = f.mul[qw][j].a[i];
                    if (f.mul[qw][j].num)
                        if (f.mul[qw][j].num != 1)
                            out << f.mul[qw][j].num;
                        else
                            if (!(w[0]+w[1]+w[2]+w[3]+w[4]+w[5]+w[6]))
                                out << f.mul[qw][j].num;
                            else
                                fl = 0;
                    if (w[0])
                    {
                        if (fl)
                            out << "*";
                        else 
                            fl = 1;
                        out << st;
                        for (i = 1; i < w[0]; i++)
                            out << "*" << st;
                    }
                    if (w[1])
                    {
                        if (fl)
                            out << "*";
                        else 
                            fl = 1;
                        out << "sin(" << f.mul[qw][j].arg[0][0]  << ")";
                        for (i = 1; i < w[1]; i++)
                            out << "*sin(" << f.mul[qw][j].arg[0][i]  << ")";
                    }
                    if (w[2])
                    {
                        if (fl)
                            out << "*";
                        else 
                            fl = 1;
                        out << "cos(" << f.mul[qw][j].arg[1][0]  << ")";
                        for (i = 1; i < w[2]; i++)
                            out << "*cos(" << f.mul[qw][j].arg[1][i] << ")";
                    }
                    if (w[3])
                    {
                        if (fl)
                            out << "*";
                        else 
                            fl = 1;
                        out << "exp(" << f.mul[qw][j].arg[2][0]  << ")";
                        for (i = 1; i < w[3]; i++)
                            out << "*exp(" << f.mul[qw][j].arg[2][i] << ")";
                    }
                    if (w[4])
                    {
                        if (fl)
                            out << "*";
                        else 
                            fl = 1;
                        out << "ln(" << f.mul[qw][j].arg[3][0]  << ")";
                        for (i = 1; i < w[4]; i++)
                            out << "*ln(" << f.mul[qw][j].arg[3][i] << ")";
                    }
                    if (w[5])
                    {
                        if (fl)
                            out << "*";
                        else 
                            fl = 1;
                        out << "asin(" << f.mul[qw][j].arg[4][0]  << ")";
                        for (i = 1; i < w[5]; i++)
                            out << "*asin(" << f.mul[qw][j].arg[4][i] << ")";
                    }
                    if (w[6])
                    {
                        if (fl)
                            out << "*";
                        else 
                            fl = 1;
                        out << "(" << f.mul[qw][j].arg[5][0]  << ")";
                        for (i = 1; i < w[6]; i++)
                            out << "*(" << f.mul[qw][j].arg[5][i] << ")";
                    }
                    if (((f.length[qw] - j) != 1) && (f.mul[qw][j + 1].num > 0))
                        out << '+';
                } 
                if (((f.length[qw+1])) && (f.mul[qw+1][0].num > 0))
                    out << '+';
            } 
            qw++;   
        }
        return out;
    } 

}
