#ifndef _RENDERER_H_
#define _RENDERER_H_
namespace KonTiKi
{
    class Matrix4x4;
    class Material;
    class Renderer : Component
    {
    friend class Camera;
    public:
        Renderer(GameObject* pGameObject);
        bool isVisible(void);
        Material* GetMaterial(void);
        Material** GetMaterials(void);
        Material* GetSharedMaterial(void);
        Material** GetSharedMaterials(void)

        int GetMaterialsCount(void);
        int GetSharedMaterialsCount(void);
        const Matrix4x4 GetLocalToWorldMatrix(void);
        const Matrix4x4 GetWorldToLocalMatrix(void);

        // Messages
        void OnBecameInvisible(void);
        void OnBecameVisible(void);

    private:
        
        Material::RenderQueue GetRenderQueueByMeshIndex(int index);        
        Material* GetMaterialByMeshIndex(int index);
    private:
        Mesh* m_pMesh;
    };
}
#endif
