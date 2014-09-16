#ifndef _MATH_UTILS_H_
#define _MATH_UTILS_H_
#include <Math/ConstantDefine.h>
#include <cmath>
namespace KonTiKi
{
    inline bool Equal(float a, float b)
    {
        return abs(a-b) < EPSILON;
    }
}
#endif
