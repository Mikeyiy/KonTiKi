#ifndef _MATERIAL_H_
#define _MATERIAL_H_
namespace KonTiKi
{
    class Shader;
    class Material : Object
    {
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
