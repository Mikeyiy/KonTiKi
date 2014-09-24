#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <list>
#include <cassert>
#include <Component.h>
#include <Math/Matrix.h>
namespace KonTiKi
{
    class Renderer;
    //class Material;
    //class Mesh;
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
        RenderableItem(Renderer* pRenderer, int meshIndex) : m_pRenderer(pRenderer), m_meshIndex(meshIndex)
        {
        }
    };

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

        Matrix4x4 m_projectionMatrix;
        
    };
}
#endif
