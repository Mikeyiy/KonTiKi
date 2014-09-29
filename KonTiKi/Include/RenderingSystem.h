#ifndef _RENDERING_SYSTEM_H_
#define _RENDERING_SYSTEM_H_
#include <System.h>
#include <Runnable.h>
namespace KonTiKi
{
    class IUnify3DDeviceCG;
    class RenderingSystem : System//, Runnable
    {
    public:
        RenderingSystem(void){}
        ~RenderingSystem(void){}

        virtual void StartUp(void) override;
        virtual void ShutDown(void) override;

        IUnify3DDeviceCG* GetDevice(void)
        {
            return m_pDevice;
        }
//        virtual void Start(void) override {}
//        virtual void Stop(void) override {}

    private:
        IUnify3DDeviceCG* m_pDevice;
    };
}
#endif
