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
#include "GraphicsSystem.h"

namespace KonTiKi
{
    GameEngine::GameEngine( void )
    {
        Init();
    }

    void GameEngine::Init( void )
    {
        // m_renderer = new Renderer();
        // m_renderer.Start();

        // m_input = new Input();
        // m_input.Start(); 

        // 初始化各个系统模块。
        GraphicsSystem* pGraphicsSystem = new GraphicsSystem();
        m_systems.push_back( pGraphicsSystem );

        std::cout << " Init " << std::endl;

        // Load Scenes
        // Main Loop.
        // while( true )
        // {
        //     Update( Time.deltaTime );
        // }

        // Destroy each systems.

        // m_input.End();
        // m_renderer.End();
    }

    void GameEngine::Update( float dt )
    {
        std::vector<System*>::iterator iterator = m_systems.begin();

    	//for( size_t i = 0; i != m_systems.size(); ++i )
        for( ; iterator != m_systems.end(); ++iterator )
    	{
            System* pSystem =  *iterator;
            assert( pSystem != nullptr );

            pSystem->Update( dt );
            std::cout << " Update " << std::endl;
    	}

    }

    void GameEngine::MainLoop( void )
    {
    }


}
