#include <Renderer/GLES2/VertexDataBufferGLES2.h>

namespace KonTiKi
{
    VertexDataBufferGLES2::VertexDataBufferGLES2(Type type, unsigned size, const void* data, IVertexDataBuffer::Usage usage) : IVertexDataBuffer(type, size, data, usage)
    {}

    void Update(unsigned offset, unsigned size, const void* data)
    {}
}
