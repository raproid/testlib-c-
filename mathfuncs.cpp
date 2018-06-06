#include "mathfuncs.h"

#include <stdexcept>

using namespace std;

namespace mathfuncs
{
    double simplemathfuncs::add(double a, double b)
    {
        return a + b;
    }

    double simplemathfuncs::subtract(double a, double b)
    {
        return a - b;
    }

    double simplemathfuncs::multiply(double a, double b)
    {
        return a * b;
    }

    double simplemathfuncs::divide(double a, double b)
    {
        return a / b;
    }
}
