#ifndef _UNIFY3D_DEVICE_GLES2_H_
#define _UNIFY3D_DEVICE_GLES2_H_
#include <Renderer/Pipeline.h>
#include <GLES2/gl2.h>
namespace KonTiKi
{
    class Unify3DVertexShaderGLES2 : public IUnify3DVertexShader
    {
    public:
        Unify3DVertexShaderGLES2(GLuint handle, IUnify3DDeviceCG* pDevice) : m_handle(handle), m_pDevice(pDevice)
        {}

        virtual IUnify3DDeviceCG* GetDevice(void) const override
        {
            return m_pDevice;
        }

        virtual void* GetFunction(void) const override
        {
            return (void*)&m_handle;
        }

    private:
        IUnify3DDeviceCG* m_pDevice;
        GLuint m_handle;
    };

    class Unify3DFragmentShaderGLES2 : public IUnify3DFragmentShader
    {
    public:
        Unify3DFragmentShaderGLES2(GLuint handle, IUnify3DDeviceCG* pDevice) : m_handle(handle), m_pDevice(pDevice)
        {}

        virtual IUnify3DDeviceCG* GetDevice(void) const override
        {
            return m_pDevice;
        }

        virtual void* GetFunction(void) const override
        {
            return (void*)&m_handle;
        }

    private:
        IUnify3DDeviceCG* m_pDevice;
        GLuint m_handle;
    };


    class Unify3DDeviceGLES2 : IUnify3DDeviceCG
    {
    public: 
        virtual void Clear(int flag, const Vector4& color, float z, int stencil) override;

        virtual bool SetRenderState(RenderCommand::CommandType cmd, int value) override;

        virtual void SetViewport(int x, int y, unsigned w, unsigned h) override;

        virtual bool CreateVertexDataBuffer(IVertexDataBuffer::Type type, unsigned size, void* data
            , IVertexDataBuffer::Usage usage, IVertexDataBuffer** ppVertexDataBuffer) override;

        virtual bool CreateVertexDeclaration(Unify3DVertexElementCG* pVertexElements, unsigned numElements, IUnify3DVertexDeclaration** ppDecl) override;

        virtual bool SetVertices(unsigned streamNum, IVertexDataBuffer* pStreamData, unsigned offsetInByte, unsigned stride, IUnify3DVertexDeclaration* pDecl) override;

//        virtual bool SetVertexDeclaration(IUnify3DVertexDeclaration* pDecl) override;

        virtual bool LoadVertexShaderFromMemory(const char* shaderSrc, IUnify3DVertexShader** pShader) override;

        virtual bool SetVertexShader(IUnify3DVertexShader* pShader) override;

        virtual bool LoadFragmentShaderFromMemory(const char* shaderSrc, IUnify3DFragmentShader** pShader) override;

        virtual bool SetFragmentShader(IUnify3DFragmentShader* pShader) override;


        virtual bool SetIndices(IVertexDataBuffer* pIndexData) override;

        virtual void DrawPrimitive(RenderCommand::Topology topology, unsigned startVertex, unsigned verticesCount) override;

        virtual void DrawIndexedPrimitive(RenderCommand::Topology, unsigned indicesCount, const void* indices) override;

    private:
        const unsigned VERTEX_POS_INDEX = 0;
        const unsigned VERTEX_NORMAL_INDEX = 1;
        const unsigned VERTEX_TEXCOORD0_INDEX = 2;
        const unsigned VERTEX_TEXCOORD1_INDEX = 2;

        GLuint m_program;

        IUnify3DVertexShader* m_pVertexShader;
        IUnify3DFragmentShader* m_pFragmentShader;

        IVertexDataBuffer* m_pIndexData;
       
    };
}
#endif
