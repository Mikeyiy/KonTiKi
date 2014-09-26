#ifndef _PIPELINE_H_
#define _PIPELINE_H_
#include <Renderer/IVertexDataBuffer.h>
namespace KonTiKi
{
    class RenderCommand
    {
    public:
        // Command Type.
        enum CommandType 
        {
            RCMD_BLEND,
            RCMD_BLEND_OP,
            RCMD_CULL,
            RCMD_ZWRITE,
            RCMD_ZTEST,
            RCMD_OFFSET, 

            // Draw command.
            RCMD_DRAW,

            // Clear command.
            RCMD_CLEAR,
        }; 

        // Blend command's parameters
        enum BlendCMDParameters
        {
            BLD_ONE,
            BLD_ZERO,
            BLD_SRC_COLOR,
            BLD_SRC_ALPHA,
            BLD_DST_COLOR,
            BLD_DST_ALPHA,
            BLD_ONE_MINUS_SRC_COLOR,
            BLD_ONE_MINUS_SRC_ALPHA,
            BLD_ONE_MINUS_DST_COLOR,
            BLD_ONE_MINUS_DST_ALPHA,
        };

        enum BlendOpCMDParameters
        {
            BLDOP_ADD,
            BLDOP_SUB,
            BLDOP_REV_SUB,
            BLDOP_MIN,
            BLDOP_MAX,
        };

        enum CullCMDParameters
        {
            CULL_BACK,
            CULL_FRONT,
            CULL_OFF,
        };

        enum ZWriteCMDParameters
        {
            ZWRITE_ON,
            ZWRITE_OFF,
        };

        enum ZTestCMDParameters
        {
            ZTEST_LESS,
            ZTEST_GREATER,
            ZTEST_LEQUAL,
            ZTEST_GEQUAL,
            ZTEST_EQUAL,
            ZTEST_NOT_EQUAL,
            ZTEST_ALWAYS,
        };

        enum Topology 
        {
            TOPOLOGY_POINTS,
            TOPOLOGY_LINES,
            TOPOLOGY_LINE_STRIP,
            TOLOGY_LINE_LOOP,
            TOPOLOGY_TRIANGLES,
            TOPOLOGY_TRIANGLE_STRIP,
            TOPOLOGY_TRIANGLE_FAN,
        };

        enum Clear
        {
            CLR_STENCIL,
            CLR_TARGET,
            CLR_ZBUFFER,
        };
    };

    // IDirect3DDevice9 like.
    class IUnify3DDeviceCG
    {
    public:
        virtual void Clear(int flag, const Vector3& color, float z, int stencil) = 0;

        virtual bool SetRenderState(RenderCommand::CommandType cmd, int value) = 0;

        virtual void SetViewport(int x, int y, unsigned w, unsigned h) = 0;

        // 注：和DX不一样,最后一个参数DX是输入图元数量。
        virtual void DrawPrimitive(RenderCMD::Topology topology, unsigned startVertex, unsigned verticesCount) = 0; 

        // 
        virtual void DrawIndexedPrimitive(RenderCMD::Topology topology, unsigned indicesCount, unsigned short* indices) = 0;

        virtual bool CreateVertexDataBuffer(IVertexDataBuffer::Type type, unsigned size, void* data
            , IVertexDataBuffer::Usage, IVertexDataBuffer** ppVertexDataBuffer) = 0;
    };

    // 该接口用于统一D3D9级别的图形API。由全局函数Unify3DCreateXX函数创建。
    // 该接口用于获得物理设备的信和和初始化IUnify3DDeviceCG接口。
    // 该接口用于OpenGL ES 2.0设备时依赖于具体的操作系统和EGL。
    // 该接口用于D3D9设备时依赖于Windows系统和DX API。
    class IUnify3DCG
    {
    public:
        virtual bool CreateDevice(void* params, IUnify3DDeviceCG** ppReturnedDeviceInterface) = 0;    
    };
}
#endif
