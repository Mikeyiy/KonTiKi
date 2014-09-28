#ifndef _MESH_H_
#define _MESH_H_

namespace KonTiKi
{
    class Mesh
    {
    public:
        Mesh(void) : m_verticesCount(0), m_indicesCount(0), m_vertices(nullptr)
            , m_tangents(nullptr)
            , m_normals(nullptr), m_uv(nullptr), m_uv1(nullptr)
            , m_colors(nullptr), m_triangles(nullptr), m_vertexBuffer(null_ptr)
            , m_indexBuffer(nullptr)
        {};
        virtual ~Mesh(void){}; 
        int GetSubMeshCount(void){return 1;}        

        unsigned int m_verticesCount;
        unsigned int m_indicesCount;
        Vector3* m_vertices;
        Vector4* m_tangents;
        Vector3* m_normals;
        Vector2* m_uv;
        Vector2* m_uv1;
        Vector4* m_colors;
        unsigned short* m_triangles;

        bool UploadMeshData(void);

    public:
        unsigned m_offset;
        unsigned m_stride;
        IVertexDataBuffer* m_pVertexBuffer;
        IVertexDataBuffer* m_pIndexBuffer;

        // World transformed vertices.

        // VBO info. VBO ptr, offsets
    };
}


#endif
