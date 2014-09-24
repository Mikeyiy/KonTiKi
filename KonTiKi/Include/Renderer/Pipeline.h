#ifndef _PIPELINE_H_
#ifndef _PIPELINE_H_
namespace KonTiKi
{
    class Material;
    class Light;
    class Mesh;
    class Pipeline
    {
    public:
        void SetMaterial(Material* pMat);
        void SetLightInfo(std::list<Light*> lights);
        void CommitMesh(Mesh* pMesh);
    };
}
#endif
