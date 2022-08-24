#include <iostream>
#include <math.h>
#include "var.hpp"
#include "mul.hpp"
#include "fun.hpp"
namespace my
{
    using std::cout;
    bool Multiplier::check_farg()
    {
        if (f_arg == nullptr)
            return 0;
        else
            return 1;
    }

    Multiplier::Multiplier()
    {
        num = 1;
        for (int i = 0; i < 7; i++)
            a[i] = 0;
        for (int i = 0; i < 6; i++)
            arg[i] = nullptr;
        f_arg = nullptr;
    } 

    Multiplier::Multiplier(double k, Variable x)
    {
        var = x.get_name();
        num = k;
        a[0] = 1;
        for (int i = 1; i < 7; i++)
            a[i] = 0;
        for (int i = 0; i < 6; i++)
            arg[i] = nullptr;
        f_arg = nullptr;
    }

    Multiplier::Multiplier(Variable x)
    {
        var = x.get_name();
        num = 1;
        a[0] = 1;
        for (int i = 1; i < 7; i++)
            a[i] = 0;
        for (int i = 0; i < 6; i++)
            arg[i] = nullptr;
        f_arg = nullptr;
    }

    Multiplier::Multiplier(double k)
    {
        var = "";
        num = k;
        for (int i = 0; i < 7; i++)
            a[i] = 0;
        for (int i = 0; i < 6; i++)
            arg[i] = nullptr;
        f_arg = nullptr;
    }

    Multiplier::Multiplier(const Multiplier &m)
    {
        this->var = m.var;
        num = m.num;
        for (int i = 0; i < 7; i++)
            a[i] = m.a[i];
        for (int i = 0; i < 6; i++)
        {
            if (a[i + 1])
            {
                arg[i] = new Function [a[i + 1]];
                for (int j = 0; j < a[i + 1]; j++)
                    arg[i][j] = m.arg[i][j];
            }
            else
                arg[i] = nullptr;
        }
        if (m.f_arg == nullptr)
            f_arg = nullptr;
        else
        {
            f_arg = new Function;
            *f_arg = *(m.f_arg);
        }
    }
    Function Multiplier::get_f_arg()
    {
        Function f = *f_arg;
        return f;
    }
    string Multiplier::get_var()
    {
        return var;
    }

    void Multiplier::put_minus()
    {
        num *= -1;
    }

    Multiplier Multiplier::operator*(Variable y)
    {
        not_equal(y.get_name(), this->var);
        this->a[0] = this->a[0] + 1;
        return *this;
    }

    void Multiplier::set_var(Function f2)
    {
        if (f2.get_argument() == "")
            return;
        var = f2.get_argument();
        if (f_arg == nullptr)
            f_arg = new Function;  
        *f_arg = f2;
        for (int i = 0; i < 6; i++)
        {
            for (int k = 0; k < a[i + 1]; k++)
                set_argument(arg[i][k], f2);
        }
    }

    Multiplier::Multiplier(int *b, string s, Function fx, int n)
    {
        for (int i = 0; i < 7; i++)
            a[i] = b[i];
        num = 1;
        var = s;
        arg[n - 1] = new Function;
        arg[n - 1][0] = fx; 
        f_arg = nullptr;
        for (int i = 0; i < 6; i++)
            if (i != (n - 1))
                arg[i] = nullptr;
    }

    Multiplier::Multiplier(int *b, string s, Multiplier m, int n)
    {
        Function f(m);
        num = 1;
        for (int i = 0; i < 7; i++)
            a[i] = b[i];
        var = s;
        arg[n - 1] = new Function [1];
        arg[n - 1][0] = f; 
        f_arg = NULL;
        for (int i = 0; i < 6; i++)
            if (i != (n - 1))
                arg[i] = nullptr;
    }

    
    Multiplier Multiplier::operator=(Multiplier m)
    {
        num = m.num;
        for (int i = 0; i < 7; i++)
            a[i] = m.a[i];
        var = m.var;
        if (this == &m)
            return *this;
        for (int i = 0; i < 6; i++)
        {
            if (m.a[i + 1])
            {
                arg[i] = new Function [a[i + 1]];
                for (int j = 0; j < a[i + 1]; j++)
                    arg[i][j] = m.arg[i][j];
            }
            else
                arg[i] = nullptr;
        }
        if (m.f_arg == nullptr)
        {
            if (f_arg != nullptr)
                delete f_arg;
            f_arg = nullptr;
        }
        else
        {
            if (f_arg == nullptr)
                f_arg = new Function;
            *f_arg = *(m.f_arg);
        }
        return *this;
    }

    Multiplier Multiplier::operator*(Multiplier m)
    {
        int i, w[6];
        for(int j = 0; j < 6; j++)
            w[j] = a[j + 1];
        not_equal(m.get_var(), this->var);
        if (m.num)
            num *= m.num;
        for (i = 1; i < 7; i++)
            a[i] = a[i] + m.a[i];
        for (i = 0; i < 6; i++)
        {
            if (!m.a[i + 1])
                continue;
            Function *pf = new Function [w[i] + m.a[i + 1]];
            for (int u = 0; u < w[i]; u++)
                pf[u] = arg[i][u];
            for (int u = w[i]; u < w[i] + m.a[i + 1]; u++)
                pf[u] = m.arg[i][u - w[i]];
            if (w[i])
                delete [] arg[i];
            arg[i] = pf;
        }
        return *this;
    }

    Huge Multiplier::operator()(const Huge &h, Huge e)
    {
        int i;
        Huge pog(num);
        if (f_arg == nullptr)
            for (i = 0; i < a[0]; i++)
                pog = pog*h;
        else
            for (i = 0; i < a[0]; i++)
                pog = pog*((*f_arg)(h)); 
        for (i = 0; i < a[3]; i++)
                pog = pog*pow(3, (h.get_int() + 1));
        for (i = 0; i < a[4]; i++)
            pog = pog*20;
        for (i = 0; i < a[5]; i++)
            pog = pog*2;
        for (i = 0; i < a[6]; i++)
            pog = pog*(arg[5][i](h));
        Huge eps;
        if (pog > 0 || pog < 0)
            eps = e / pog;
        else
            eps = 0.0000001;
        Huge res(num);
        bool fl = 1;
        if (f_arg == nullptr)
            fl = 0;
        for (i = 0; i < a[0]; i++)
        {
            if (fl)
            {
                Huge w;
                w = (*f_arg)(h, eps);
                res = res * w;
            }
            else
                res = res * h;
        }
        for (i = 0; i < a[1]; i++)
            res = res * sin(arg[0][i](h, eps), eps);
        for (i = 0; i < a[2]; i++)
            res = res * cos(arg[1][i](h, eps), eps);
        for (i = 0; i < a[3]; i++)
            res = res * exp(arg[2][i](h, eps), eps);
        for (i = 0; i < a[4]; i++)
        {
            Function f(arg[3][i]);
            Huge k = f(h, eps);
            res = res * ln(k, eps);
        }
        for (i = 0; i < a[5]; i++)
            res = res * asin(arg[4][i](h, eps), eps);
        for (i = 0; i < a[6]; i++)
            res = res * arg[5][i](h, eps);
        return res;
    }

/*
Multiplier::~Multiplier()
{
    if (f_arg != NULL)
        delete f_arg;
    for (int i = 0; i < 6; i++)
        if (a[i + 1])
            delete [] arg[i];
} */

}
