#ifndef _RUNNABLE_H_
#define _RUNNABLE_H_

namespace KonTiKi
{
    class Runnable
    {
    public:
        virtual void Start(void) = 0;
        virtual void Stop(void) = 0;
    };
}

#endif
