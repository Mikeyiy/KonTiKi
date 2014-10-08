#include <Renderer/GLES2/Unify3DDeviceGLES2.h>
#include <GLES2/gl2.h>
#include <Renderer/GLES2/VertexDataBufferGLES2.h>

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
            if(value != RenderCommand::CULL_OFF)
            {
                glEnable(GL_CULL_FACE);
                if(value == RenderCommand::CULL_BACK)
                {
                    glCullFace(GL_BACK);
                }
                else
                {
                    glCullFace(GL_FRONT);
                }
            }
            else
            {
                glDisable(GL_CULL_FACE);
            }
        break;    
        case RenderCommand::RCMD_ZWRITE : 
            if( value == RenderCommand::FALSE)
            {
                glDepthMask(GL_FALSE);
            }
            else
            {
                glDepthMask(GL_TRUE);
            }
        break;    
        case RenderCommand::RCMD_ZTEST : 
            glEnable(GL_DEPTH_TEST);
            GLenum func;
            switch(value)
            {
            case RenderCommand::ZTEST_LESS:
            default: 
                {
                     func = GL_LESS;
                }
            break;
            case RenderCommand::ZTEST_GREATER:
                {
                     func = GL_GREATER; 
                }
            break;
            case RenderCommand::ZTEST_LEQUAL:
                {
                     func = GL_LEQUAL; 
                }
            break;
            case RenderCommand::ZTEST_GEQUAL:
                {
                     func = GL_GEQUAL; 
                }
            break;
            case RenderCommand::ZTEST_EQUAL:
                {
                     func = GL_EQUAL; 
                }
            break;
            case RenderCommand::ZTEST_NOT_EQUAL:
                {
                     func = GL_NOTEQUAL; 
                }
            break;
            case RenderCommand::ZTEST_ALWAYS:
                {
                     func = GL_ALWAYS; 
                }
            break;
            }
            glDepthFunc(func);
        break;    
        default:
        break;
        }
        
    } 

    void Unify3DDeviceGLES2::SetViewport(int x, int y, unsigned w, unsigned h)
    {
        glViewport(x, y, w, h);
    } 

    bool Unify3DDeviceGLES2::CreateVertexDataBuffer(IVertexDataBuffer::Type type, unsigned size, void* data
            , IVertexDataBuffer::Usage usage, IVertexDataBuffer** ppVertexDataBuffer)
    {
        IVertexDataBuffer* pVB = new VertexDataBufferGLES2(type, size, data, usage);
        if(pVB)
        {
            ppVertexDataBuffer = &pVB;
            return true;
        }
        else
        {
            ppVertexDataBuffer = nullptr;
            return false;
        }
    } 

    bool Unify3DDeviceGLES2::CreateVertexDeclaration(Unify3DVertexElementCG* pVertexElements, unsigned numElements, IUnify3DVertexDeclaration** ppDecl)
    {
        IUnify3DVertexDeclaration* pDecl = new IUnify3DVertexDeclaration(pVertexElements, numElements, (IUnify3DDeviceCG*)this);        
        ppDecl = &pDecl;
        return true;
    }

    bool Unify3DDeviceGLES2::SetVertices(unsigned streamNum, IVertexDataBuffer* pStreamData, unsigned offsetInByte, unsigned stride, IUnify3DVertexDeclaration* pDecl)
{
    Unify3DVertexElementCG** ppDecl;
    unsigned* pNumElements;

    pDecl->GetDeclaration(ppDecl, pNumElements);            
    VertexDataBufferGLES2* pVertexDataBuffer = dynamic_cast<VertexDataBufferGLES2*>(pStreamData); 
    unsigned bufferId = pVertexDataBuffer->GetBufferId();
    GLuint offset = offsetInByte;
    glBindBuffer(GL_ARRAY_BUFFER, bufferId);

    for(int i = 0; i != *pNumElements; ++i)
    {
        Unify3DVertexElementCG vertexElement = (*ppDecl)[i];
        int declUsage = vertexElement.usage; 

        unsigned vertexAttribIndex = 0;
        int componentSize = 0;
        
        switch(declUsage)
        {
        case UNIFYDECLUSAGE_POSITION:
        vertexAttribIndex = VERTEX_POS_INDEX; 
        glBindAttribLocation(m_program, VERTEX_POS_INDEX, "v_position");
        break;
        case UNIFYDECLUSAGE_NORMAL:
        vertexAttribIndex = VERTEX_NORMAL_INDEX;
        glBindAttribLocation(m_program, VERTEX_NORMAL_INDEX, "v_normal");
        break;
        case UNIFYDECLUSAGE_TEXCOORD:
        if(vertexElement.usageIndex == 0)
        {
            vertexAttribIndex = VERTEX_TEXCOORD0_INDEX;
            glBindAttribLocation(m_program, VERTEX_TEXCOORD0_INDEX, "v_texcoord0");
        }
        else
        {
            vertexAttribIndex = VERTEX_TEXCOORD1_INDEX;
            glBindAttribLocation(m_program, VERTEX_TEXCOORD1_INDEX, "v_texcoord1");
        }
        break;
        default:
        break;
        }
        glEnableVertexAttribArray(vertexAttribIndex);
        
        offset += vertexElement.offset; 

        switch(vertexElement.type)
        { 
        case UNIFYDECLTYPE_FLOAT1:
        componentSize = 1;
        break;
        case UNIFYDECLTYPE_FLOAT2:
        componentSize = 2;
        break;
        case UNIFYDECLTYPE_FLOAT3:
        componentSize = 3;
        break;
        case UNIFYDECLTYPE_FLOAT4:
        componentSize = 4;
        break;
        default:
        break;
        }

        glVertexAttribPointer(vertexAttribIndex, componentSize, GL_FLOAT, GL_FALSE, 0, (const void*)offset);
    }
} 

    //bool Unify3DDeviceGLES2::SetVertexDeclaration(IUnify3DVertexDeclaration* pDecl){} 

    bool Unify3DDeviceGLES2::LoadVertexShaderFromMemory(const char* shaderSrc, IUnify3DVertexShader** ppShader)
    {
        GLuint shaderHandle = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(shaderHandle, 1, &shaderSrc, nullptr);

        glCompileShader(shaderHandle);

        // Test if compilation succeeded.
        GLint shaderCompiled;
        glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &shaderCompiled);
 
        if(!shaderCompiled)
        {
            glDeleteShader(shaderHandle);
            return false;
        }

        Unify3DVertexShaderGLES2* pShader = new Unify3DVertexShaderGLES2(shaderHandle, this);                
        *ppShader = pShader;
    } 

    bool Unify3DDeviceGLES2::SetVertexShader(IUnify3DVertexShader* pShader)
    {
        m_pVertexShader = pShader; 
 
        return true;
    } 

    bool Unify3DDeviceGLES2::LoadFragmentShaderFromMemory(const char* shaderSrc, IUnify3DFragmentShader** ppShader)
    {
        GLuint shaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(shaderHandle, 1, &shaderSrc, nullptr);

        glCompileShader(shaderHandle);

        // Test if compilation succeeded.
        GLint shaderCompiled;
        glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &shaderCompiled);
 
        if(!shaderCompiled)
        {
            glDeleteShader(shaderHandle);
            return false;
        }

        Unify3DFragmentShaderGLES2* pShader = new Unify3DFragmentShaderGLES2(shaderHandle, this);                
        *ppShader = pShader;
     
        return true;
    } 

    bool Unify3DDeviceGLES2::SetFragmentShader(IUnify3DFragmentShader* pShader)
    {
        m_pFragmentShader = pShader; 
    } 


    bool Unify3DDeviceGLES2::SetIndices(IVertexDataBuffer* pIndexData)
    {
        m_pIndexData = pIndexData;
        return true;
    } 

    

    void Unify3DDeviceGLES2::DrawPrimitive(RenderCommand::Topology topology, unsigned startVertex, unsigned verticesCount){} 

    void Unify3DDeviceGLES2::DrawIndexedPrimitive(RenderCommand::Topology, unsigned indicesCount, const void* indices)
{
    // 
        

   // VertexDataBufferGLES2* pVertexDataBuffer = dynamic_cast<VertexDataBufferGLES2*>(pStreamData); 
    //unsigned bufferId = pVertexDataBuffer->GetBufferId();
} 
}
