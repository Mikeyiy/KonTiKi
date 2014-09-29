#ifndef _PIPELINE_H_
#define _PIPELINE_H_
#include <Renderer/IVertexDataBuffer.h>
#include <Math/Vector.h>
namespace KonTiKi
{
    enum Unify3DDeclType
    {
        UNIFYDECLTYPE_FLOAT1,
        UNIFYDECLTYPE_FLOAT2,
        UNIFYDECLTYPE_FLOAT3,
        UNIFYDECLTYPE_FLOAT4,
    };

    enum Unify3DDeclMethod
    {
        UNIFYDECLMETHOD_DEFAULT = 0,
    };

    enum Unify3DDeclUsage
    {
        UNIFYDECLUSAGE_POSITION,
        UNIFYDECLUSAGE_BLENDWEIGHT = 1,
        UNIFYDECLUSAGE_BLENDINDICES = 2,
        UNIFYDECLUSAGE_NORMAL = 3,
        UNIFYDECLUSAGE_PSIZE = 4,
        UNIFYDECLUSAGE_TEXCOORD = 5,
        UNIFYDECLUSAGE_TANGENT = 6,
        UNIFYDECLUSAGE_BINORMAL = 7,
        UNIFYDECLUSAGE_TESSFACTOR = 8,
        UNIFYDECLUSAGE_POSITIONT = 9,
        UNIFYDECLUSAGE_COLOR = 10,
        UNIFYDECLUSAGE_FOG = 11,
        UNIFYDECLUSAGE_DEPTH = 12,
        UNIFYDECLUSAGE_SAMPLE = 13,
    };

    struct Unify3DVertexElementCG
    {
        unsigned short stream;
        unsigned short offset;
        char type;
        char method;
        char usage;
        char usageIndex;
    };

    //     
    class IUnify3DVertexDeclaration
    {
    class IUnify3DDeviceCG;
    public:
        // Get the vertex shader declaration.
        bool GetDeclaration(Unify3DVertexElementCG* pDecl, unsigned* pNumElements);
        // Pointer to the IUnify3DDeviceCG interface that is returned.
        bool GetDevice(IUnify3DDeviceCG** ppDevice);
    }; 

    class RenderCommand
    {
    public:
        enum RS_Bool
        {
            FALSE,
            TRUE,
        };

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
            CLR_STENCIL = 1,
            CLR_TARGET = 1 << 1,
            CLR_ZBUFFER = 1 << 2,
        };
    };

    class Unify3DConstantTable;

    class IUnify3DDeviceCG;
    class IUnify3DVertexShader
    {
    public:
        virtual IUnify3DDeviceCG* GetDevice(void);
        // If OpenGL, return handle.
        // If DX, return pointer to a buffer that contains the shader data. 
        virtual void* GetFunction(void) = 0;

        virtual char* GetCompiledLog(void) = 0;
        // D3DCONSTANTTABLE like.
        virtual Unify3DConstantTable* GetConstantTable(void) = 0;
    };

    // IDirect3DDevice9 like.
    class IUnify3DDeviceCG
    {
    public:
        virtual void Clear(int flag, const Vector4& color, float z, int stencil) = 0;

        virtual bool SetRenderState(RenderCommand::CommandType cmd, int value) = 0;

        virtual void SetViewport(int x, int y, unsigned w, unsigned h) = 0;

        virtual bool CreateVertexDataBuffer(IVertexDataBuffer::Type type, unsigned size, void* data
            , IVertexDataBuffer::Usage usage, IVertexDataBuffer** ppVertexDataBuffer) = 0;

        virtual bool SetStreamSource(unsigned streamNum, IVertexDataBuffer* pStreamData, unsigned offsetInByte, unsigned stride) = 0;

        virtual bool SetVertexDeclaration(IUnify3DVertexDeclaration* pDecl) = 0;

        virtual bool LoadVertexShaderFromMemory(const char* shaderSrc, IUnify3DVertexShader* pShader) = 0;
        virtual bool SetVertexShader(IUnify3DVertexShader* pShader) = 0;

        virtual bool SetIndices(IVertexDataBuffer* pIndexData) = 0;

        // 注：和DX不一样,最后一个参数DX是输入图元数量。
        virtual void DrawPrimitive(RenderCommand::Topology topology, unsigned startVertex
            , unsigned verticesCount) = 0; 

        // 
        virtual void DrawIndexedPrimitive(RenderCommand::Topology topology
            , unsigned indicesCount, const void* indices) = 0;
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
