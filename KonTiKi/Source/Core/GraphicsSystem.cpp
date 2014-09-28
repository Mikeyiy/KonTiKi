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
    virtual GraphicsSystem::StartUp(void) override {}

    virtual GraphicsSystem::ShutDown(void) override {}

    void GraphicsSystem::Update(void)
    {
        std::vector<Camera*>::iterator cam_iterator = s_cameras.begin();
        // 需要对Camera排序，根据depth.
        for( ; cam_iterator != s_cameras.end(); ++cam_iterator )
        { 
            Camera* pCamera = *cam_iterator;
            assert( pCamera );
            pCamera->CollectAndSort(s_gameObjects);
        }
        // 假设现在填充第N帧完成，欲填充第N+1帧的数据，检查第N-1帧是否渲染结束，否则等待。
        // 若已渲染完成，则翻转缓冲区，并开始填充N+1帧。 
        // 设想如果用轮询机制，则可以在渲染命令缓冲设置一个能否读写的标识。
        // 如果使用线程间信号同步则可能性能要好一些。 
        for( ; cam_iterator != s_cameras.end(); ++cam_iterator )
        {
            Camera* pCamera = *cam_iterator;
            pCamera->Render();
        }
        // 第N+1帧渲染命令已填充完毕。
    }
}
