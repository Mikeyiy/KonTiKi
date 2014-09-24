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
                pItem = new RenderableItem(pRenderer, i);
                AddItemToRenderQueue(pItem);            
            }
        }
    }
 
    void Camera::Render(void)
    {
        // 设置材质。
        // 设置光源信息。
        // 提交Mesh信息。 
    }

    // 1. 按Queue值排序；
    // 2. 相同Queue值：不透明物件排在前；如果是透明物件则由远至近排序；
    // 3. 合并：不透明物件相同材质实例的物件的Mesh合入同一个Mesh成为SubMesh。透明物件也是如此，但需注意顺序不能变。 
    // 4. Base Pass中光源不一致的物件不能合并为一个Mesh。(在搜集之前每个Renderer就整理好了一份光源列表)
    void Camera::AddItemToRenderQueue(RenderableItem* pItem)
    {
        // 按RenderQueue排序。Queue相同的情况下，如果材质是透明的则根据离摄像机的距离排序，距离远的插在前，
        // 距离近的插在后；不透明材质则无需排序。 
        m_RenderQueue.push_back(pItem);
    }
}
