#include <iostream>
#include "huge.hpp"
#include "dop.hpp"
namespace my
{
    using std::string;
    void Huge::clean_nul()
    {
        int l = len;
        for (int i = l - 1; i >= 0; i--)
            if (ar[i])
                return;
            else
                len--;
    }
    int Huge::get_int() const
    {
        int res = 0, i;
        if (exp <= 0)
            return 0;
        for (i = 0; i < exp; i++)
            if (i < len)
                res = res*10 + ar[i];
            else
                break;
        if (i == len)
            for (int i = len; i < exp; i++)
                res *= 10;
        return res;
    }
    Huge::~Huge()
    {
        delete [] ar;
    }
    Huge Huge::operator-() const
    {
        Huge h;
        h = *this;
        h.sgn *= -1;
        return h;
    }
    Huge Huge::modul() const
    {
        Huge h(*this);
        h.sgn = 1;
        return h;
    }

    bool Huge::operator>(const Huge &h) const
    {
        if (sgn != h.sgn)
            return sgn > h.sgn;
        if (!sgn)
            return false;
        if (exp != h.exp)
            if (sgn > 0)
                return exp > h.exp;
            else
                return exp < h.exp;
        int l = min(len, h.len);
        for (int i = 0; i < l; i++)
            if (ar[i] != h.ar[i])
                if ((ar[i] > h.ar[i] && sgn > 0) || (ar[i] < h.ar[i] && sgn < 0))
                    return true;
                else
                    return false;
        if (len - h.len == 0)
            return false;
        Huge h1(*this), h2(h);
        h1.clean_nul();
        h2.clean_nul();
        l = min(h1.len, h2.len);
        if ((l == h1.len && sgn > 0) || (l == h2.len && sgn < 0))
            return false;
        return true;
    }
    bool Huge::operator==(const Huge &h) const
    {
        if (*this > h || h > *this)
            return false;
        return true;
    }
    bool Huge::operator>=(const Huge &h) const
    {
        if (*this > h || *this == h)
            return true;
        return false;
    }
    bool Huge::operator!=(const Huge &h) const
    {
        if (*this == h)
            return false;
        return true;
    }
    bool Huge::operator<(const Huge &h) const
    {
        if (*this >= h)
            return false;
        return true;
    }
    Huge Huge::reverse() const
    {
        int L = 100;
        if (!sgn)
        {
            cout << "div 0 ERROR" << endl;
            exit;
        }
        Huge div(*this), fir(1), res; int t;
        res.sgn = div.sgn;
        div.sgn = 1;
        res.exp = 1;
        res.ar = new int [L];
        while (div < 1)
        {
            div.exp++;
            res.exp++;
        }
        while (fir < div)
            fir.exp++;
        res.exp -= fir.exp - 1;
        int num = 0;
        int total = L;
        do
        {
            t = 0;
            while (fir >= div)
            {
                t++;
                if (t > 9)
                    break;
                fir = fir - div;
            }
            res.ar[num] = t;
            fir.exp++;
            num++;
        }
        while (fir != 0 && num < total);
        res.len = num;
        res.clean_nul();
        return res;
    }
    Huge Huge::operator/(const Huge &h) const
    {
        Huge res = *this * h.reverse();
        return res;
    }
    Huge Huge::operator+(const Huge &h) const
    {
        Huge res;
        int diff, i, l;
        if (!sgn)
        {
            res = h;
            return res;
        }
        if (!h.sgn)
        {
            res = *this;
            return res;
        }
        if (sgn > 0 && h.sgn > 0 || sgn < 0 && h.sgn < 0)
        {
            res.sgn = sgn;
            res.exp = max(exp, h.exp);
            diff = abs(exp - h.exp);
            if (sgn > 0 && *this > h || sgn < 0 && h > *this)
            {
                l = max(len, h.len + diff);
                res.ar = new int [l + 1];
                for (i = 0; i < l + 1; i++)
                    res.ar[i] = 0;
                for (i = 0; i < diff; i++)
                    if (i < len)
                        res.ar[i] += ar[i];
                    else
                        break;
                for (i = diff; i < l; i++)
                {
                    if (i < len)
                        res.ar[i] += ar[i];
                    if (i - diff < h.len)
                        res.ar[i] += h.ar[i - diff];
                }
            }
            else
            {
                l = max(len + diff, h.len);
                res.ar = new int [l + 1];
                for (i = 0; i < l + 1; i++)
                    res.ar[i] = 0;
                for (i = 0; i < diff; i++)
                    if (i < h.len)
                        res.ar[i] += h.ar[i];
                    else
                        break;
                for (i = diff; i < l; i++)
                {
                    if (i < h.len)
                        res.ar[i] += h.ar[i];
                    if (i - diff < len)
                        res.ar[i] += ar[i - diff];
                } 
            } 
            res.len = l;
            for (i = l; i >= 1; i--)
                if (res.ar[i] >= 10)
                {
                    res.ar[i - 1] += res.ar[i]/10;
                    res.ar[i] = res.ar[i]%10;
                }
            if (res.ar[0] > 9)
            {
                for (i = l; i >= 1; i--)
                    res.ar[i] = res.ar[i - 1];
                
                res.ar[0] = res.ar[1]/10;
                res.ar[1] = res.ar[1]%10; 
                res.len++;
                res.exp++;
            } 
            res.clean_nul();
            return res;
        }
        if (sgn < 0)
                return h - (-(*this));
        return *this - (-h);
    }   

    Huge Huge::operator-(const Huge &h) const
    {
        int l;
        if (!sgn)
        {
            Huge res(h);
            return -res;
        }
        if (!h.sgn)
        {
            Huge res(*this);
            return res;
        }
        if (sgn > 0 && h.sgn > 0)
        {
            Huge res; int i;
            res.exp = max(exp, h.exp);
            int diff = abs(exp - h.exp);
            if (*this > h)
            {
                res.sgn = 1;
                l = max(len, h.len + diff);
                res.ar = new int [l];
                for (i = 0; i < l; i++)
                    res.ar[i] = 0;
                for (i = 0; i < diff; i++)
                    if (i < len)
                        res.ar[i] += ar[i];
                    else
                        break;
                for (i = diff; i < l; i++)
                {
                    if (i < len)
                        res.ar[i] += ar[i];
                    if (i - diff < h.len)
                        res.ar[i] -= h.ar[i - diff];
                }
            }
            else
            {
                res.sgn = -1;
                l = max(len + diff, h.len);
                res.ar = new int [l];
                for (i = 0; i < l; i++)
                    res.ar[i] = 0;
                for (i = 0; i < diff; i++)
                    if (i < h.len)
                        res.ar[i] += h.ar[i];
                    else
                        break;
                for (i = diff; i < l; i++)
                {
                    if (i < h.len)
                        res.ar[i] += h.ar[i];
                    if (i - diff < len)
                        res.ar[i] -= ar[i - diff];
                } 
            } 
            res.len = l;
            for (i = l - 1; i >= 1; i--)
                while (res.ar[i] < 0)
                {
                    res.ar[i - 1]--;
                    res.ar[i] += 10;
                }
            int k = min_no_nul(res.ar, l);
            if (k == -1)
            {
                res = 0;
                return res;
            }
            for (i = k; i < l; i++)
                res.ar[i - k] = res.ar[i];
            res.exp -= k;
            res.len -= k;
            return res;
        }
        if (sgn < 0 && h.sgn < 0)
            return (-h) - (-*this);  //*this - h
        return *this + (-h);
    }

    Huge Huge::operator*(const Huge &h) const
    {
        Huge res; int i;
        res.sgn = sgn * h.sgn;
        if (len == 0 || h.len == 0)
        {
            res.ar = new int [1];
            res.ar[0] = 0;
            res.len = 0;
            res.exp = 1;
            return res;
        }
        res.exp = exp + h.exp;
        res.ar = new int [len + h.len];
        for (i = 0; i < len + h.len; i++)
            res.ar[i] = 0;
        for (i = 0; i < len; i++)
            for (int j = 0; j < h.len; j++)
                res.ar[i + j + 1] += ar[i] * h.ar[j];
        for (i = len + h.len - 1; i >=1; i--)
            if (res.ar[i] >= 10)
            {
                res.ar[i - 1] += res.ar[i]/10;
                res.ar[i] = res.ar[i]%10;
            }
        res.len = len + h.len;
        if (!res.ar[0])
        {
            res.len--;
            res.exp--;
            int *tmp = new int [res.len];
            for (int i = 0; i < res.len; i++)
                tmp[i] = res.ar[i + 1];
            delete [] res.ar;
            res.ar = tmp;
        }
        res.clean_nul();
        return res;
    }

    Huge &Huge::operator=(const Huge &h)
    {
        if (this == &h)
            return *this;
        if (ar != NULL)
            delete [] ar;
        len = h.len;
        exp = h.exp;
        sgn = h.sgn;
        if (!len)
        {
            ar = new int [1];
            ar[0] = 0;
            return *this;
        }
        ar = new int [h.len];
        for (int i = 0; i < h.len; i++)
            ar[i] = h.ar[i];
        return *this;
    }

    Huge::Huge()
    {
        ar = nullptr;
        sgn = 0;
        len = 0;
        exp = 1;
    }
    Huge::Huge(const int &d)
    {
        int i, u = abs(d);
        len = length_int(d);
        exp = len;
        sgn = sign(d);
        if (len)
            ar = new int [len];
        else
        {
            ar = new int [1];
            ar[0] = 0;
            exp = 1;
            return;
        }
        int num = len - 1;
        while (u)
        {
            ar[num] = u%10;
            u /= 10;
            num--;
        }
    }
    Huge::Huge(const Huge &h)
    {
        exp = h.exp;
        len = h.len;
        sgn = h.sgn;
        ar = new int [len];
        for (int i = 0; i < len; i++)
            ar[i] = h.ar[i];
    }
    Huge::Huge(const double &d)
    {
        int k, l, i;
        double db = abs(d);
        sgn = sign(d);
        exp = 0;
        len = length_double(d);
        while (db > 1)
        {
            db = db / 10;
            exp++;
        }
        while (db < 0.1)
        {
            db *= 10;
            exp--;
        }
        ar = new int [len];
        for (i = 0; i < len; i++)
        {
            db *= 10;
            k = (int) db;
            ar[i] = k;
            db -= k;
        }
    }

}
