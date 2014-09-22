#include <list>
#include <cassert>
#include <Camera.h>
#include <GameObject.h>
#include <Renderer/Material.h>
#include <Transform.h>
#include <Math/MathUtils.h>
#include <Renderer/Renderer.h>
#include <Mesh.h>
#include <Math/Vector.h>
namespace KonTiKi
{
    void Camera::CollectAndSort(std::list<GameObject*>& gameObjects)
    {
        std::list<GameObject*>::iterator it = gameObjects.begin();
        for(; it != gameObjects.end(); ++it)
        {
            GameObject* pGameObject = *it;
            assert(pGameObject);

            Renderer* pRenderer = pGameObject->GetRenderer();
            if( !pRenderer )
                continue;
            
            // 判断Renderable GameObject是否在视景体中。
            if( !IsInFrustum(m_projectionMatrix, pGameObject->GetTransform()->GetPosition()) )
                continue;

            // 根据Mesh对应的材质类型分类存放GameObject对象。对于半透明对象则需要排序。
            assert(pRenderer->m_pMesh);
            int meshCount = pRenderer->m_pMesh->GetSubMeshCount();
            int materialCount = pRenderer->GetMaterialsCount(); 
            for(int i=0; i != meshCount; ++i)
            {
                float sqrDistance = SqrDistance(GetTransform()->GetPosition(), pRenderer->GetTransform()->GetPosition());
                // TODO: Spawn RenderableItem form pool.
                RenderableItem* pItem = nullptr;
                if( i < materialCount )
                {
                    pItem = new RenderableItem(pRenderer->m_pMesh, i, pRenderer->GetMaterials()[i], sqrDistance);
                }
                else
                {
                    pItem = new RenderableItem(pRenderer->m_pMesh, i, GetErrorMaterial(), sqrDistance);
                }
                AddItemToRenderQueue(pItem);            
            }
        }
    }
 
    void Camera::Render(void)
    {
    
    }

    void Camera::AddItemToRenderQueue(const RenderableItem* pItem)
    {
        assert(pItem && pItem->m_pMaterial);        
        // 按RenderQueue排序。Queue相同的情况下，如果材质是透明的则根据离摄像机的距离排序，距离远的插在前，
        // 距离近的插在后；不透明材质则无需排序。 
    }
}
