#include <list>
#include <cassert>
#include <Camera.h>
#include <GameObject.h>
#include <Renderer/Material.h>
#include <Transform.h>
#include <Math/MathUtils.h>
#include <Renderer/Renderer.h>
#include <Mesh.h>
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
                // TODO: Spawn RenderableItem form pool.
                RenderableItem* pItem = nullptr;
                if( i < materialCount )
                    pItem = new RenderableItem(pRenderer->m_pMesh, i, pRenderer->GetMaterials()[i]);
                else
                {
                    pItem = new RenderableItem(pRenderer->m_pMesh, i, GetErrorMaterial());
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
        
    }
}
