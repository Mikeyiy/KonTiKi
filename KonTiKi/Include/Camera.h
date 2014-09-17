#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <list>
#include <cassert>
#include <Component.h>
namespace KonTiKi
{
    class Camera : Component
    {
    friend class GraphicsSystem;
    public:
        Camera( GameObject* pAttachedGameObject ) : Component( pAttachedGameObject ){};
        ~Camera(void){};

    private:
        void CollectAndSort(std::list<GameObject*>& gameObjects); 
   
        void FillRenderingBuffer(void);

    private: 
        // 
        std::list<GameObject*> BackgroundQueue;
        std::list<GameObject*> GeometryQueue;
        std::list<GameObject*> AlphaTestQueue;
        std::list<GameObject*> TransparentQueue;
        std::list<GameObject*> OverlayQueue;
        
    };
}
#endif
