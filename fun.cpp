#include <iostream>
#include <iomanip>
#include "var.hpp"
#include "mul.hpp"
#include "fun.hpp"
#include "huge.hpp"
#include "huge.hpp"

namespace my
{
    using std::string;
    using std::cout;
    Function::Function(Multiplier m)
    {
        length = new int [2];
        length[0] = 1;
        length[1] = 0;
        mul = new Multiplier* [1];
        mul[0] = new Multiplier [6];
        mul[0][0] = m;
        argument = m.get_var();
        if (m.check_farg())
        {
            f_argument = new Function [1];
            *f_argument = m.get_f_arg();
        }
        else 
            f_argument = nullptr;
    }
    Function::Function()
    {
        length = nullptr;
        mul = nullptr;
        f_argument = nullptr;
    }
    Function::Function(string s)
    {
        length = nullptr;
        mul = nullptr;
        argument = s;
        f_argument = nullptr;
    }
    Function::Function(Variable x)
    {
        length = new int [2];
        length[0] = 1;
        length[1] = 0;
        mul = new Multiplier* [1];
        mul[0] = new Multiplier [6];
        mul[0][0] = x;
        argument = x.get_name();
        f_argument = nullptr;
    }
    Function::Function(double k)
    {
        length = new int [2];
        length[0] = 1;
        length[1] = 0;
        mul = new Multiplier* [1];
        mul[0] = new Multiplier [6];
        mul[0][0] = k;
        argument = "";
        f_argument = nullptr;
    }
    Function Function::operator+(double k)
    {
        Function f = *this;
        Multiplier m(k);
        f.mul[0][length[0]] = m;
        f.length[0]++;
        return f; 
    }
    Function Function::operator+(Multiplier m)
    {
        not_equal(argument, m.get_var());
        if (f_argument != nullptr)
        {
            Function tm(m);
            return *this + tm;
        }
        Function f = *this;
        f.argument = m.get_var();
        f.mul[0][length[0]] = m;
        f.length[0]++;
        return f; 
    }

    Function Function::operator+(Function f)
    {
        int i;
        not_equal(argument, f.argument);
        Function tmpf = *this;
        if (tmpf.argument == "")
            tmpf.argument = f.argument;
        int l1 = min_nul(tmpf.length);
        int l2 = min_nul(f.length);
        int *len;
        len = new int [l1 + l2 + 1];
        for (i = 0; i < l1; i++)
            len[i] = tmpf.length[i];
        for (i = 0; i < l2; i++)
            len[i + l1] = f.length[i];
        len[l1 + l2] = 0;
        delete [] tmpf.length;
        tmpf.length = len;
        int num = 0;
        Multiplier **mult;
        mult = new Multiplier* [l1 + l2];
        for (i = 0; i < l1; i++)
        {
            mult[i] = new Multiplier [6];
            for (int j = 0; j < tmpf.length[i]; j++)
                mult[i][j] = tmpf.mul[i][j];
            delete [] tmpf.mul[i];
        }
        for (i = 0;  i < l2; i++)
        {
            mult[i + l1] = new Multiplier [6];
            for (int j = 0; j < tmpf.length[i]; j++)
                mult[i + l1][j] = f.mul[i][j];
        }
        delete [] tmpf.mul;
        tmpf.mul = mult;
        if ((tmpf.f_argument == nullptr) && (tmpf.f_argument == nullptr))
            return tmpf;
        Function *far = new Function [l1 + l2];
        if (tmpf.f_argument == nullptr) {
            for (i = 0; i < l1; i++)
                far[i] = 0;
        }
        else {
            for (i = 0; i < l1; i++)
                far[i] = tmpf.f_argument[i];
        }
        if (f.f_argument == nullptr) {
            for (i = 0; i < l2; i++)
                far[i + l1] = 0;
        }
        else {
            for (i = 0; i < l2; i++)
                far[i + l1] = f.f_argument[i];
        }
        delete [] tmpf.f_argument;
        tmpf.f_argument = far;
        return tmpf;
    }
    Function Function::operator-(Function f)
    {
        Function tmpf;
        tmpf = *this + f;
        int k1 = min_nul(length);
        int k2 = min_nul(tmpf.length);
        for (int i = k1; i < k2; i++)
            for (int j = 0; j < f.length[i - k1]; j++)
                (tmpf.mul[i][j]).put_minus();
        return tmpf;
    }
    Function::Function (const Function &f)
    {
        int k = 1;
        int l = min_nul(f.length);
        length = new int [l + 1];
        for (int i = 0; i < l; i++)
            length[i] = f.length[i];
        length[l] = 0;
        argument = f.argument;
        int num = 0;
        mul = new Multiplier* [l];
        if (f.f_argument == nullptr)
        {
            f_argument = nullptr;
            k = 0;
        }
        else
            f_argument = new Function [l];
        while (f.length[num])
        {
            mul[num] = new Multiplier [6];
            for (int i = 0; i < f.length[num]; i++)
                mul[num][i] = f.mul[num][i];  
            if (k)
                f_argument[num] = f.f_argument[num];
            num++;
        }
    }
    Function Function::operator=(Function f)
    {
        int k = 1;
        int l = min_nul(f.length);
        length = new int [l + 1];
        for (int i = 0; i < l; i++)
            length[i] = f.length[i];
        length[l] = 0;
        if (f.argument == "")
            argument = "";
        else 
            argument = f.argument;
        int num = 0;
        mul = new Multiplier* [l];
        if (f.f_argument == nullptr)
        {
            f_argument = nullptr;
            k = 0;
        }
        else
            f_argument = new Function [l];
        while (f.length[num])
        {
            mul[num] = new Multiplier [6];
            for (int i = 0; i < f.length[num]; i++)
                mul[num][i] = f.mul[num][i];  
            if (k)
                f_argument[num] = f.f_argument[num];
            num++;
        }
        return *this;
    }


    Function Function::operator()(Function f2)
    {
        Function f;
        f = *this;
        if (argument == "")
            return *this;
        set_argument(f, f2);
        return f;
    }

    string Function::get_argument()
    {
        return argument;
    }

    Huge Function::operator()(const int &h)
    {
        Multiplier m;
        Huge res(0);
        int k = 0, i;
        int len = min_nul(length), q = 0;
        int e = std::cout.precision();
        Huge eps(1);
        for (i = 0; i < e; i++)
            eps = eps/10;
        for (int i = 0; i < len; i++)
            q += length[i];
        if (q)
            eps = eps/q;
        while (length[k])
        {
            for (i = 0; i < length[k]; i++)
            {
                m = mul[k][i];
                res = res + m(h, eps);
            }
            k++;
        }
        return res;
    }
    Huge Function::operator()(const double &h)
    {
        Multiplier m;
        Huge res(0);
        int k = 0, i;
        int len = min_nul(length), q = 0;
        int e = std::cout.precision();
        Huge eps(1);
        for (i = 0; i < e; i++)
            eps = eps/10;
        for (int i = 0; i < len; i++)
            q += length[i];
        if (q)
            eps = eps/q;
        while (length[k])
        {
            for (i = 0; i < length[k]; i++)
            {
                m = mul[k][i];
                res = res + m(h, eps);
            }
            k++;
        }
        return res;
    }
    Huge Function::operator()(const Huge &h, Huge e)
    {
        Multiplier m;
        Huge res(0);
        int k = 0, i;
        int len = min_nul(length), q = 0;
        Huge eps(e);
        for (int i = 0; i < len; i++)
            q += length[i];
        if (q)
            eps = eps/q;
        while (length[k])
        {
            for (i = 0; i < length[k]; i++)
            {
                m = mul[k][i];
                res = res + m(h, eps);
            }
            k++;
        }
        return res;
    }
    Huge Function::operator()(const Huge &h)
    {
        Multiplier m;
        Huge res(0);
        int k = 0, i;
        int len = min_nul(length), q = 0;
        int e = std::cout.precision();
        Huge eps(1);
        for (i = 0; i < e; i++)
            eps = eps/10;
        for (int i = 0; i < len; i++)
            q += length[i];
        if (q)
            eps = eps/q;
        while (length[k])
        {
            for (i = 0; i < length[k]; i++)
            {
                m = mul[k][i];
                res = res + m(h, eps);
            }
            k++;
        }
        return res;
    }

}


