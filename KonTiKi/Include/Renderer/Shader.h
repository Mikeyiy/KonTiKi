#ifndef _SHADER_H_
#define _SHADER_H_
#include <string>
namespace KonTiKi
{
    class Shader
	{
    public:
        // Render queue of this shader. 
        int GetRenderQueue(void);		
	};

    Shader* Find(const std::string shaderName) ;
}
#endif
