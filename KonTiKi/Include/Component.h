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

#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include "Object.h"

namespace KonTiKi
{
    class GameObject;

    class Component : public Object
    {
    public:
    	Component( GameObject* pAttatchedGameObject );

    public:
        GameObject* pGameObject;
    };
}

#endif
