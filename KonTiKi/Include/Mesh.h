#ifndef _MESH_H_
#define _MESH_H_

namespace KonTiKi
{
    class Mesh
    {
    public:
        Mesh(void){};
        virtual ~Mesh(void){}; 
        int GetSubMeshCount(void){return 1;}        
    };
}


#endif
