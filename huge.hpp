#ifndef HUGE
#define HUGE

namespace my
{
    class Huge
    {
        int *ar;
        int sgn;
        int len;
        int exp;
      public:
        Huge(const int &d);
        Huge(const double &d);
        Huge(const Huge &h);
        Huge();
        ~Huge();
        int get_int() const;
        Huge reverse() const;
        Huge modul() const;
        void clean_nul();
        Huge &operator=(const Huge &h);
        Huge operator-() const;
        bool operator>(const Huge &h) const;
        bool operator<(const Huge &h) const;
        bool operator==(const Huge &h) const;
        bool operator>=(const Huge &h) const;
        bool operator!=(const Huge &h) const;
        Huge operator+(const Huge &h) const;
        Huge operator-(const Huge &h) const;
        Huge operator*(const Huge &h) const;
        friend Huge operator*(const int &k, const Huge &h);
        Huge operator/(const Huge &h) const;
        friend Huge sin(const Huge &y, int eps);
        friend Huge cos(const Huge &y, int eps);
        friend Huge exp(const Huge &y, int eps);
        friend Huge ln(const Huge &y, int eps);
        friend Huge asin(const Huge &y, int eps);
        friend std::ostream &operator<<(std::ostream &out, Huge h);
    };
}
#endif
