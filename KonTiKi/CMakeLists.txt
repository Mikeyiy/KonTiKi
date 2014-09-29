project(KonTiKi)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")
project(KonTiKi)
include_directories(Include)
#参考文章"CMake,OpenGL,and GLX on OS X"
if(APPLE)
    include_directories(/System/Library/Frameworks) 
    include_directories(ThirdParty/include) 
    find_library(COCOA_LIBRARY Cocoa)
    find_library(GLUT_LIBRARY GLUT)
    find_library(OpenGL_LIBRARY OpenGL)
    mark_as_advanced(COCOA_LIBRARY GLUT_LIBRARY OpenGL_LIBRARY)
    set(EXTRA_LIBS ${COCOA_LIBRARY} ${GLUT_LIBRARY} ${OpenGL_LIBRARY})
endif(APPLE)
add_library(kontiki Source/Core/Object.cpp
                    Source/Core/GameObject.cpp
                    Source/Core/GameEngine.cpp
                    Source/Core/Component.cpp
                    Source/Core/System.cpp
                    Source/Core/Transform.cpp
                    Source/Core/GraphicsSystem.cpp
                    Source/Math/Vector.cpp
                    Source/Math/Matrix.cpp
                    Source/Math/Quaternion.cpp
                    Source/Graphics/Camera.cpp
                    Source/Core/RenderingSystem.cpp
                    Source/Renderer/Material.cpp
                    Source/Renderer/GLES2/Unify3DDeviceGLES2.cpp
           )

add_executable(testKonTiKi Source/Test/TestInConsole.cpp
              )      
target_link_libraries(testKonTiKi kontiki ${EXTRA_LIBS})               

enable_testing()
add_test(test01 testKonTiKi)                  

