#include <Renderer/Material.h>
#include <Renderer/Shader.h>
namespace KonTiKi
{
    Material::Material(const std::string& contents)    
    {
        // ShaderManger parses the contents and ...
    }

    Material::Material(const Shader& shader)
    {
    
    }

    Material* GetErrorMaterial(void)
    {
        // Get it from MaterialManager.
        return nullptr;
    }
}
