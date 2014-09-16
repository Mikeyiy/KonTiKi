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
            m[0] = x;
            m[1] = y;
        }

        //拷贝构造函数。
        Vector2(const Vector2& rhs)
        {
            m[0] = rhs.x;
            m[1] = rhs.y;
        }

        Vector2(const Vector3& rhs);
        Vector2(const Vector4& rhs);

        const float GetX(void) const
        {
            return m[0];
        }

        const float GetY(void) const
        {
            return m[1];
        }

        void SetX(float x)
        {
            m[0] = x;
        }

        void SetY(float y)
        {
            m[1] = y;
        }

        float& operator[](int index)
        {
            return m[index];
        }

        const float operator[](int index) const
        {
            return m[index];
        }

        void Set(int i, float value)
        {
            m[i] = value;
        }

        //拷贝赋值操作符。
        Vector2& operator=(const Vector2& rhs)
        {
            m[0] = rhs.x;
            m[1] = rhs.y;
            return *this;
        }

        // 与向量间的运算。
        const Vector2 operator+(const Vector2& rhs) const
        {
	    return Vector2(m[0]+rhs.x, m[1]+rhs.y);
        }

        const Vector2 operator-(const Vector2& rhs) const
        {
            return Vector2(m[0]-rhs.x, m[1]-rhs.y);
        }

        const Vector2 operator*(const Vector2& rhs) const
        {
            return Vector2(m[0]*rhs.x, m[1]*rhs.y);
        }

        const Vector2 operator/(const Vector2& rhs) const
        {
            return Vector2(m[0]/rhs.x, m[1]/rhs.y);
        }

        // 与向量间的自反运算。 
        Vector2& operator+=(const Vector2& rhs)
        {
            m[0]+=rhs.x;
            m[1]+=rhs.y;
            return *this;
        }

        Vector2& operator-=(const Vector2& rhs) 
        {
            m[0]-=rhs.x;
            m[1]-=rhs.y;
            return *this;
        }

        Vector2& operator*=(const Vector2& rhs) 
        {
            m[0]*=rhs.x;
            m[1]*=rhs.y;
            return *this;
        }

        Vector2& operator/=(const Vector2& rhs)
        {
            m[0]/=rhs.x;
            m[1]/=rhs.y;
            return *this;
        }

        // 逻辑运算符。
        const bool operator==(const Vector2& rhs) const
        {
            return m[0] == rhs.x && m[1] == rhs.y;
        }

        const bool operator!=(const Vector2& rhs) const
        {
            return m[0] != rhs.x || m[1] != rhs.y;
        }

        // 与标量的运算。
        const Vector2 operator*(float k) const
        {
            return Vector2(k*m[0], k*m[1]);
        }

        const Vector2 operator/(float k) const
        {
            assert(k!=0);
            return Vector2(m[0]/k, m[1]/k);
        }

        // 与标量的自反运算。
        Vector2& operator*=(float k)
        {
            m[0] *= k;
            m[1] *= k;
            return *this;
        }

        Vector2& operator/=(float k)
        {
            m[0] /= k;
            m[1] /= k;
            return *this;
        }

        void Normalize(void)
        {
            float magnitude = GetMagnitude();
            assert(magnitude > 0.0f); 
            m[0] /= magnitude;
            m[1] /= magnitude;
        }

        string ToString(void) const
        {return nullptr;}

        const float GetMagnitude(void) const
        {
            return sqrt(m[0]*m[0] + m[1]*m[1]);
        }

        const float GetSqrMagnitude(void) const
        {
           return m[0]*m[0] + m[1]*m[1];
        }

        // Static Functions

        static const float Distance(const Vector2& a, const Vector2& b) 
        { 
            float dx = a.x - b.x;
            float dy = a.y - b.y;
            return sqrt(dx*dx + dy*dy);
        }

        static const float Dot(const Vector2& a, const Vector2& b )
        {
            return a.x * b.x + a.y * b.y;
        }

        public:
            static const Vector2 up;
        public:
            union 
            {
                struct{float x, y;};
                struct{float u, v;};
                float m[2];
            };
    };

    struct Vector3
    {
    public:
        Vector3(float x=0, float y=0, float z=0)
        {
            m[0] = x;
            m[1] = y;
            m[2] = z;
        }

        //拷贝构造函数。
        Vector3(const Vector3& rhs)
        {
            m[0] = rhs.x;
            m[1] = rhs.y;
            m[2] = rhs.z;
        }

        Vector3(const Vector4& rhs);
        Vector3(const Vector2& rhs);

        float& operator[](int index)
        {
            return m[index];
        }

        const float operator[](int index) const
        {
            return m[index];
        }

        void Set(int i, float value)
        {
            m[i] = value;
        }

        //拷贝赋值操作符。
        Vector3& operator=(const Vector3& rhs)
        {
            m[0] = rhs.x;
            m[1] = rhs.y;
            m[2] = rhs.z;
            return *this;
        }

        // 与向量间的运算。
        const Vector3 operator+(const Vector3& rhs) const
        {
	    return Vector3(m[0]+rhs.x, m[1]+rhs.y, m[2]+rhs.z);
        }

        const Vector3 operator-(const Vector3& rhs) const
        {
            return Vector3(m[0]-rhs.x, m[1]-rhs.y, m[2]-rhs.z);
        }

        const Vector3 operator*(const Vector3& rhs) const
        {
            return Vector3(m[0]*rhs.x, m[1]*rhs.y, m[2]*rhs.z);
        }

        const Vector3 operator/(const Vector3& rhs) const
        {
            return Vector3(m[0]/rhs.x, m[1]/rhs.y, m[2]/rhs.z);
        }

        // 与向量间的自反运算。 
        Vector3& operator+=(const Vector3& rhs)
        {
            m[0]+=rhs.x;
            m[1]+=rhs.y;
            m[2]+=rhs.z;
            return *this;
        }

        Vector3& operator-=(const Vector3& rhs) 
        {
            m[0]-=rhs.x;
            m[1]-=rhs.y;
            m[2]-=rhs.z;
            return *this;
        }

        Vector3& operator*=(const Vector3& rhs) 
        {
            m[0]*=rhs.x;
            m[1]*=rhs.y;
            m[2]*=rhs.z;
            return *this;
        }

        Vector3& operator/=(const Vector3& rhs)
        {
            m[0]/=rhs.x;
            m[1]/=rhs.y;
            m[2]/=rhs.z;
            return *this;
        }

        // 逻辑运算符。
        const bool operator==(const Vector3& rhs) const
        {
            return m[0] == rhs.x && m[1] == rhs.y && m[2] == rhs.z;
        }

        const bool operator!=(const Vector3& rhs) const
        {
            return m[0] != rhs.x || m[1] != rhs.y || m[2] != rhs.z;
        }

        // 与标量的运算。
        const Vector3 operator*(float k) const
        {
            return Vector3(k*m[0], k*m[1], k*m[2]);
        }

        const Vector3 operator/(float k) const
        {
            assert(k!=0);
            return Vector3(m[0]/k, m[1]/k, m[2]/k);
        }

        // 与标量的自反运算。
        Vector3& operator*=(float k)
        {
            m[0] *= k;
            m[1] *= k;
            m[2] *= k;
            return *this;
        }

        Vector3& operator/=(float k)
        {
            m[0] /= k;
            m[1] /= k;
            m[2] /= k;
            return *this;
        }

        void Normalize(void)
        {
            float magnitude = GetMagnitude();
            assert(magnitude > 0.0f); 
            m[0] /= magnitude;
            m[1] /= magnitude;
            m[2] /= magnitude;
        }

        const string ToString(void) const
        {return nullptr;}

        void Print(void) const
        {
            char buffer[20];
            sprintf(buffer, "(%.5f, %.5f, %.5f)", m[0], m[1], m[2]);
            printf("%s\n", buffer);
        }

        const float GetMagnitude(void) const
        {
            return sqrt( m[0]*m[0] + m[1]*m[1] + m[2]*m[2]);
        }

        const float GetSqrMagnitude(void) const
        {
            return m[0]*m[0] + m[1]*m[1] + m[2]*m[2];
        }


        const float GetX(void) const
        {
            return m[0];
        }

        const float GetY(void) const
        {
            return m[1];
        }

        const float GetZ(void) const
        {
            return m[2];
        }

        // Static Functions
        // 计算从from到to的角度.
        static const float Angle(const Vector3& from, const Vector3& to) 
        { return 0; }

        static const float Distance(const Vector3& a, const Vector3& b) 
        { 
            float dx = a.x - b.x;
            float dy = a.y - b.y;
            float dz = a.z - b.z;
            return sqrt(dx*dx + dy*dy + dz*dz);
        }

        public:
            static const Vector3 back;
            static const Vector3 down;
            static const Vector3 forward;
            static const Vector3 left;
            static const Vector3 one;
            static const Vector3 right;
            static const Vector3 up;
            static const Vector3 zero;
        public:
            union 
            {
                struct{float x, y, z;};
                struct{float u, v, w;};
                struct{float pitch, heading, bank;};
                float m[3];
            };
    };

    struct Vector4
    {
    public:
        Vector4(float x=0, float y=0, float z=0, float w=0)
        {
            m[0] = x;
            m[1] = y;
            m[2] = z;
            m[3] = w;
        }

        //拷贝构造函数。
        Vector4(const Vector4& rhs)
        {
            m[0] = rhs.x;
            m[1] = rhs.y;
            m[2] = rhs.z;
            m[3] = rhs.w;
        }
 
        Vector4& operator=(const Vector4& rhs)
        {
            m[0] = rhs.x;
            m[1] = rhs.y;
            m[2] = rhs.z;
            m[3] = rhs.w;
            return *this; 
        }

        Vector4& operator=(const Vector3& rhs)
        {
            m[0] = rhs.x;
            m[1] = rhs.y;
            m[2] = rhs.z;
            return *this; 
        }

        Vector4(const Vector3& rhs)
        {
            m[0] = rhs.x;
            m[1] = rhs.y;
            m[2] = rhs.z;
            m[3] = 0;
        }

        Vector4(const Vector2& rhs)
        {
            m[0] = rhs.x;
            m[1] = rhs.y;
            m[2] = 0;
            m[3] = 0;
        }
/*
        void Set(int i, float value)
        {
            m[i] = value;
        }
*/
        float& operator[](int index)
        {
            return m[index];
        }

        const float operator[](int index) const 
        {
            return m[index];
        }


        // 与向量间的运算。
        const Vector4 operator+(const Vector4& rhs) const
        {
	    return Vector4(m[0]+rhs.x, m[1]+rhs.y, m[2]+rhs.z, m[3]+rhs.w);
        }

        const Vector4 operator-(const Vector4& rhs) const
        {
            return Vector4(m[0]-rhs.x, m[1]-rhs.y, m[2]-rhs.z, m[3]-rhs.w);
        }

        const Vector4 operator*(const Vector4& rhs) const
        {
            return Vector4(m[0]*rhs.x, m[1]*rhs.y, m[2]*rhs.z, m[3]*rhs.w);
        }

        const Vector4 operator/(const Vector4& rhs) const
        {
            return Vector4(m[0]/rhs.x, m[1]/rhs.y, m[2]/rhs.z, m[3]/rhs.w);
        }

        // 与向量间的自反运算。 
        Vector4& operator+=(const Vector4& rhs)
        {
            m[0]+=rhs.x;
            m[1]+=rhs.y;
            m[2]+=rhs.z;
            m[3]+=rhs.w;
            return *this;
        }

        Vector4& operator-=(const Vector4& rhs) 
        {
            m[0]-=rhs.x;
            m[1]-=rhs.y;
            m[2]-=rhs.z;
            m[3]-=rhs.w;
            return *this;
        }

        Vector4& operator*=(const Vector4& rhs) 
        {
            m[0]*=rhs.x;
            m[1]*=rhs.y;
            m[2]*=rhs.z;
            m[3]*=rhs.w;
            return *this;
        }

        Vector4& operator/=(const Vector4& rhs)
        {
            m[0]/=rhs.x;
            m[1]/=rhs.y;
            m[2]/=rhs.z;
            m[3]/=rhs.w;
            return *this;
        }

        // 逻辑运算符。
        const bool operator==(const Vector4& rhs) const
        {
            return m[0] == rhs.x && m[1] == rhs.y && m[2] == rhs.z && m[3] == rhs.w;
        }

        const bool operator!=(const Vector4& rhs) const
        {
            return m[0] != rhs.x || m[1] != rhs.y || rhs.z || m[3] != rhs.w;
        }

        // 与标量的运算。
        const Vector4 operator*(float k) const
        {
            return Vector4(k*m[0], k*m[1], k*m[2], k*m[3]);
        }

        const Vector4 operator/(float k) const
        {
            assert(k!=0);
            return Vector4(m[0]/k, m[1]/k, m[2]/k, m[3]/k);
        }

        // 与标量的自反运算。
        Vector4& operator*=(float k)
        {
            m[0] *= k;
            m[1] *= k;
            m[2] *= k;
            m[3] *= k;
            return *this;
        }

        Vector4& operator/=(float k)
        {
            m[0] /= k;
            m[1] /= k;
            m[2] /= k;
            m[3] /= k;
            return *this;
        }

        void Normalize(void)
        {
            float magnitude = GetMagnitude();
            assert(magnitude > 0.0f); 
            m[0] /= magnitude;
            m[1] /= magnitude;
            m[2] /= magnitude;
            m[3] /= magnitude;
        }

        const string ToString(void) const
        {return nullptr;}

        const float GetMagnitude(void) const
        {
            return sqrt( m[0]*m[0] + m[1]*m[1] + m[2]*m[2] + m[3]*m[3]);
        }

        const float GetSqrMagnitude(void) const
        {
            return m[0]*m[0] + m[1]*m[1] + m[2]*m[2] + m[3]*m[3];
        }

        const float GetX(void) const
        {
            return m[0];
        }

        const float GetY(void) const
        {
            return m[1];
        }

        const float GetZ(void) const
        {
            return m[2];
        }

        const float GetW(void) const
        {
            return m[3];
        }

        // Static Functions

        static const float Distance(const Vector4& a, const Vector4& b) 
        {
             float dx = a.x - b.x; 
             float dy = a.y - b.y; 
             float dz = a.z - b.z; 
             float dw = a.w - b.w; 
             return sqrt( dx*dx + dy*dy + dz*dz + dw*dw ); 
        } 

     
        void Print(void) const
        {
            char buffer[20];
            sprintf(buffer, "(%.5f, %.5f, %.5f, %.5f)", m[0], m[1], m[2], m[3]);
            printf("%s\n", buffer);
        }

        public: 
            union 
            {
                struct{float x, y, z, w;};
                float m[4];
            };
    };

    // Global Functions.
    inline const float Dot(const Vector3& a, const Vector3& b)
    {
        return a.x*b.x + a.y*b.y + a.z*b.z;
    }

    inline const Vector3 Cross(const Vector3& a, const Vector3& b)
    {
        return Vector3(a.y*b.z - a.z*b.y
                      ,a.z*b.x - a.x*b.z
                      ,a.x*b.y - a.y*b.x);
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
        return Vector2(k*v.x, k*v.y);
    }

    inline const Vector3 operator*(float k, const Vector3& v)
    {
        return Vector3(k*v.x, k*v.y, k*v.z);
    }

    inline const Vector4 operator*(float k, const Vector4& v)
    {
        return Vector4(k*v.x, k*v.y, k*v.x, k*v.y);
    }

    inline const float Dot(const Vector4& lhs, const Vector4& rhs)
    {
        return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z + lhs.w*rhs.w;
    }

    inline const Vector3 operator-(const Vector3& rhs)
    {
        Vector3 ret;
        ret.x = -rhs.x;
        ret.y = -rhs.y;
        ret.z = -rhs.z;
        return ret;
    }
}
#endif

