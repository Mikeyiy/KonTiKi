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
#include "System.h"

namespace KonTiKi
{
    std::list<GameObject*> System::s_gameObjects;

	void System::Update( float dt )
    {
    	std::cout << "System Update" << std::endl;
    	std::list<GameObject*>::iterator iterator = s_gameObjects.begin();
        for(; iterator != s_gameObjects.end(); ++iterator)
        {
            ProcessGameObject( **iterator, dt );
        }
    }
}