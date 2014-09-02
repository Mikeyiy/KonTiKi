/*
* 版权所有（C）， 2014， 陈刚
* All rights reserved.
*
* 文件名称： 
* 文件标识：
* 文件摘要：
* 
* 当前版本：
* 摘要：
* 作者：
* 完成日前：
*
* 取代版本：
* 摘要：
* 原作者：
* 完成日前：
*/

#include <iostream>
#include "GraphicsSystem.h"

namespace KonTiKi
{
    void GraphicsSystem::ProcessGameObject( GameObject& gameObject, float dt )
    {
    	std::cout << "ProcessGameObject" << std::endl;
        if( gameObject.meshFilter && gameObject.meshRenderer )
        {
            ArrangeRenderable( gameObject.meshFilter.mesh, gameObject.meshRenderer.materials, gameObject.transform );
        }
        if( gameObject.skinnedMeshRender )    
        {
            
        } 
    }

    void GraphicsSystem::ArrangeRenderable( MeshFilter& meshfilter, MeshRenderer& meshrenderer, Transform& transform )
    {
        // Groups renderalbe data according to material instances.  
        // Meshes appends to different VBO object. 
       
    }
}
