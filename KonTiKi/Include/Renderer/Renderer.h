#ifndef _RENDERER_H_
#define _RENDERER_H_
namespace KonTiKi
{
    class Matrix4x4;
    class Material;
    class Renderer : Component
    {
    public:
        Renderer(GameObject* pGameObject);
        bool isVisible(void);
        Material* GetMaterial(void);
        Material* GetMaterials(void);
        Material* GetSharedMaterial(void);
        Material* GetSharedMaterials(void)

        const Matrix4x4 GetLocalToWorldMatrix(void);
        const Matrix4x4 GetWorldToLocalMatrix(void);

        // Messages
        void OnBecameInvisible(void);
        void OnBecameVisible(void);
    };
}
#endif
