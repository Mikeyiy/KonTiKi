#include <Renderer/GLES2/Unify3DDeviceGLES2.h>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

namespace KonTiKi
{
    void Unify3DDeviceGLES2::Clear(int flag, const Vector4& color, float z, int stencil)
    {
        int clearMask = 0;
        if( flag | RenderCommand::CLR_TARGET )
        {
            clearMask |= GL_COLOR_BUFFER_BIT;
            glClearColor(color.x, color.y, color.z, color.w);
        }
        if( flag | RenderCommand::CLR_ZBUFFER )
        {
            clearMask |= GL_DEPTH_BUFFER_BIT;
            glClearDepthf(z);
        }
        if( flag | RenderCommand::CLR_STENCIL )
        {
            clearMask |= GL_STENCIL_BUFFER_BIT;
            glClearStencil(stencil);
        }

        glClear(clearMask); 
    } 

    // GL_BLEND, GL_CULL_FACE, GL_DEPTH_TEST,
    // GL_DITHER, GL_POLYGON_OFFSET_FILL,
    // GL_SAMPLE_ALPHA_TO_COVERAGE
    // GL_SAMPLE_COVERAGE
    // GL_SCISSOR_TEST, GL_STENCIL_TEST
    bool Unify3DDeviceGLES2::SetRenderState(RenderCommand::CommandType cmd, int value) {
        switch(cmd)
        {
        case RenderCommand::RCMD_BLEND : 
            if( value == RenderCommand::FALSE )
            {
                glDisable(GL_BLEND);
            }
            else
            {
                glEnable(GL_BLEND);
            }
        break;    
        case RenderCommand::RCMD_CULL : 
        break;    
        case RenderCommand::RCMD_ZWRITE : 
        break;    
        case RenderCommand::RCMD_ZTEST : 
        break;    
        case RenderCommand::RCMD_OFFSET : 
        break;    
        default:
        break;
        }
        
    } 

    void Unify3DDeviceGLES2::SetViewport(int x, int y, unsigned w, unsigned h){} 

    bool Unify3DDeviceGLES2::CreateVertexDataBuffer(IVertexDataBuffer::Type type, unsigned size, void* data
            , IVertexDataBuffer::Usage usage, IVertexDataBuffer** ppVertexDataBuffer){} 

    bool Unify3DDeviceGLES2::SetStreamSource(unsigned streamNum, IVertexDataBuffer* pStreamData, unsigned offsetInByte, unsigned stride){} 

    bool Unify3DDeviceGLES2::SetVertexDeclaration(IUnify3DVertexDeclaration* pDecl){} 

    bool Unify3DDeviceGLES2::LoadVertexShaderFromMemory(const char* shaderSrc, IUnify3DVertexShader* pShader){} 

    bool Unify3DDeviceGLES2::SetVertexShader(IUnify3DVertexShader* pShader){} 

    bool Unify3DDeviceGLES2::SetIndices(IVertexDataBuffer* pIndexData){} 

    void Unify3DDeviceGLES2::DrawPrimitive(RenderCommand::Topology topology, unsigned startVertex, unsigned verticesCount){} 

    void Unify3DDeviceGLES2::DrawIndexedPrimitive(RenderCommand::Topology, unsigned indicesCount, const void* indices){} 
}
