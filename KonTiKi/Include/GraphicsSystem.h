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

#ifndef _GRAPHICS_SYSTEM_H_
#define _GRAPHICS_SYSTEM_H_

#include "System.h"

namespace KonTiKi
{
    class GraphicsSystem : public System
    {
    public:
    	GraphicsSystem( void ) {}
    	virtual ~GraphicsSystem( void ) {}

    protected:
    	virtual void ProcessGameObject( GameObject& gameObject, float dt ) override;
    private:
        void ArrangeRenderable( MeshFilter& meshfilter, MeshRenderer& meshrenderer, Transform& transfrom );
    };
}

#endif