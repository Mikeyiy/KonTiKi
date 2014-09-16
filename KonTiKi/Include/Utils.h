#ifndef _UTILS_H_
#define _UTILS_H_
namespace KonTiKi
{
    template<typename T>
    inline void Swap(T* a, T* b)
    {
        T pTemp = *a;
        *a = *b;
        *b = pTemp;
    }
}
#endif
