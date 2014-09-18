#include <list>
#include <Camera.h>
#include <GameObject.h>
#include <Renderer/Material.h>
namespace KonTiKi
{
    void Camera::CollectAndSort(std::list<GameObject*>& gameObjects)
    {
        std::list<GameObject*>::iterator it = gameObjects.begin();
        for(; it != gameObjects.end(); ++it)
        {
            // 判断Renderable GameObject是否在视景体中。
            GameObject* pGameObject = *it;
            assert(pGameObject);
        }
    }
 
    void Camera::FillRenderingBuffer(void)
    {
    
    }
}
