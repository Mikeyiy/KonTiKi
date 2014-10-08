#include <Renderer/GLES2/VertexDataBufferGLES2.h>
#include <cassert>
namespace KonTiKi
{
    VertexDataBufferGLES2::VertexDataBufferGLES2(Type type, unsigned size, const void* data, IVertexDataBuffer::Usage usage) : IVertexDataBuffer(type, size, data, usage)
    {
        glGenBuffers(1, &m_id);
        glBindBuffer(GL_ARRAY_BUFFER, m_id);

        int usageInGL;
        switch(usage) 
        {
        case USAGE_DYNAMIC_DRAW:
        usageInGL = GL_DYNAMIC_DRAW;
        break;
        case USAGE_STREAM_DRAW:
        usageInGL = GL_STREAM_DRAW;
	break;
	case USAGE_STATIC_DRAW:
        default:
        usageInGL = GL_STATIC_DRAW;
        break;
        }

        GLenum target = GetGLBufferTarget(m_type); 
        glBufferData(target, size, data, usageInGL);
    }

    void VertexDataBufferGLES2::Update(unsigned offset, unsigned size, const void* data)
    {
        GLenum target = GetGLBufferTarget(m_type); 
        glBufferSubData(target, offset, size, data);
    }
}
