#ifndef _UNIFY3D_DEVICE_GLES2_H_
#define _UNIFY3D_DEVICE_GLES2_H_
#include <Renderer/Pipeline.h>
namespace KonTiKi
{
    class Unify3DDeviceGLES2 : IUnify3DDeviceCG
    {
    public: 
        virtual void Clear(int flag, const Vector3& color, float z, int stencil) override;
    };
}
#endif
