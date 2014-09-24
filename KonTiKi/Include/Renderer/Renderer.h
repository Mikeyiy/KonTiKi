#ifndef _RENDERER_H_
#define _RENDERER_H_
namespace KonTiKi
{
    class Matrix4x4;
    class Material;
    class Mesh;
    class Renderer : Component
    {
    friend class Camera;
    public:
        Renderer(GameObject* pGameObject);
        bool isVisible(void){return true;}
        Material* GetMaterial(void){return nullptr;}
        Material** GetMaterials(void){return nullptr;}
        Material* GetSharedMaterial(void){return nullptr;}
        Material** GetSharedMaterials(void){return nullptr;}

        int GetMaterialsCount(void){return 0;}
        int GetSharedMaterialsCount(void){return 0;}
        const Matrix4x4 GetLocalToWorldMatrix(void){return Matrix4x4();};
        const Matrix4x4 GetWorldToLocalMatrix(void){return Matrix4x4();};

        // Messages
        void OnBecameInvisible(void){}
        void OnBecameVisible(void){}

    private:
        
        Material::RenderQueue GetRenderQueueByMeshIndex(int index){return Material::QUEUE_BACKGROUD;}        
        Material* GetMaterialByMeshIndex(int index){return nullptr;}
    private:
        Mesh* m_pMesh;
    };
}
#endif
