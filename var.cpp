#include <iostream>
#include "var.hpp"

namespace my
{
    Variable::Variable(const char *s) {
        name = std::string(s);
    }
    std::string Variable::get_name() {
        return name;
    }
}
