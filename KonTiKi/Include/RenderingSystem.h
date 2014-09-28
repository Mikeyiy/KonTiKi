#ifndef _RENDERING_SYSTEM_H_
#define _RENDERING_SYSTEM_H_
#include <System.h>
#include <Runnable.h>
namespace KonTiKi
{
    class RenderingSystem : System//, Runnable
    {
    public:
        RenderingSystem(void){}
        ~RenderingSystem(void){}

        virtual void StartUp(void) override;
        virtual void ShutDown(void) override;

//        virtual void Start(void) override {}
//        virtual void Stop(void) override {}
    };
}
#endif
