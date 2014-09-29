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

#include <GameEngine.h>
#include <System.h>
#include <cassert>
#include <GraphicsSystem.h>
#include <RenderingSystem.h>
#include <InputSystem.h>

namespace KonTiKi
{

    RenderingSystem g_RenderingSystem;
    GraphicsSystem g_GraphicsSystem;

    GameEngine::GameEngine( void )
    {
        Init();
    }

    void GameEngine::Init( void )
    {
//        m_pRenderingSystem = new RenderingSystem();
//        m_pRenderingSystem->Start();

//        m_pInputSystem = new InputSystem();
//        m_pInputSystem->Start(); 

        // 初始化各个系统模块。
//        m_pGraphicsSystem = new GraphicsSystem();
        
        g_RenderingSystem.StartUp();
        g_GraphicsSystem.StartUp();
    }

    void GameEngine::Update(void)
    {
//        m_pGraphicsSystem->Update();
        g_GraphicsSystem.Update();
    }

    void GameEngine::Destroy(void)
    {
//        delete m_pGraphicsSystem;

//        m_pInputSystem->Stop();
//        m_pRenderingSystem->Stop();
        g_GraphicsSystem.ShutDown();
        g_RenderingSystem.ShutDown();
    }

}
