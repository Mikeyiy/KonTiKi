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

#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include <type_traits>
#include <vector>
#include "Object.h"
#include "Component.h"

namespace KonTiKi
{
    class GameObject : public Object
    {
        public:
            GameObject( void );
            virtual ~GameObject( void ) {}

            template <typename T>
            T* AddComponent( void );

         private:
         	void Init( void );

        private:
        	std::vector<Component*> m_components;

    };
}

#endif
