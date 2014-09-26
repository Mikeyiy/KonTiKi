#ifndef _MATERIAL_H_
#define _MATERIAL_H_
#include <Object.h>
#include <string>
namespace KonTiKi
{
    class Shader;
    class Material : Object
    {
    public:
    enum RenderQueue
    {
        QUEUE_BACKGROUD = 1000,
        QUEUE_GEOMETRY = 2000,
        QUEUE_ALPHATEST = 2450,
        QUEUE_TRANSPARENT = 3000,
        QUEUE_OVERLAY = 4000,
    };

    enum RenderType
    {
        TYPE_OPAQUE,
        TTYPE_RANSPARENT,
        TTYPE_RANSPARENT_CUTOUT,
        TYPE_BACKGROUND,
        TYPE_OVERLAY,
        TYPE_TREE_OPAQUE,
        TYPE_TREE_TRANSPARENT_CUTOUT,
        TYPE_TREE_BILLBOARD,
        TYPE_GRASS,
        TYPE_GRASS_BILLBOARD,
    };
    public:
        Material(const std::string& contents);

        Material(const Shader& shader);

        ~Material(void){}

        int GetMaterialsCount(void) const 
        {
            return 0;
        }

        int GetPassCount(void) const
        {
            return 0;
        }

        Shader* GetShader(void) const
        {
            return nullptr;
        }
        
        const int GetRenderQueue(void) const
        {
            return m_queue;
        }

        const bool IsTransparent(void) const
        {
            return false;
        }
    private:
        Shader* m_pShader;
        int m_queue;        
        // Material Container.
    };
 
    extern Material* GetErrorMaterial(void);
}
#endif
