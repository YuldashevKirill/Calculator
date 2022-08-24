#ifndef VAR
#define VAR

namespace my
{
    class Variable
    {
        std::string name;
    public:
        Variable(const char *s);
        std::string get_name();
    };
}


#endif
