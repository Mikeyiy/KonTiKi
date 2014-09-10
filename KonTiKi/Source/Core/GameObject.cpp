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

#include "GameObject.h"
#include "Transform.h"
#include "System.h"

namespace KonTiKi
{
    GameObject::GameObject( void )
    {
    	Init();
    }

    void GameObject::Init( void )
    {
        AddComponent<Transform>();

        System::AddGameObject( this );
    }

    template <typename T>
    T* GameObject::AddComponent( void )
    {
    	//static_assert( std::is_same<int, int>::value );
    	T* ret = new T( this );
    	if( ret )
    	    m_components.push_back( ret );
        return ret;
    }
}
