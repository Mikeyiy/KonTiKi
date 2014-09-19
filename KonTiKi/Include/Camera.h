#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <list>
#include <cassert>
#include <Component.h>
#include <Math/Matrix.h>
namespace KonTiKi
{
    class Renderer;
    class Material;
    class Mesh;
    struct RenderableItem
    {
        Mesh* m_pMesh;
        int m_meshIndex;
        Material* m_pMaterial;

        RenderableItem(Mesh* pMesh, int meshIndex, Material* pMaterial) 
            : m_pMesh(pMesh), m_meshIndex(meshIndex), m_pMaterial(pMaterial)
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
   
        void Render(void);

        void AddItemToRenderQueue(const Renderer& renderer);

    private: 
        // 
        std::list<GameObject*> OpaqueQueue;
        std::list<GameObject*> TransparentQueue;

        Matrix4x4 m_projectionMatrix;
        
    };
}
#endif
