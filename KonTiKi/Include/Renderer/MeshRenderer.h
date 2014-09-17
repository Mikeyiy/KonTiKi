#ifndef _MESH_RENDERER_H_
#define _MESH_RENDERER_H_
#include <Renderer/Renderer.h>
namespace KonTiKi
{
    class GameObject;
    class MeshRenderer : Renderer
    {
    public:
        MeshRenderer(GameObject* pGameObject);
    }
}
#endif
