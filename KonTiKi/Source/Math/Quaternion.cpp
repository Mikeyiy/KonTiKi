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
        x = sin_v * axis.x;
        y = sin_v * axis.y;
        z = sin_v * axis.z;
    }

    // 实现思路：轴角对。
    void Quaternion::SetFromToRotation(const Vector3& fromDirection, const Vector3& toDirection)
    {
        Vector3 axis = Cross(fromDirection, toDirection); 
        axis.Normalize();
        float angle = Angle(fromDirection, toDirection);            
        SetAngleAxis(angle, axis);
    }


    void Quaternion::SetFromToRotation(const Quaternion& from, const Quaternion& to)
    {
        Quaternion inversedFrom = Inverse(from); 
        Quaternion delta = to * inversedFrom;
        w = delta.w;
        x = delta.x;
        y = delta.y;
        z = delta.z;
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

    const float Angle( const Quaternion& a, const Quaternion& b )
    {
        Quaternion delta;
        delta.SetFromToRotation(a, b);
        return 2.0f * acos(delta.w) * RADIAN_TO_DEGREE;
    }

    const Quaternion AngleAxis(float angle, const Vector3& axis)
    {
	angle *= 0.5f;
	angle *= DEGREE_TO_RADIAN;
	float cos_v = cos(angle);
	float sin_v = sin(angle);
	float w = cos_v;
	float x = sin_v * axis.x;
	float y = sin_v * axis.y;
	float z = sin_v * axis.z;
	return Quaternion(x, y, z, w);
    }

    const float Dot(const Quaternion& a, const Quaternion& b)
    {
        return 0;
    }

    const Matrix4x4 QuaternionToMatrix(const Quaternion& rotation)
    {
	float x = rotation.x;
	float y = rotation.y;
	float z = rotation.z;
	float w = rotation.w;

	Matrix4x4 mat;
	mat[0][0] = 1-2*y*y-2*z*z;
	mat[1][0] = 2*x*y+2*w*z;
	mat[2][0] = 2*x*z-2*w*y;

	mat[0][1] = 2*x*y-2*w*z;
	mat[1][1] = 1-2*x*x-2*z*z;
	mat[2][1] = 2*y*z+2*w*x;

	mat[0][2] = 2*x*z+2*w*y;
	mat[1][2] = 2*y*z-2*w*x;
	mat[2][2] = 1-2*x*x-2*y*y;

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
	float x = rotation.x;
	float y = rotation.y;
	float z = rotation.z;
	float w = rotation.w;

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
    {
        return Quaternion();
    }

    const Quaternion Adjoint(const Quaternion& rotation)
    {
	return Quaternion(rotation.x
			 , -rotation.y
			 , -rotation.z
			 , -rotation.w);
    }

    const Quaternion Inverse(const Quaternion& rotation)
    {
	float m = sqrt(rotation.x*rotation.x
			   + rotation.y*rotation.y
			   + rotation.z*rotation.z
			   + rotation.w*rotation.w); 

	assert(m!=0);
	return Adjoint(rotation)/m;
    }


    const Quaternion Lerp(const Quaternion& from, const Quaternion& to, float t)
    {
        return Quaternion();
    }

    const Quaternion LookRotation(const Vector3& forward, const Vector3& upwards)
    {
        return Quaternion();
    }

    const Quaternion RotateTowards(const Vector3& from, const Vector3& to, float maxDegreeDelta)
    {
        return Quaternion();
    }

    const Quaternion Slerp(const Quaternion& from, const Quaternion& to, float)
    {
        return Quaternion();
    }

    const bool operator==(const Quaternion& a, const Quaternion& b)
    {
	return a.x==b.x && a.y==b.y && a.z==b.z && a.w==b.w;
    }

    const bool operator!=(const Quaternion& a, const Quaternion& b)
    {
	return a.x!=b.x || a.y!=b.y || a.z!=b.z || a.w!=b.w;
    }

    const Quaternion operator*(const Quaternion& lhs, const Quaternion& rhs)
    {
        Quaternion q;
        q.w = lhs.w*rhs.w - lhs.x*rhs.x - lhs.y*rhs.y - lhs.z*rhs.z;
        q.x = lhs.w*rhs.x - lhs.x*rhs.w + lhs.z*rhs.y - lhs.y*rhs.z;
        q.y = lhs.w*rhs.y - lhs.y*rhs.w + lhs.x*rhs.z - lhs.z*rhs.x;
        q.z = lhs.w*rhs.z - lhs.z*rhs.w + lhs.y*rhs.x - lhs.x*rhs.y;
        return q;        
    }
}
