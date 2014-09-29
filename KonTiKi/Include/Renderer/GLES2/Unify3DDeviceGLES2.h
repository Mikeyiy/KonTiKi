#ifndef _UNIFY3D_DEVICE_GLES2_H_
#define _UNIFY3D_DEVICE_GLES2_H_
#include <Renderer/Pipeline.h>

namespace KonTiKi
{
    class Unify3DDeviceGLES2 : IUnify3DDeviceCG
    {
    public: 
        virtual void Clear(int flag, const Vector4& color, float z, int stencil) override;

        virtual bool SetRenderState(RenderCommand::CommandType cmd, int value) override;

        virtual void SetViewport(int x, int y, unsigned w, unsigned h) override;

        virtual bool CreateVertexDataBuffer(IVertexDataBuffer::Type type, unsigned size, void* data
            , IVertexDataBuffer::Usage usage, IVertexDataBuffer** ppVertexDataBuffer) override;

        virtual bool SetStreamSource(unsigned streamNum, IVertexDataBuffer* pStreamData, unsigned offsetInByte, unsigned stride) override;

        virtual bool SetVertexDeclaration(IUnify3DVertexDeclaration* pDecl) override;

        virtual bool LoadVertexShaderFromMemory(const char* shaderSrc, IUnify3DVertexShader* pShader) override;

        virtual bool SetVertexShader(IUnify3DVertexShader* pShader) override;

        virtual bool SetIndices(IVertexDataBuffer* pIndexData) override;

        virtual void DrawPrimitive(RenderCommand::Topology topology, unsigned startVertex, unsigned verticesCount) override;

        virtual void DrawIndexedPrimitive(RenderCommand::Topology, unsigned indicesCount, const void* indices) override;

    };
}
#endif
