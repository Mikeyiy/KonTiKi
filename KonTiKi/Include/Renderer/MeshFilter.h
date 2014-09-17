#ifndef _MESH_FILTER_H_
#ifndef _MESH_FILTER_H_
#include <Component.h>
namespace KonTiKi
{
    class GameObject;
    class MeshFilter : Component
    {
    public:
        MeshFilter(GameObject* pAttachedGameObject);
     
        const Mesh* GetMesh(void) const;

        const Mesh* GetSharedMesh(void) const;

        void SetMesh(void);

        void SetSharedMesh(void);
    };
}
#endif
