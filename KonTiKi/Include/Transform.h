/*
* 版权所有（C）， 2014， 陈刚
* All rights reserved.
*
* 文件名称： 
* 文件标识：
* 文件摘要：
* 
* 当前版本：
* 摘要：
* 作者：
* 完成日前：
*
* 取代版本：
* 摘要：
* 原作者：
* 完成日前：
*/

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include <vector>
#include "Component.h"
#include <Math/Matrix.h>
#include <Math/Quaternion.h>
#include <Math/Vector.h>

namespace KonTiKi
{
	class Transform : public Component
	{
	public:
            Transform( GameObject* pAttatchedGameObject ) : Component( pAttatchedGameObject ) {}

            const Transform* GetParent(void) const; 

            //Transform* GetParent(void) const;

            Vector3 GetForward(void) const;

            const Matrix4x4 GetLocalToWorldMatrix(void) const;

            const Matrix4x4 GetWorldToLocalMatrix(void) const;

            const Vector3 GetLocalEulerAngles(void) const;

            const Vector3 GetEulerAngles(void) const;

            void SetLocalPosition(const Vector3& position);

            void SetLocalEulerAngles(const Vector3& eulerAngles);

            void SetLocalScale(const Vector3& scale);

            const Quaternion GetLocalRotation(void) const;

            const Quaternion GetRotation(void) const;

            const Vector3 GetPosition(void) const;

            const Vector3 GetLossyScale(void) const;
        private:
            const Matrix4x4 GetLocalToParentMatrix(void) const; 
            const bool IsUnifiedScale(void) const;
        public:
            bool hasChanged;
        private:
            Vector3 m_localPosition;
            Vector3 m_localScale;
            Quaternion m_localRotation;
            Transform* m_pParent;
            std::vector<Transform*> m_children;
	};
}

#endif
