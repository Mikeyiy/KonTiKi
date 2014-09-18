#ifndef _MATERIAL_H_
#define _MATERIAL_H_
namespace KonTiKi
{
    class Shader;
    class Material : Object
    {
    public:
    enum RenderQueue
    {
        BACKGROUD = 1000,
        GEOMETRY = 2000,
        ALPHATEST = 2450,
        TRANSPARENT = 3000,
        OVERLAY = 4000,
    };
    public:
        Material(const std::string contents);

        Material(const Shader& shader);

        int GetPassCount(void) const;

        Shader* GetShader(void) const;

    private:
        Shader* m_pShader;
        int m_queue;        
    };
}
#endif
