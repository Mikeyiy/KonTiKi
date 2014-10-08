#ifndef _VERTEX_DATA_BUFFER_GLES2_H_
#define _VERTEX_DATA_BUFFER_GLES2_H_

#include <cassert>
#include <GLES2/gl2.h>
#include <Renderer/IVertexDataBuffer.h>

namespace KonTiKi
{
    class VertexDataBufferGLES2 : public IVertexDataBuffer
    {
    public:
        VertexDataBufferGLES2(Type type, unsigned size, const void* data, IVertexDataBuffer::Usage usage);

        virtual void Update(unsigned offset, unsigned size, const void* data) override; 

        unsigned GetBufferId(void)
        {
            return m_id;
        }

    private:
        inline GLenum GetGLBufferTarget(Type type) 
        {
            assert(type == BF_ARRAY_BUFFER || type == BF_ELEMENT_ARRAY_BUFFER);
            GLenum target; 
            if(type == BF_ARRAY_BUFFER)
            {
                target = GL_ARRAY_BUFFER;
            }
            else
            {
                target = GL_ELEMENT_ARRAY_BUFFER;
            }
            return target;
        }
    private:
        unsigned m_id;
    }; 
}

#endif
