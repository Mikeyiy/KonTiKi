#include <Transform.h>
#include <Math/MathUtils.h>

namespace KonTiKi
{
    const Transform* Transform::GetParent(void) const
    {
        return m_pParent;
    }

    Transform* Transform::GetParent(void)
    {
        return m_pParent;
    }

    Vector3 Transform::GetForward(void)
    {
        Matrix4x4 mat = GetLocalToWorldMatrix();
        return mat.MultiplyVector(Vector3::forward);
    }

    const Matrix4x4 Transform::GetLocalToWorldMatrix(void)
    {
        Transform* pParent = m_pParent;
        Matrix4x4 mat = GetLocalToParentMatrix();
        while(pParent)
        {
            mat = pParent->GetLocalToParentMatrix() * mat;
            pParent = pParent->GetParent();
        }
        return mat;
    }

    const Matrix4x4 Transform::GetWorldToLocalMatrix(void)
    {
        Matrix4x4 retMat = TRS(m_localPosition, m_localRotation, m_localScale);
        if(IsUnifiedScale())
        {
            retMat = retMat.GetTranspose();
            Vector3 v(-retMat[3][0], -retMat[3][1], -retMat[3][2]);
            retMat[3][0] = 0;
            retMat[3][1] = 0;
            retMat[3][2] = 0;
            retMat[0][3] = Dot(v, Vector3(retMat[0]));
            retMat[1][3] = Dot(v, Vector3(retMat[1]));
            retMat[2][3] = Dot(v, Vector3(retMat[2]));
            return retMat;
        }
        else
        {
            return retMat.GetInverse();
        }
    }

    const Vector3 Transform::GetLocalEulerAngles(void) const
    {
        return QuaternionToEuler(m_localRotation); 
    }

    const Vector3 Transform::GetEulerAngles(void) const
    {
        return QuaternionToEuler(GetRotation());
    }

    
    void Transform::SetLocalPosition(const Vector3& position)
    {
        m_localPosition = position;
    }

    void Transform::SetLocalEulerAngles(const Vector3& eulerAngles)
    {
        m_localRotation = EulerToQuaternion(eulerAngles);
        hasChanged = true;
    }

    void Transform::SetLocalScale(const Vector3& scale)
    {
        m_localScale = scale;
    }

    const Quaternion Transform::GetLocalRotation(void) const
    {
        return m_localRotation;
    }

    const Quaternion Transform::GetRotation(void) const
    {
        Transform* pParent = m_pParent;
        Quaternion q = GetLocalRotation();
        while(pParent)
        {
            q = pParent->GetLocalRotation() * q;
            pParent = pParent->GetParent();
        }
        return q;
    }

    const Vector3 Transform::GetPosition(void)
    {
        return GetLocalToWorldMatrix().MultiplyPoint3x4(m_localPosition);
    }

    const Vector3 Transform::GetLossyScale(void)
    {
        Transform* pParent = m_pParent;
        Vector3 s = m_localScale;
        while(pParent)
        {
            s = pParent->m_localScale * s;
            pParent = pParent->m_pParent;
        }
        return s;
    }

    const Matrix4x4 Transform::GetLocalToParentMatrix(void) 
    {
        return TRS(m_localPosition, m_localRotation, m_localScale);
    }
 
    const bool Transform::IsUnifiedScale(void)
    {
        return Equal(m_localScale.x, m_localScale.y) && Equal(m_localScale.y, m_localScale.z);    
    }
}

