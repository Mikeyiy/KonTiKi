#ifndef _MESH_H_
#define _MESH_H_
namespace KonTiKi
{
    class Matrix4x4;
    class BoneWeight;
    class Color;
    class Color32;
    class Bounds;
    struct Vector2;
    struct Vector3;
    struct Vector4;
    class Mesh : Object
    {
    public:
        Mesh(void);

        
    public:
        // The bind poses.
        Matrix4x4* bindposes;

        // The bone weights of each vertex.
        BoneWeight* boneWeights;

        // The bounding volume of mesh.

        // Vertex colors of the mesh.
        Color* colors;
        Color32* colors32;

        // The normals of the mesh.
        Vector3* normals;

        // The tangents of the mesh.
        Vector4* tangents;

        // The positions of the mesh.
        Vector4* vertices;       

        // The indices of the mesh.
        int* triangles;

        // the number of vertices in the mesh.
        int vertexCount;

        // The base coordinate set of the mesh.
        Vector2* uv;

        // The second texture coordinate set of the mesh, if present.
        Vector2* uv2;

        // The number of submeshes.
        int subMeshCount;
    };
}
#endif
