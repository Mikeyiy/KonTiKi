#ifndef _QUATERNION_H_
#define _QUATERNION_H_
#include <cmath>

#include <cassert>
#include <iostream>
#include <Math/Vector.h>
#include <Math/Matrix.h>
namespace KonTiKi
{
    class Quaternion
    {
    public:
        Quaternion(float x=0, float y=0, float z=0, float w=0);
        ~Quaternion(void);

        void Set(float new_x, float new_y, float new_z, float new_w);

        void SetAngleAxis(float angle, const Vector3& axis);

        void SetFromToRotation(const Vector3& fromDirection, const Vector3& toDirection);

        void SetLookRotation(const Vector3& view, const Vector3& up = Vector3::up);

        void Print(void) const;

        const Quaternion operator*(float k) const;

        const Quaternion operator/(float k) const;

        const float GetX() const;

        const float GetY() const;

        const float GetZ() const;
        
        const float GetW() const;

        void SetX(float new_x);

        void SetY(float new_y);

        void SetZ(float new_z);

        void SetW(float new_w);
    private:
        float x, y, z, w;
    };

    extern const float Angle( const Quaternion& a, const Quaternion& b );

    extern const Quaternion AngleAxis(float angle, const Vector3& axis);

    extern const float Dot(const Quaternion& a, const Quaternion& b);

    extern const Matrix4x4 QuaternionToMatrix(const Quaternion& rotation);

    extern const Quaternion EulerToQuaternion(float p, float h, float b);    
  
    extern const Vector3 QuaternionToEuler(const Quaternion& rotation);

    extern const Quaternion FromToRotation(const Vector3& fromDirection, const Vector3& toDirection);

    extern const Quaternion Adjoint(const Quaternion& rotation);

    extern const Quaternion Inverse(const Quaternion& rotation);

    extern const Quaternion Lerp(const Quaternion& from, const Quaternion& to, float t);

    extern const Quaternion LookRotation(const Vector3& forward, const Vector3& upwards = Vector3::up);

    extern const Quaternion RotateTowards(const Vector3& from, const Vector3& to, float maxDegreeDelta);

    extern const Quaternion Slerp(const Quaternion& from, const Quaternion& to, float);

    extern const bool operator==(const Quaternion& a, const Quaternion& b);

    extern const bool operator!=(const Quaternion& a, const Quaternion& b);

    extern const Quaternion operator*(const Quaternion& lhs, const Quaternion& rhs);
}
#endif
