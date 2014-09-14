#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <string>
#include <cassert>
#include <stdio.h>
#include <Math/Vector.h>
#include <Math/ConstantDefine.h>
using namespace std;
namespace KonTiKi
{
    class Quaternion;
    class Matrix4x4
    {
    public:
        Matrix4x4();

        Matrix4x4(const Matrix4x4& mat);

        Matrix4x4& operator=(const Matrix4x4& rhs);

        Vector4& operator[](int index);

        Matrix4x4 operator*(float s) const;

        //Fetches a row in matrix(Read only). 
        const Vector4& operator[](int index) const; 

        //Get inverse matrix.
        const Matrix4x4 GetInverse(void) const;

        const bool IsIdentity(void) const;

        const Matrix4x4 GetTranspose(void) const;

        const Vector4 GetColumn(int i) const;

        const Vector4 GetRow(int i) const;

        const Vector3 MultiplyPoint(const Vector3& point) const;

        const Vector3 MultiplyPoint3x4(const Vector3& point) const;

        const Vector3 MultiplyVector(const Vector3 vector) const;

        void SetColumn(int j, const Vector4& column);

        void SetRow(int i, const Vector4& row);

        void SetTRS(const Vector3& pos, const Quaternion& q, const Vector3& s);

        string ToString(void) const;

        void Print(void) const;

    private:
        inline Vector4 Multiply(Vector4 pointIn4d) const
        {
            Vector4 ret;
            for(int i = 0; i != 4; ++i)
            {
                //ret.Set(i, Dot(GetRow(i), pointIn4d));
                ret[i] = Dot(m[i], pointIn4d);
            }
            return ret;
        }
    public:
        union
        {
            struct 
            {
                float m00, m01, m02, m03,
                      m10, m11, m12, m13,
                      m20, m21, m22, m23, 
                      m30, m31, m32, m33;
            };
            Vector4 m[4];
        };
        //Vector4 m[4];
    };

    // Global Functions
    extern const Matrix4x4 operator*(const Matrix4x4& lhs, const Matrix4x4& rhs);

    extern const Matrix4x4 Orthor(float left, float right, float bottom, float top, float zNear, float zFar);

    extern const Matrix4x4 Perspective(float fox, float aspect, float zNear, float zFar);

    extern const Matrix4x4 Scale(float x, float y, float z);

    extern const Matrix4x4 TRS(const Vector3& pos, const Quaternion& q, const Vector3& s);

    extern const Matrix4x4 GetWorldToCameraMatrix(const Vector3& eyePos, const Vector3& lookAtPos, const Vector3& up);

    extern const Matrix4x4 EulerToMatrix(float p, float h, float b);

    extern const float Determinant(const Matrix4x4& m);

    extern const Matrix4x4 Inverse(const Matrix4x4& m);
}
#endif
