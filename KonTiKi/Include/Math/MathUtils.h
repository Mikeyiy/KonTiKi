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

    inline bool IsInFrustum(const Matrix4x4& projectionMatrix, const Vector3& position)
    {
        return true;
    }
}
#endif
