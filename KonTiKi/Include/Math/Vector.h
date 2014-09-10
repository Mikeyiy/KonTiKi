#ifndef _PRIMITIVE_DATA_TYPE_H_
#define _PRIMITIVE_DATA_TYPE_H_

#include <string>
#include <cmath>
#include <cassert>
#include <stdio.h>
#include <Math/ConstantDefine.h>
using namespace std;
namespace KonTiKi
{
    struct Vector3;
    struct Vector4;
    struct Vector2
    {
    public:
        Vector2(float x, float y) 
        {
            v[0] = x;
            v[1] = y;
        }

        //拷贝构造函数。
        Vector2(const Vector2& rhs)
        {
            v[0] = rhs.GetX();
            v[1] = rhs.GetY();
        }

        Vector2(const Vector3& rhs);
        Vector2(const Vector4& rhs);

        const float GetX(void) const
        {
            return v[0];
        }

        const float GetY(void) const
        {
            return v[1];
        }

        void SetX(float x)
        {
            v[0] = x;
        }

        void SetY(float y)
        {
            v[1] = y;
        }

        const float operator[](int index) const
        {
            return v[index];
        }

        void Set(int i, float value)
        {
            v[i] = value;
        }

        //拷贝赋值操作符。
        Vector2& operator=(const Vector2& rhs)
        {
            v[0] = rhs.GetX();
            v[1] = rhs.GetY();
            return *this;
        }

        // 与向量间的运算。
        const Vector2 operator+(const Vector2& rhs) const
        {
	    return Vector2(v[0]+rhs.GetX(), v[1]+rhs.GetY());
        }

        const Vector2 operator-(const Vector2& rhs) const
        {
            return Vector2(v[0]-rhs.GetX(), v[1]-rhs.GetY());
        }

        const Vector2 operator*(const Vector2& rhs) const
        {
            return Vector2(v[0]*rhs.GetX(), v[1]*rhs.GetY());
        }

        const Vector2 operator/(const Vector2& rhs) const
        {
            return Vector2(v[0]/rhs.GetX(), v[1]/rhs.GetY());
        }

        // 与向量间的自反运算。 
        Vector2& operator+=(const Vector2& rhs)
        {
            v[0]+=rhs.GetX();
            v[1]+=rhs.GetY();
            return *this;
        }

        Vector2& operator-=(const Vector2& rhs) 
        {
            v[0]-=rhs.GetX();
            v[1]-=rhs.GetY();
            return *this;
        }

        Vector2& operator*=(const Vector2& rhs) 
        {
            v[0]*=rhs.GetX();
            v[1]*=rhs.GetY();
            return *this;
        }

        Vector2& operator/=(const Vector2& rhs)
        {
            v[0]/=rhs.GetX();
            v[1]/=rhs.GetY();
            return *this;
        }

        // 逻辑运算符。
        const bool operator==(const Vector2& rhs) const
        {
            return v[0] == rhs.GetX() && v[1] == rhs.GetY();
        }

        const bool operator!=(const Vector2& rhs) const
        {
            return v[0] != rhs.GetX() || v[1] != rhs.GetY();
        }

        // 与标量的运算。
        const Vector2 operator*(float k) const
        {
            return Vector2(k*v[0], k*v[1]);
        }

        const Vector2 operator/(float k) const
        {
            assert(k!=0);
            return Vector2(v[0]/k, v[1]/k);
        }

        // 与标量的自反运算。
        Vector2& operator*=(float k)
        {
            v[0] *= k;
            v[1] *= k;
            return *this;
        }

        Vector2& operator/=(float k)
        {
            v[0] /= k;
            v[1] /= k;
            return *this;
        }

        void Normalize(void)
        {
            float magnitude = GetMagnitude();
            assert(magnitude > 0.0f); 
            v[0] /= magnitude;
            v[1] /= magnitude;
        }

        string ToString(void) const
        {return nullptr;}

        const float GetMagnitude(void) const
        {
            return sqrt(v[0]*v[0] + v[1]*v[1]);
        }

        const float GetSqrMagnitude(void) const
        {
           return v[0]*v[0] + v[1]*v[1];
        }

        // Static Functions
        // 计算从from到to的角度.
        static const float Angle(const Vector2& from, const Vector2& to) 
        { return 0; }

        static const float Distance(const Vector2& a, const Vector2& b) 
        { 
            float dx = a.GetX() - b.GetX();
            float dy = a.GetY() - b.GetY();
            return sqrt(dx*dx + dy*dy);
        }

        static const float Dot(const Vector2& a, const Vector2& b )
        {
            return a.GetX() * b.GetX() + a.GetY() * b.GetY();
        }

        public:
            static const Vector2 up;
        private:
            float v[2];
    };

    struct Vector3
    {
    public:
        Vector3(float x=0, float y=0, float z=0)
        {
            v[0] = x;
            v[1] = y;
            v[2] = z;
        }

        //拷贝构造函数。
        Vector3(const Vector3& rhs)
        {
            v[0] = rhs.GetX();
            v[1] = rhs.GetY();
            v[2] = rhs.GetZ();
        }

        Vector3(const Vector4& rhs);
        Vector3(const Vector2& rhs);

        const float operator[](int index) const
        {
            return v[index];
        }

        void Set(int i, float value)
        {
            v[i] = value;
        }

        //拷贝赋值操作符。
        Vector3& operator=(const Vector3& rhs)
        {
            v[0] = rhs.GetX();
            v[1] = rhs.GetY();
            v[2] = rhs.GetZ();
            return *this;
        }

        // 与向量间的运算。
        const Vector3 operator+(const Vector3& rhs) const
        {
	    return Vector3(v[0]+rhs.GetX(), v[1]+rhs.GetY(), v[2]+rhs.GetZ());
        }

        const Vector3 operator-(const Vector3& rhs) const
        {
            return Vector3(v[0]-rhs.GetX(), v[1]-rhs.GetY(), v[2]-rhs.GetZ());
        }

        const Vector3 operator*(const Vector3& rhs) const
        {
            return Vector3(v[0]*rhs.GetX(), v[1]*rhs.GetY(), v[2]*rhs.GetZ());
        }

        const Vector3 operator/(const Vector3& rhs) const
        {
            return Vector3(v[0]/rhs.GetX(), v[1]/rhs.GetY(), v[2]/rhs.GetZ());
        }

        // 与向量间的自反运算。 
        Vector3& operator+=(const Vector3& rhs)
        {
            v[0]+=rhs.GetX();
            v[1]+=rhs.GetY();
            v[2]+=rhs.GetZ();
            return *this;
        }

        Vector3& operator-=(const Vector3& rhs) 
        {
            v[0]-=rhs.GetX();
            v[1]-=rhs.GetY();
            v[2]-=rhs.GetZ();
            return *this;
        }

        Vector3& operator*=(const Vector3& rhs) 
        {
            v[0]*=rhs.GetX();
            v[1]*=rhs.GetY();
            v[2]*=rhs.GetZ();
            return *this;
        }

        Vector3& operator/=(const Vector3& rhs)
        {
            v[0]/=rhs.GetX();
            v[1]/=rhs.GetY();
            v[2]/=rhs.GetZ();
            return *this;
        }

        // 逻辑运算符。
        const bool operator==(const Vector3& rhs) const
        {
            return v[0] == rhs.GetX() && v[1] == rhs.GetY() && v[2] == rhs.GetZ();
        }

        const bool operator!=(const Vector3& rhs) const
        {
            return v[0] != rhs.GetX() || v[1] != rhs.GetY() || v[2] != rhs.GetZ();
        }

        // 与标量的运算。
        const Vector3 operator*(float k) const
        {
            return Vector3(k*v[0], k*v[1], k*v[2]);
        }

        const Vector3 operator/(float k) const
        {
            assert(k!=0);
            return Vector3(v[0]/k, v[1]/k, v[2]/k);
        }

        // 与标量的自反运算。
        Vector3& operator*=(float k)
        {
            v[0] *= k;
            v[1] *= k;
            v[2] *= k;
            return *this;
        }

        Vector3& operator/=(float k)
        {
            v[0] /= k;
            v[1] /= k;
            v[2] /= k;
            return *this;
        }

        void Normalize(void)
        {
            float magnitude = GetMagnitude();
            assert(magnitude > 0.0f); 
            v[0] /= magnitude;
            v[1] /= magnitude;
            v[2] /= magnitude;
        }

        const string ToString(void) const
        {return nullptr;}

        void Print(void) const
        {
            char buffer[20];
            sprintf(buffer, "(%.5f, %.5f, %.5f)", v[0], v[1], v[2]);
            printf("%s\n", buffer);
        }

        const float GetMagnitude(void) const
        {
            return sqrt( v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
        }

        const float GetSqrMagnitude(void) const
        {
            return v[0]*v[0] + v[1]*v[1] + v[2]*v[2];
        }


        const float GetX(void) const
        {
            return v[0];
        }

        const float GetY(void) const
        {
            return v[1];
        }

        const float GetZ(void) const
        {
            return v[2];
        }

        // Static Functions
        // 计算从from到to的角度.
        static const float Angle(const Vector3& from, const Vector3& to) 
        { return 0; }

        static const float Distance(const Vector3& a, const Vector3& b) 
        { 
            float dx = a.GetX() - b.GetX();
            float dy = a.GetY() - b.GetY();
            float dz = a.GetZ() - b.GetZ();
            return sqrt(dx*dx + dy*dy + dz*dz);
        }

        public:
            static const Vector3 up;
        private:
            float v[3];
    };

    struct Vector4
    {
    public:
        Vector4(float x=0, float y=0, float z=0, float w=0)
        {
            v[0] = x;
            v[1] = y;
            v[2] = z;
            v[3] = w;
        }

        //拷贝构造函数。
        Vector4(const Vector4& rhs)
        {
            v[0] = rhs.GetX();
            v[1] = rhs.GetY();
            v[2] = rhs.GetZ();
            v[3] = rhs.GetW();
        }

        Vector4(const Vector3& rhs)
        {
            v[0] = rhs.GetX();
            v[1] = rhs.GetY();
            v[2] = rhs.GetZ();
            v[3] = 1;
        }

        Vector4(const Vector2& rhs)
        {
            v[0] = rhs.GetX();
            v[1] = rhs.GetY();
            v[2] = 0;
            v[3] = 1;
        }

        void Set(int i, float value)
        {
            v[i] = value;
        }

        const float operator[](int index) const 
        {
            return v[index];
        }


        //拷贝赋值操作符。
        Vector4& operator=(const Vector4& rhs)
        {
            v[0] = rhs.GetX();
            v[1] = rhs.GetY();
            v[2] = rhs.GetZ();
            v[3] = rhs.GetW();
            return *this;
        }

        // 与向量间的运算。
        const Vector4 operator+(const Vector4& rhs) const
        {
	    return Vector4(v[0]+rhs.GetX(), v[1]+rhs.GetY(), v[2]+rhs.GetZ(), v[3]+rhs.GetW());
        }

        const Vector4 operator-(const Vector4& rhs) const
        {
            return Vector4(v[0]-rhs.GetX(), v[1]-rhs.GetY(), v[2]-rhs.GetZ(), v[3]-rhs.GetW());
        }

        const Vector4 operator*(const Vector4& rhs) const
        {
            return Vector4(v[0]*rhs.GetX(), v[1]*rhs.GetY(), v[2]*rhs.GetZ(), v[3]*rhs.GetW());
        }

        const Vector4 operator/(const Vector4& rhs) const
        {
            return Vector4(v[0]/rhs.GetX(), v[1]/rhs.GetY(), v[2]/rhs.GetZ(), v[3]/rhs.GetW());
        }

        // 与向量间的自反运算。 
        Vector4& operator+=(const Vector4& rhs)
        {
            v[0]+=rhs.GetX();
            v[1]+=rhs.GetY();
            v[2]+=rhs.GetZ();
            v[3]+=rhs.GetW();
            return *this;
        }

        Vector4& operator-=(const Vector4& rhs) 
        {
            v[0]-=rhs.GetX();
            v[1]-=rhs.GetY();
            v[2]-=rhs.GetZ();
            v[3]-=rhs.GetW();
            return *this;
        }

        Vector4& operator*=(const Vector4& rhs) 
        {
            v[0]*=rhs.GetX();
            v[1]*=rhs.GetY();
            v[2]*=rhs.GetZ();
            v[3]*=rhs.GetW();
            return *this;
        }

        Vector4& operator/=(const Vector4& rhs)
        {
            v[0]/=rhs.GetX();
            v[1]/=rhs.GetY();
            v[2]/=rhs.GetZ();
            v[3]/=rhs.GetW();
            return *this;
        }

        // 逻辑运算符。
        const bool operator==(const Vector4& rhs) const
        {
            return v[0] == rhs.GetX() && v[1] == rhs.GetY() && v[2] == rhs.GetZ() && v[3] == rhs.GetW();
        }

        const bool operator!=(const Vector4& rhs) const
        {
            return v[0] != rhs.GetX() || v[1] != rhs.GetY() || rhs.GetZ() || v[3] != rhs.GetW();
        }

        // 与标量的运算。
        const Vector4 operator*(float k) const
        {
            return Vector4(k*v[0], k*v[1], k*v[2], k*v[3]);
        }

        const Vector4 operator/(float k) const
        {
            assert(k!=0);
            return Vector4(v[0]/k, v[1]/k, v[2]/k, v[3]/k);
        }

        // 与标量的自反运算。
        Vector4& operator*=(float k)
        {
            v[0] *= k;
            v[1] *= k;
            v[2] *= k;
            v[3] *= k;
            return *this;
        }

        Vector4& operator/=(float k)
        {
            v[0] /= k;
            v[1] /= k;
            v[2] /= k;
            v[3] /= k;
            return *this;
        }

        void Normalize(void)
        {
            float magnitude = GetMagnitude();
            assert(magnitude > 0.0f); 
            v[0] /= magnitude;
            v[1] /= magnitude;
            v[2] /= magnitude;
            v[3] /= magnitude;
        }

        const string ToString(void) const
        {return nullptr;}

        const float GetMagnitude(void) const
        {
            return sqrt( v[0]*v[0] + v[1]*v[1] + v[2]*v[2] + v[3]*v[3]);
        }

        const float GetSqrMagnitude(void) const
        {
            return v[0]*v[0] + v[1]*v[1] + v[2]*v[2] + v[3]*v[3];
        }

        const float GetX(void) const
        {
            return v[0];
        }

        const float GetY(void) const
        {
            return v[1];
        }

        const float GetZ(void) const
        {
            return v[2];
        }

        const float GetW(void) const
        {
            return v[3];
        }

        // Static Functions
        // 计算从from到to的角度.
        static const float Angle(const Vector4& from, const Vector4& to) 
        { return 0; }

        static const float Distance(const Vector4& a, const Vector4& b) 
        { float dx = a.GetX() - b.GetX(); 
          float dy = a.GetY() - b.GetY(); 
          float dz = a.GetZ() - b.GetZ(); 
          float dw = a.GetW() - b.GetW(); 
          return sqrt( dx*dx + dy*dy + dz*dz + dw*dw ); 
        } 
        private: 
            float v[4];
    };

    // Global Functions.
    inline const float Dot(const Vector3& a, const Vector3& b)
    {
        return a.GetX()*b.GetX() + a.GetY()*b.GetY() + a.GetZ()*b.GetZ();
    }

    inline const Vector3 Cross(const Vector3& a, const Vector3& b)
    {
        return Vector3(a.GetY()*b.GetZ() - a.GetZ()*b.GetY()
                      ,a.GetZ()*b.GetX() - a.GetX()*b.GetZ()
                      ,a.GetX()*b.GetY() - a.GetY()*b.GetX());
    }

    // Static Functions
    // 计算从from到to的角度.
    inline const float Angle(const Vector3& from, const Vector3& to) 
    { 
        float cos_value = Dot(from, to) / (from.GetMagnitude() * to.GetMagnitude());
        float radian = acos(cos_value);
        return radian * RADIAN_TO_DEGREE; 
    }

    inline const Vector2 operator*(float k, const Vector2& v)
    {
        return Vector2(k*v.GetX(), k*v.GetY());
    }

    inline const Vector3 operator*(float k, const Vector3& v)
    {
        return Vector3(k*v.GetX(), k*v.GetY(), k*v.GetZ());
    }

    inline const Vector4 operator*(float k, const Vector4& v)
    {
        return Vector4(k*v.GetX(), k*v.GetY(), k*v.GetX(), k*v.GetY());
    }

    inline const float Dot(const Vector4& lhs, const Vector4& rhs)
    {
        return lhs.GetX()*rhs.GetX() + lhs.GetY()*rhs.GetY() + lhs.GetZ()*rhs.GetZ() + lhs.GetW()*rhs.GetW();
    }
}
#endif

