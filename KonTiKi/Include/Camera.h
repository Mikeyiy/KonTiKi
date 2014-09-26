#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <list>
#include <cassert>
#include <Component.h>
#include <Math/Matrix.h>
#include <Renderer/Material.h>
#include <Renderer/Renderer.h>
using namespace std;
namespace KonTiKi
{
    struct RenderableItem
    {
/*
        Mesh* m_pMesh;
        int m_meshIndex;
        Material* m_pMaterial;
        float m_sqrDistance;
        // Light source list.

        RenderableItem(Mesh* pMesh, int meshIndex, Material* pMaterial, float sqrDistance) 
            : m_pMesh(pMesh), m_meshIndex(meshIndex), m_pMaterial(pMaterial), m_sqrDistance(sqrDistance)
        {
        }
*/

        Renderer* m_pRenderer;
        int m_meshIndex;
        float m_sqrDistance;
        RenderableItem(Renderer* pRenderer, int meshIndex, float sqrDistance) : m_pRenderer(pRenderer)
            , m_meshIndex(meshIndex)
            , m_sqrDistance(sqrDistance)
        {
        }

        int GetRenderQueue(void)
        {
            return m_pRenderer->GetMaterials()[m_meshIndex]->GetRenderQueue();
        }

        bool IsTransparent(void)
        {
            return m_pRenderer->GetMaterials()[m_meshIndex]->IsTransparent();
        }

        float GetDistance(void)
        {
            return m_sqrDistance;
        }
    };

    struct RenderQueueItem
    {
        int m_queueIndex;
        list<RenderableItem*> m_opaqueRenderableList;
        list<RenderableItem*> m_transparentRenderableList;
    };

    extern bool CompareRenderableItemDistance(const RenderableItem* a, const RenderableItem* b);
    extern bool CompareRenderQueue(const RenderQueueItem* a, const RenderQueueItem* b); 

    class Camera : Component
    {
    friend class GraphicsSystem;
    public:
        Camera( GameObject* pAttachedGameObject ) : Component( pAttachedGameObject ){};
        ~Camera(void){};

    private:
        void CollectAndSort(std::list<GameObject*>& gameObjects); 
   
        // Fill the command buffer.
        void Render(void);

        void AddItemToRenderQueue(RenderableItem* pItem);

    private: 
        // 
        std::list<RenderableItem*> m_RenderQueue;
        list<RenderQueueItem*> m_renderQueueItemList;

        Matrix4x4 m_projectionMatrix;
        
    };
}
#endif
