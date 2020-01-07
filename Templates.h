#ifndef FITNESS_CLUB_TEMPLATES_H
#define FITNESS_CLUB_TEMPLATES_H
#include <iostream>
#include <sstream>


template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 6)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return out.str();
}

#endif //FITNESS_CLUB_TEMPLATES_H
