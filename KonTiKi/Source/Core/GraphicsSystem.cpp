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
#include <cassert>
#include <GraphicsSystem.h>
#include <GameObject.h>
#include <Transform.h>
#include <Camera.h>
#include <Math/Vector.h>
#include <Log/Log.h>
namespace KonTiKi
{
    void GraphicsSystem::Update(void)
    {
        std::vector<Camera*>::iterator cam_iterator = s_cameras.begin();
        for( ; cam_iterator != s_cameras.end(); ++cam_iterator )
        { 
            Camera* pCamera = *cam_iterator;
            assert( pCamera );

            std::list<GameObject*>::iterator iterator = s_gameObjects.begin();
            for( ; iterator != s_gameObjects.end(); ++iterator )
            {
                // 判断所有的Renderable GameObject是否在视景体中。
                GameObject* pGameObject = *iterator;
                assert( pGameObject );
                
                
            }
        }
    }
}
