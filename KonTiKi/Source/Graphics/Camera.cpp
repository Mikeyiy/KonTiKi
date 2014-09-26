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
            float sqrDistance = SqrDistance(GetTransform()->GetPosition(), pRenderer->GetTransform()->GetPosition());
            for(int i=0; i != meshCount; ++i)
            {
                // TODO: Spawn RenderableItem form pool.
                RenderableItem* pItem = nullptr;
                pItem = new RenderableItem(pRenderer, i, sqrDistance);
                AddItemToRenderQueue(pItem);            
            }
        }
    }
 
    void Camera::Render(void)
    {
        // 设置材质。
        // 设置光源信息。
        // 提交Mesh信息。 
        std::list<RenderQueueItem*>::iterator it = m_renderQueueItemList.begin();
        for(; it != m_renderQueueItemList.end(); ++it) 
        {

        }
    }

    // 1. 按Queue值排序；
    // 2. 相同Queue值：不透明物件排在前；如果是透明物件则由远至近排序；
    // 3. 合并：不透明物件相同材质实例的物件的Mesh合入同一个Mesh成为SubMesh。透明物件也是如此，但需注意顺序不能变。 
    // 4. Base Pass中光源不一致的物件不能合并为一个Mesh。(在搜集之前每个Renderer就整理好了一份光源列表)
    void Camera::AddItemToRenderQueue(RenderableItem* pItem)
    {
        // 按RenderQueue排序。Queue相同的情况下，如果材质是透明的则根据离摄像机的距离排序，距离远的插在前，
        // 距离近的插在后；不透明材质则无需排序。 
        assert(pItem);

        // 获得该item的Queue值
        int queue = pItem->GetRenderQueue();

        if(m_renderQueueItemList.size() == 0)
        {
            RenderQueueItem* pRenderQueueItem = new RenderQueueItem();
            pRenderQueueItem->m_queueIndex = queue;

            m_renderQueueItemList.push_back(pRenderQueueItem);
            if(pItem->IsTransparent())
            {
                pRenderQueueItem->m_transparentRenderableList.push_back(pItem);
            }
            else
            {
                pRenderQueueItem->m_opaqueRenderableList.push_back(pItem);
            }
        }
        else 
        {

        RenderQueueItem rqItem;
        rqItem.m_queueIndex = queue;
        // 通过折半查找等于该Queue值的列表；如不存在则找到大于它的iterator，然后插于前方。
        std::list<RenderQueueItem*>::iterator low = lower_bound(m_renderQueueItemList.begin()
            , m_renderQueueItemList.end(), &rqItem, CompareRenderQueue);

        if((*low)->m_queueIndex == queue)
        {
            RenderQueueItem* pRenderQueueItem = (*low); 

            if(pItem->IsTransparent())
            {
                if(pRenderQueueItem->m_transparentRenderableList.size() == 0)
                    pRenderQueueItem->m_transparentRenderableList.push_back(pItem);
                else
                {
                    // 通过折半查找插入RenderableItem.
                    std::list<RenderableItem*>::iterator low; 
                    low = lower_bound(pRenderQueueItem->m_transparentRenderableList.begin(),
                        pRenderQueueItem->m_transparentRenderableList.end(),
                        pItem, CompareRenderableItemDistance);
                    if(pItem->m_sqrDistance < (*low)->m_sqrDistance)
                    {
                        pRenderQueueItem->m_transparentRenderableList.push_back(pItem);
                    }
                    else
                    {
                        pRenderQueueItem->m_transparentRenderableList.insert(low, pItem);
                    }
                }
            }
            else
            {
                list<RenderableItem*>::iterator it
                    = pRenderQueueItem->m_opaqueRenderableList.begin();
                bool inserted = false;
                for(; it != pRenderQueueItem->m_opaqueRenderableList.end(); ++it)
                {
                    if((*it)->m_pRenderer->GetMaterial() == pItem->m_pRenderer->GetMaterial())
                    {
                        pRenderQueueItem->m_opaqueRenderableList.insert(it, pItem);    
                        inserted = true;
                        break;
                    }
                }
                if(!inserted)
                {
                    pRenderQueueItem->m_opaqueRenderableList.push_back(pItem);
                }
                pRenderQueueItem->m_opaqueRenderableList.push_back(pItem);
            }
        }
        else if(queue < (*low)->m_queueIndex)
        {
            RenderQueueItem* pRenderQueueItem = new RenderQueueItem();
            pRenderQueueItem->m_queueIndex = queue;

            m_renderQueueItemList.insert(low, pRenderQueueItem);
            if(pItem->IsTransparent())
            {
                pRenderQueueItem->m_transparentRenderableList.push_back(pItem);
            }
            else
            {
                pRenderQueueItem->m_opaqueRenderableList.push_back(pItem);
            }
        }
        else
        {
            RenderQueueItem* pRenderQueueItem = new RenderQueueItem();
            pRenderQueueItem->m_queueIndex = queue;

            m_renderQueueItemList.push_back(pRenderQueueItem);
            if(pItem->IsTransparent())
            {
                pRenderQueueItem->m_transparentRenderableList.push_back(pItem);
            }
            else
            {
                pRenderQueueItem->m_opaqueRenderableList.push_back(pItem);
            }
        }

        }// 
        // 获得该item是否是透明物件
        // 如果是透明物件，则在透明列表中按距离插入。 
    }

    bool CompareRenderableItemDistance(const RenderableItem* a, const RenderableItem* b)
    {
        return a->m_sqrDistance > b->m_sqrDistance;
    }

    bool CompareRenderQueue(const RenderQueueItem* a, const RenderQueueItem* b)
    {
        return a->m_queueIndex < b->m_queueIndex;
    }
}
