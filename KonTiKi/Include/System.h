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


#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include <list>
#include <vector>
#include "Object.h"

namespace KonTiKi
{
    class GameObject;
    class Camera;
    class System : public Object
    {
    public:
        System( void ) {}
        virtual ~System( void ) {}

        virtual void StartUp(void) = 0;
        virtual void ShutDown(void) = 0;

    	void Update( float dt );

        static void AddGameObject( GameObject* pGameObject )
        {
            s_gameObjects.push_back( pGameObject );
        }

    protected:
    	static std::list<GameObject*> s_gameObjects;
        static std::vector<Camera*> s_cameras;
    };

}

#endif
