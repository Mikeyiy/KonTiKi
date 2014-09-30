#ifndef _VERTEX_DATA_BUFFER_GLES2_H_
#define _VERTEX_DATA_BUFFER_GLES2_H_

#include <Renderer/IVertexDataBuffer.h>

namespace KonTiKi
{
    class VertexDataBufferGLES2 : public IVertexDataBuffer
    {
    public:
        VertexDataBufferGLES2(Type type, unsigned size, const void* data, IVertexDataBuffer::Usage usage);

        virtual void Update(unsigned offset, unsigned size, const void* data) override; 
    }; 
}

#endif
