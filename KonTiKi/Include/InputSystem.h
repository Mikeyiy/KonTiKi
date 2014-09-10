#ifndef _INPUT_SYSTEM_H_
#define _INPUT_SYSTEM_H_
#include <System.h>
#include <Runnable.h>
namespace KonTiKi
{
    class InputSystem : System, Runnable
    {
    public:
        InputSystem(void){}
        ~InputSystem(void){}

        virtual void Start(void) override{}
        virtual void Stop(void) override{}
        
    };
}
#endif
