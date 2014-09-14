#include <Math/Matrix.h>
#include <Math/Quaternion.h>
namespace KonTiKi
{
    Matrix4x4::Matrix4x4()
    {
        m00 = 0; m01 = 0; m02 = 0; m03 = 0; 
        m10 = 0; m11 = 0; m12 = 0; m13 = 0; 
        m20 = 0; m21 = 0; m22 = 0; m23 = 0; 
        m30 = 0; m31 = 0; m32 = 0; m33 = 0; 
    }

    Matrix4x4::Matrix4x4(const Matrix4x4& mat)
    {
        m00 = mat.m00; m01 = mat.m01; m02 = mat.m02; m03 = mat.m03; 
        m10 = mat.m10; m11 = mat.m11; m12 = mat.m12; m13 = mat.m13; 
        m20 = mat.m20; m21 = mat.m21; m22 = mat.m22; m23 = mat.m23; 
        m30 = mat.m30; m31 = mat.m31; m32 = mat.m32; m33 = mat.m33; 
    }

    Matrix4x4& Matrix4x4::operator=(const Matrix4x4& mat) 
    {
        m00 = mat.m00; m01 = mat.m01; m02 = mat.m02; m03 = mat.m03; 
        m10 = mat.m10; m11 = mat.m11; m12 = mat.m12; m13 = mat.m13; 
        m20 = mat.m20; m21 = mat.m21; m22 = mat.m22; m23 = mat.m23; 
        m30 = mat.m30; m31 = mat.m31; m32 = mat.m32; m33 = mat.m33; 
        return *this;
    }

    Vector4& Matrix4x4::operator[](int index)
    {
        return m[index];
    }

    Matrix4x4 Matrix4x4::operator*(float s) const
    {
        Matrix4x4 retMat;
        retMat.m00 = m00*s;
        retMat.m01 = m01*s;
        retMat.m02 = m02*s;
        retMat.m03 = m03*s;

        retMat.m10 = m10*s;
        retMat.m11 = m11*s;
        retMat.m12 = m12*s;
        retMat.m13 = m13*s;

        retMat.m20 = m20*s;
        retMat.m21 = m21*s;
        retMat.m22 = m22*s;
        retMat.m23 = m23*s;

        retMat.m30 = m30*s;
        retMat.m31 = m31*s;
        retMat.m32 = m32*s;
        retMat.m33 = m33*s;

        return retMat;
    }

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
        return (m[0][0]-1 < EPSILON) &&(m[1][1]-1 < EPSILON) &&(m[2][2]-1 < EPSILON) &&(m[3][3]-1 < EPSILON);
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
        ret[0] = Dot(Vector3(m[0]), point);
        ret[1] = Dot(Vector3(m[1]), point);
        ret[2] = Dot(Vector3(m[2]), point);
        ret[3] = 1.0f;
        return ret;
    }

    const Vector3 Matrix4x4::MultiplyVector(const Vector3 vector) const
    {
        Vector3 ret;
        ret[0] = Dot(Vector3(m[0]), vector);
        ret[1] = Dot(Vector3(m[1]), vector);
        ret[2] = Dot(Vector3(m[2]), vector);
        ret[3] = 1.0f;
        return ret;
    }

    void Matrix4x4::SetColumn(int j, const Vector4& column)
    {
        for(int i=0; i != 4; ++i)            
        {
            //m[i].Set(j, column[j]);
            m[i][j] = column[i];
        }
    }

    void Matrix4x4::SetRow(int i, const Vector4& row)
    {
        m[i] = row;
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
 
        trs[0][3] = pos.x;
        trs[1][3] = pos.y;
        trs[2][3] = pos.z;
        trs[3][3] = 1;
        return trs;       
    }

    const Matrix4x4 Scale(float x, float y, float z)
    {
        Matrix4x4 scale;
        
        scale[0][0] = x;
        scale[1][1] = y;
        scale[2][2] = z;
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
        mat[0][0] = cosh*cosb + sinh*sinp*sinb;
        mat[1][0] =  sinb*cosp;
        mat[2][0] =  -sinh*cosb + cosh*sinp*sinb;
    
        mat[0][1] =  -cosh*sinb+sinh*sinp*cosb;
        mat[1][1] =  cosb*cosp;
        mat[2][1] =  sinb*sinh+cosh*sinp*cosb;

        mat[0][2] =  sinh*cosp;
        mat[1][2] =  -sinp;
        mat[2][2] =  cosh*cosp;

        mat[3][3] = 1;
        return mat;
    }

    const Matrix4x4 operator*(const Matrix4x4& lhs, const Matrix4x4& rhs)
    {
        Matrix4x4 retMat;
        for(int i=0; i != 4; ++i)
        {
            for(int j=0; j != 4; ++j)
            {
                retMat[i][j] = Dot(lhs.GetRow(i), rhs.GetColumn(j));
            }
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

    const Matrix4x4 GetWorldToCameraMatrix(const Vector3& eyePos, const Vector3& lookAtPos, const Vector3& up)
    {
        Vector3 N = lookAtPos - eyePos;
        Vector3 U = Cross(up, N);
        Vector3 V = Cross(N, U);

        N.Normalize();
        U.Normalize();
        V.Normalize();

        float NdotT = Dot(N, eyePos);
        float UdotT = Dot(U, eyePos);
        float VdotT = Dot(V, eyePos);

        Matrix4x4 retMat;
        
        retMat[0] = U; retMat[0][3] = -UdotT;
        retMat[1] = V; retMat[1][3] = -VdotT;
        retMat[2] = N; retMat[2][3] = -NdotT;
        retMat[3][3] = 1;
        return retMat;
    }

    const float Determinant(const Matrix4x4& m)
    {
        float d00 = m.m00 * (m.m11*m.m22*m.m33 + m.m12*m.m23*m.m31 + m.m13*m.m21*m.m32 - m.m11*m.m23*m.m32 - m.m12*m.m21*m.m33 - m.m13*m.m22*m.m31);        
        float d01 = m.m01 * (m.m10*m.m22*m.m33 + m.m12*m.m23*m.m30 + m.m13*m.m20*m.m32 - m.m10*m.m23*m.m32 - m.m12*m.m20*m.m33 - m.m13*m.m22*m.m30);        
        float d02 = m.m02 * (m.m10*m.m21*m.m33 + m.m11*m.m23*m.m30 + m.m13*m.m20*m.m31 - m.m10*m.m23*m.m31 - m.m11*m.m20*m.m33 - m.m13*m.m21*m.m30);        
        float d03 = m.m03 * (m.m10*m.m21*m.m32 + m.m11*m.m22*m.m30 + m.m12*m.m20*m.m31 - m.m10*m.m22*m.m31 - m.m11*m.m20*m.m32 - m.m12*m.m21*m.m30);        

        return d00 - d01 + d02 - d03;
    }

    const Matrix4x4 Inverse(const Matrix4x4& m)
    {
        float d00 =  (m.m11*m.m22*m.m33 + m.m12*m.m23*m.m31 + m.m13*m.m21*m.m32 - m.m11*m.m23*m.m32 - m.m12*m.m21*m.m33 - m.m13*m.m22*m.m31);        
        float d01 =  (m.m10*m.m22*m.m33 + m.m12*m.m23*m.m30 + m.m13*m.m20*m.m32 - m.m10*m.m23*m.m32 - m.m12*m.m20*m.m33 - m.m13*m.m22*m.m30);        
        float d02 =  (m.m10*m.m21*m.m33 + m.m11*m.m23*m.m30 + m.m13*m.m20*m.m31 - m.m10*m.m23*m.m31 - m.m11*m.m20*m.m33 - m.m13*m.m21*m.m30);        
        float d03 =  (m.m10*m.m21*m.m32 + m.m11*m.m22*m.m30 + m.m12*m.m20*m.m31 - m.m10*m.m22*m.m31 - m.m11*m.m20*m.m32 - m.m12*m.m21*m.m30);        

        float d10 =  (m.m01*m.m22*m.m33 + m.m02*m.m23*m.m31 + m.m03*m.m21*m.m32 - m.m01*m.m23*m.m32 - m.m02*m.m21*m.m33 - m.m03*m.m22*m.m31);        
        float d11 =  (m.m00*m.m22*m.m33 + m.m02*m.m23*m.m30 + m.m03*m.m20*m.m32 - m.m00*m.m23*m.m32 - m.m02*m.m20*m.m33 - m.m03*m.m22*m.m30);        
        float d12 =  (m.m00*m.m21*m.m33 + m.m01*m.m23*m.m30 + m.m03*m.m20*m.m31 - m.m00*m.m23*m.m31 - m.m01*m.m20*m.m33 - m.m03*m.m21*m.m30);        
        float d13 =  (m.m00*m.m21*m.m32 + m.m01*m.m22*m.m30 + m.m02*m.m20*m.m31 - m.m00*m.m22*m.m31 - m.m01*m.m20*m.m32 - m.m02*m.m21*m.m30);        

        float d20 =  (m.m01*m.m12*m.m33 + m.m02*m.m13*m.m31 + m.m03*m.m11*m.m32 - m.m01*m.m13*m.m32 - m.m02*m.m11*m.m33 - m.m03*m.m12*m.m31);        
        float d21 =  (m.m00*m.m12*m.m33 + m.m02*m.m13*m.m30 + m.m03*m.m10*m.m32 - m.m00*m.m13*m.m32 - m.m02*m.m10*m.m33 - m.m03*m.m12*m.m30);        
        float d22 =  (m.m00*m.m11*m.m33 + m.m01*m.m13*m.m30 + m.m03*m.m10*m.m31 - m.m00*m.m13*m.m31 - m.m01*m.m10*m.m33 - m.m03*m.m11*m.m30);        
        float d23 =  (m.m00*m.m11*m.m32 + m.m01*m.m12*m.m30 + m.m02*m.m10*m.m31 - m.m00*m.m12*m.m31 - m.m01*m.m10*m.m32 - m.m02*m.m11*m.m30);        

        float d30 =  (m.m01*m.m12*m.m23 + m.m02*m.m13*m.m21 + m.m03*m.m11*m.m22 - m.m01*m.m13*m.m22 - m.m02*m.m11*m.m23 - m.m03*m.m12*m.m21);        
        float d31 =  (m.m00*m.m12*m.m23 + m.m02*m.m13*m.m20 + m.m03*m.m10*m.m22 - m.m00*m.m13*m.m22 - m.m02*m.m10*m.m23 - m.m03*m.m12*m.m20);        
        float d32 =  (m.m00*m.m11*m.m23 + m.m01*m.m13*m.m20 + m.m03*m.m10*m.m21 - m.m00*m.m13*m.m21 - m.m01*m.m10*m.m23 - m.m03*m.m11*m.m20);        
        float d33 =  (m.m00*m.m11*m.m22 + m.m01*m.m12*m.m20 + m.m02*m.m10*m.m21 - m.m00*m.m12*m.m21 - m.m01*m.m10*m.m22 - m.m02*m.m11*m.m20);        

        
        float det = (m.m00*d00 - m.m01*d01 + m.m02*d02 - m.m03*d03);
        assert(det > EPSILON);
        float oneOverDet = 1.0f / det;
         
        Vector4 even(1, -1, 1, -1);
        Vector4 odd(-1, 1, -1, 1);

        Vector4 v0(d00, d01, d02, d03);
        Vector4 v1(d10, d11, d12, d13);
        Vector4 v2(d20, d21, d22, d23);
        Vector4 v3(d30, d31, d32, d33);

        v0 *= even;
        v1 *= odd;
        v2 *= even;
        v3 *= odd;

        Matrix4x4 retMat;
        retMat.SetColumn(0, v0);
        retMat.SetColumn(1, v1);
        retMat.SetColumn(2, v2);
        retMat.SetColumn(3, v3);

        return retMat * oneOverDet;
    }
}
