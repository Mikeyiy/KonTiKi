project(KonTiKi)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")
project(KonTiKi)
include_directories(Include)

add_library(kontiki Source/Core/Object.cpp
                    Source/Core/GameObject.cpp
                    Source/Core/GameEngine.cpp
                    Source/Core/Component.cpp
                    Source/Core/System.cpp
                    Source/Core/GraphicsSystem.cpp
                    Source/Math/Vector.cpp
                    Source/Math/Matrix.cpp
                    Source/Math/Quaternion.cpp
           )

add_executable(testKonTiKi Source/Test/TestInConsole.cpp
              )      
target_link_libraries(testKonTiKi kontiki)               

enable_testing()
add_test(test01 testKonTiKi)                  

