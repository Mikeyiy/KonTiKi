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
/*
+--------------------------------+
|     Engine Start               |
|         |                      |
|     Run Rendering Thread       |
|         |                      |
|     Run Input Thread           |
|         |                      |
|    Init Graphics System        |
|         |                      |
|    Init Physics System         |
|         |                      |
|     any more System            |
|         |                      |
|    Run Main Loop               |
|         |                      |
|     Destroy Self               |
+--------------------------------+
*/
#ifndef _GAME_ENGINE_H_
#define _GAME_ENGINE_H_

#include <vector>
#include "Object.h"
#include <RenderingSystem.h>
#include <GraphicsSystem.h>
namespace KonTiKi
{
//    class InputSystem;

    extern RenderingSystem g_RenderingSystem;
    extern GraphicsSystem g_GraphicsSystem;

    class GameEngine : public Object
    {
    public:
        GameEngine(void); 
        ~GameEngine(void);

    public:
    	void Update(void);
    	void Init(void);
        void Destroy(void);

    };
}

#endif
