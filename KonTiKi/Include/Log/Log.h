#ifndef _LOG_H_
#define _LOG_H_
#include <string>
#include <iostream>
#include <stdio.h>
namespace KonTiKi
{
    class Debug
    {
    public:
        void Log( char* message )     
        {
            printf(": %s \n", message);
        }

        void Log( string message )
        {
            std::cout << ": " << message << std::endl;
        }
    };
}
#endif
