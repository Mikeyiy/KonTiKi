#include <Math/Matrix.h>
#include <Math/Quaternion.h>
namespace KonTiKi
{
    Matrix4x4::Matrix4x4(){}

    //Fetches a row in matrix(Read only). 
    const Vector4& Matrix4x4::operator[](int index) const 
    {
        return m[index];
    }

    //Get inverse matrix.
    const Matrix4x4 Matrix4x4::GetInverse(void) const
    {
        Matrix4x4 retMat;
        return retMat;
    }

    const bool Matrix4x4::IsIdentity(void) const
    {
        if((m[0][0]-1 < EPSILON) &&(m[1][1]-1 < EPSILON) &&(m[2][2]-1 < EPSILON) &&(m[3][3]-1 < EPSILON));
    }

    const Matrix4x4 Matrix4x4::GetTranspose(void) const
    {
        float temp;
        Matrix4x4 retMat;
        return retMat;
    }

    const Vector4 Matrix4x4::GetColumn(int i) const
    {
        return Vector4(m[0][i], m[1][i], m[2][i], m[3][i]);
    }

    const Vector4 Matrix4x4::GetRow(int i) const
    {
        return m[i];
    }

    const Vector3 Matrix4x4::MultiplyPoint(const Vector3& point) const
    {
        return Multiply(point);    
    }

    const Vector3 Matrix4x4::MultiplyPoint3x4(const Vector3& point) const
    {
        Vector3 ret;
        Vector4 pointIn4D(point);
        ret.Set(0, Dot(GetRow(0), pointIn4D));
        ret.Set(1, Dot(GetRow(1), pointIn4D));
        ret.Set(2, Dot(GetRow(2), pointIn4D));
        return ret;
    }

    const Vector3 Matrix4x4::MultiplyVector(const Vector3 vector) const
    {
        Vector4 vectorIn4D(vector);
        vectorIn4D.Set(3, 0);
        return Multiply(vectorIn4D);
    }

    void Matrix4x4::SetColumn(int j, const Vector4& column)
    {
        for(int i=0; i != 4; ++i)            
        {
            m[i].Set(j, column[j]);
        }
    }

    void Matrix4x4::SetRow(int i, const Vector4& row)
    {
        m[i] = row;
    }

    void Matrix4x4::SetElement(int i, int j, float e)
    {
        m[i].Set(j, e);
    }

    void Matrix4x4::SetTRS(const Vector3& pos, const Quaternion& q, const Vector3& s)
    {}

    string Matrix4x4::ToString(void) const
    {
            
        return nullptr;
    }

    void Matrix4x4::Print(void) const
    {
        char buffer[1000];
        int n;
        n = sprintf(buffer, "%.5f %.5f %.5f %.5f \n%.5f %.5f %.5f %.5f \n%.5f %.5f %.5f %.5f \n%.5f %.5f %.5f %.5f \n", m[0][0], m[0][1],m[0][2],m[0][3],m[1][0],m[1][1],m[1][2],m[1][3],m[2][0],m[2][1],m[2][2],m[2][3],m[3][0],m[3][1],m[3][2],m[3][3]);
        printf("%s", buffer );
    }

   
    const Matrix4x4 TRS(const Vector3& pos, const Quaternion& q, const Vector3& s)
    {
        Matrix4x4 rotation = QuaternionToMatrix(q);
        Matrix4x4 scale = Scale(s.GetX(), s.GetY(), s.GetZ()); 
        Matrix4x4 trs = rotation * scale;
        trs.SetElement(0, 3, pos.GetX());
        trs.SetElement(1, 3, pos.GetY());
        trs.SetElement(2, 3, pos.GetZ());
        trs.SetElement(3, 3, 1);
 
        return trs;       
    }

    const Matrix4x4 Scale(float x, float y, float z)
    {
        Matrix4x4 scale;
        
        scale.SetElement(0, 0, x);
        scale.SetElement(1, 1, y);
        scale.SetElement(2, 2, z);

        return scale;
    }

    const Matrix4x4 EulerToMatrix(float p, float h, float b)
    {
        h *= DEGREE_TO_RADIAN;
        p *= DEGREE_TO_RADIAN;
        b *= DEGREE_TO_RADIAN;

        float cosh = cos(h);
        float cosp = cos(p);
        float cosb = cos(b);
        float sinh = sin(h);
        float sinp = sin(p);
        float sinb = sin(b);

        Matrix4x4 mat;
        mat.SetElement(0, 0, cosh*cosb + sinh*sinp*sinb);
        mat.SetElement(1, 0, sinb*cosp);
        mat.SetElement(2, 0, -sinh*cosb + cosh*sinp*sinb);
    
        mat.SetElement(0, 1, -cosh*sinb+sinh*sinp*cosb);
        mat.SetElement(1, 1, cosb*cosp);
        mat.SetElement(2, 1, sinb*sinh+cosh*sinp*cosb);

        mat.SetElement(0, 2, sinh*cosp);
        mat.SetElement(1, 2, -sinp);
        mat.SetElement(2, 2, cosh*cosp);

        mat.SetElement(3, 3, 1);
        return mat;
    }

    const Matrix4x4 operator*(const Matrix4x4& lhs, const Matrix4x4& rhs)
    {
        Matrix4x4 retMat;
        for(int i=0; i != 4; ++i)
        {
            Vector4 row;
            for(int j=0; j != 4; ++j)
            {
                row.Set(j, Dot(lhs.GetRow(i), rhs.GetColumn(j)));
            }
            retMat.SetRow(i, row);
        }
        return retMat;
    }

    const Matrix4x4 Orthor(float left, float right, float bottom, float top, float zNear, float zFar)
    {
        Matrix4x4 retMat;
        return retMat;
    }

    const Matrix4x4 Perspective(float fox, float aspect, float zNear, float zFar)
    {
        Matrix4x4 retMat;
        return retMat;
    }


}
