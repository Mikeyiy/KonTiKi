#include <stdlib.h>
#include <Mesh.h>
#include <Math/Vector.h>

namespace KonTiKi
{
    bool Mesh::UploadMeshData(void)
    {
        // 根据具体拥有的顶点属性数据分配内存.
        int sizeOfVertex = 0;
        if( m_vertices )
            sizeOfVertex += sizeof(Vector4);
        if( m_uv )
            sizeOfVertex += sizeof(Vector2);
        if( m_normals )
            sizeOfVertex += sizeof(Vector3);
        if( m_tangents )
            sizeOfVertex += sizeof(Vector4);
        if( m_uv1 )
            sizeOfVertex += sizeof(Vector2);
        if( m_colors )
            sizeOfVertex += sizeof(Vector4);
        m_stride = sizeOfVertex;
        void* pData = malloc(m_stride * m_verticesCount);

        byte* pTemp = (byte*)pData; 
        for(int i=0; i != m_verticesCount; ++i)
        {
            if(m_vertices)    
            {
                (*(Vector4*)pTemp) = Vector4(m_vertices[i], 1.0f);
                pTemp += sizeof(Vector4);
            }
            if(m_uv)    
            {
                (*(Vector2*)pTemp) = m_uv[i];
                pTemp += sizeof(Vector2);
            }
            if(m_normals)    
            {
                (*(Vector3*)pTemp) = m_normals[i];
                pTemp += sizeof(Vector3);
            }
            if(m_tangents)    
            {
                (*(Vector4*)pTemp) = m_tangents[i];
                pTemp += sizeof(Vector4);
            }
            if(m_uv1)    
            {
                (*(Vector2*)pTemp) = m_uv1[i];
                pTemp += sizeof(Vector2);
            }
            if(m_colors)    
            {
                (*(Vector4*)pTemp) = m_vertices[i];
                pTemp += sizeof(Vector4);
            }
        }

        m_offset = 0;
    
        if(!CreateVertexDataBuffer(IVertexDataBuffer::BF_ARRAY_BUFFER, m_stride * m_verticesCount, pData
            , IVertexDataBuffer::USAGE_STATIC_DRAW, m_pVertexBuffer))
            return false;

        if(!CreateVertexDataBuffer(IVertexDataBuffer::BF_ELEMENT_ARRAY_BUFFER
            , sizeof(unsigned short) * m_indicesCount,  
            , (void*)m_triangles,
            , IVertexDataBuffer::USAGE_STATIC_DRAW, m_pIndexBuffer))
            return false;

        return true;
    }
}
