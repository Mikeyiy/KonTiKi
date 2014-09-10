#include <Math/Quaternion.h>

namespace KonTiKi
{
    Quaternion::Quaternion(float x, float y, float z, float w)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    Quaternion::~Quaternion(void){}

    void Quaternion::Set(float new_x, float new_y, float new_z, float new_w)
    {
        x = new_x;
        y = new_y;
        z = new_z;
        w = new_w;
    }

    void Quaternion::SetAngleAxis(float angle, const Vector3& axis)
    {
        angle *= 0.5f;
        std::cout << angle << endl;
        angle *= DEGREE_TO_RADIAN;
        std::cout << angle << endl;
        float cos_v = cos(angle);
        float sin_v = sin(angle);
        std::cout << "sin_v:" << sin_v << std::endl;
        w = cos_v;
        x = sin_v * axis.GetX();
        y = sin_v * axis.GetY();
        z = sin_v * axis.GetZ();
    }

    // 实现思路：轴角对。
    void Quaternion::SetFromToRotation(const Vector3& fromDirection, const Vector3& toDirection)
    {
        Vector3 axis = Cross(fromDirection, toDirection); 
        axis.Normalize();
        float angle = Angle(fromDirection, toDirection);            
        SetAngleAxis(angle, axis);
    }

    void Quaternion::SetLookRotation(const Vector3& view, const Vector3& up)
    {}

    void Quaternion::Print(void) const
    {
        char buffer[50];
        sprintf(buffer, "(%.5f, %.5f, %.5f, %.5f)", x, y, z, w);
        printf("%s \n", buffer);
    }

    const Quaternion Quaternion::operator*(float k) const
    {
        return Quaternion(x*k, y*k, z*k, w*k);
    }

    const Quaternion Quaternion::operator/(float k) const
    {
        return Quaternion(x/k, y/k, z/k, w/k);
    }

    const float Quaternion::GetX() const
    {return x;}

    const float Quaternion::GetY() const
    {return y;}

    const float Quaternion::GetZ() const
    {return z;}
        
    const float Quaternion::GetW() const
    {return w;}

    void Quaternion::SetX(float new_x)
    {
        x = new_x;
    }

    void Quaternion::SetY(float new_y)
    {
        y = new_y;
    }

    void Quaternion::SetZ(float new_z)
    {
        z = new_z;
    }

    void Quaternion::SetW(float new_w)
    {
        w = new_w;
    }

    const float Angle( const Quaternion& a, const Quaternion& b )
    {}

    const Quaternion AngleAxis(float angle, const Vector3& axis)
    {
        angle *= 0.5f;
        angle *= DEGREE_TO_RADIAN;
        float cos_v = cos(angle);
        float sin_v = sin(angle);
        float w = cos_v;
        float x = sin_v * axis.GetX();
        float y = sin_v * axis.GetY();
        float z = sin_v * axis.GetZ();
        return Quaternion(x, y, z, w);
    }

    const float Dot(const Quaternion& a, const Quaternion& b)
    {

    }

    const Matrix4x4 QuaternionToMatrix(const Quaternion& rotation)
    {
        float x = rotation.GetX();
        float y = rotation.GetY();
        float z = rotation.GetZ();
        float w = rotation.GetW();

        Matrix4x4 mat;
        mat.SetElement(0, 0, 1-2*y*y-2*z*z);
        mat.SetElement(1, 0, 2*x*y+2*w*z);
        mat.SetElement(2, 0, 2*x*z-2*w*y);

        mat.SetElement(0, 1, 2*x*y-2*w*z);
        mat.SetElement(1, 1, 1-2*x*x-2*z*z);
        mat.SetElement(2, 1, 2*y*z+2*w*x);

        mat.SetElement(0, 2, 2*x*z+2*w*y);
        mat.SetElement(1, 2, 2*y*z-2*w*x);
        mat.SetElement(2, 2, 1-2*x*x-2*y*y);

        return mat; 
    }

    const Quaternion EulerToQuaternion(float p, float h, float b)    
    {
        p *= (0.5f*DEGREE_TO_RADIAN);
        h *= (0.5f*DEGREE_TO_RADIAN);
        b *= (0.5f*DEGREE_TO_RADIAN);
        
        float cp = cos(p);
        float ch = cos(h);
        float cb = cos(b);
        float sp = sin(p);
        float sh = sin(h);
        float sb = sin(b);
        float w = ch*cp*cb + sh*sp*sb;
        float x = ch*sp*cb + sh*cp*sb;
        float y = -ch*sp*sb + sh*cp*cb;
        float z = -sh*sp*cb + ch*cp*sb; 
        return Quaternion(x, y, z, w);
    }
  
    const Vector3 QuaternionToEuler(const Quaternion& rotation)
    {
        float x = rotation.GetX();
        float y = rotation.GetY();
        float z = rotation.GetZ();
        float w = rotation.GetW();

        float sp = -2.0f * (y*z - w*x);
        float p, h, b;
        if(fabs(sp) > 0.9999f)
        {
            p = 0.5f * PI * sp;

            h = atan2(-x*z + w*y, 0.5f -y*y - z*z);
            b = 0;
        }
        else
        {
            p = asin(sp);
            h = atan2(x*z + w*y, 0.5f - x*x - y*y);
            b = atan2(x*y + w*z, 0.5f - x*x - z*z);
        }
        return Vector3(p*RADIAN_TO_DEGREE, h*RADIAN_TO_DEGREE, b*RADIAN_TO_DEGREE);
    }

    const Quaternion FromToRotation(const Vector3& fromDirection, const Vector3& toDirection)
    {}

    const Quaternion Adjoint(const Quaternion& rotation)
    {
        return Quaternion(rotation.GetX()
                         , -rotation.GetY()
                         , -rotation.GetZ()
                         , -rotation.GetW());
    }

    const Quaternion Inverse(const Quaternion& rotation)
    {
        float m = sqrt(rotation.GetX()*rotation.GetX()
                           + rotation.GetY()*rotation.GetY()
                           + rotation.GetZ()*rotation.GetZ()
                           + rotation.GetW()*rotation.GetW()); 

        assert(m!=0);
        return Adjoint(rotation)/m;
    }


    const Quaternion Lerp(const Quaternion& from, const Quaternion& to, float t)
    {}

    const Quaternion LookRotation(const Vector3& forward, const Vector3& upwards)
    {}

    const Quaternion RotateTowards(const Vector3& from, const Vector3& to, float maxDegreeDelta)
    {}

    const Quaternion Slerp(const Quaternion& from, const Quaternion& to, float)
    {}

    const bool operator==(const Quaternion& a, const Quaternion& b)
    {
        return a.GetX()==b.GetX() && a.GetY()==b.GetY() && a.GetZ()==b.GetZ() && a.GetW()==b.GetW();
    }

    const bool operator!=(const Quaternion& a, const Quaternion& b)
    {
        return a.GetX()!=b.GetX() || a.GetY()!=b.GetY() || a.GetZ()!=b.GetZ() || a.GetW()!=b.GetW();
    }

    const Quaternion operator*(const Quaternion& lhs, const Quaternion& rhs)
    {

    }

}
