#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <Component.h>
namespace KonTiKi
{
    class Camera : Component
    {
    public:
        Camera( GameObject* pAttachedGameObject ) : Component( pAttachedGameObject ){};
        ~Camera(void){};
    };
}
#endif
