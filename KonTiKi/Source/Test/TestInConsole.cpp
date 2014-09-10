#include <iostream>
#include <cmath>
#include <GameEngine.h>
#include <GameObject.h>
#include <Math/Matrix.h>
#include <Math/ConstantDefine.h>
#include <Math/Quaternion.h>
using namespace KonTiKi;

int main(
    int    argc,
    char** argv
)
{
    std::cout << "Test begin" << std::endl;

    GameEngine* pGameEngine = new GameEngine();

    Matrix4x4 mat;
    //mat.Print();
    //pGameEngine->Update( 0.1f );
    //pGameEngine->Destroy();
    float h = 0.0f;
    float p = 45.0f;
    float b = 0.0f;

    h = h / 180.0 * PI;
    p = p / 180.0 * PI;
    b = b / 180.0 * PI;

    float cosh = cos(h);
    float cosp = cos(p);
    float cosb = cos(b);
    float sinh = sin(h);
    float sinp = sin(p);
    float sinb = sin(b);

    mat.SetElement(0, 0, cosh*cosb + sinh*sinp*sinb);
    mat.SetElement(1, 0, sinb*cosp);
    mat.SetElement(2, 0, -sinh*cosb + cosh*sinp*sinb);
    
    mat.SetElement(0, 1, -cosh*sinb+sinh*sinp*cosb);
    mat.SetElement(1, 1, cosb*cosp);
    mat.SetElement(2, 1, sinb*sinh+cosh*sinp*cosb);

    mat.SetElement(0, 2, sinh*cosp);
    mat.SetElement(1, 2, -sinp);
    mat.SetElement(2, 2, cosh*cosp);

    mat.SetElement(3, 3, 1);
    mat.Print();

    Vector3 v(0, 1, 0);
    Vector3 v1 = mat.MultiplyVector(v);
    v1.Print();

    Matrix4x4 mat1 = EulerToMatrix(45.0f, 150.0f, 120.0f);
    mat1.Print();

    // Vector3's Angle Function Test.
    Vector3 v2(1, 1, 0);
    Vector3 v3(-1, 0, 1);
    float angle = Angle(v2, v3);
    std::cout << angle << std::endl; 

    Vector3 c = Cross(v2, v3);
    c.Print();

    c.Normalize();
    c.Print();

    Quaternion q;
    q.SetFromToRotation(v2, v3);
    q.Print();

    Vector3 v4(2, 5, 8);
    Vector3 v5(5, 2, 1);
    Quaternion q1;
    q1.SetFromToRotation(v4, v5);
    q1.Print();

    Quaternion q2 = EulerToQuaternion(45.0f, 150.0f, 120.0f);
    q2.Print();
    
    Matrix4x4 mat2 = QuaternionToMatrix(q2);
    mat2.Print();

    Vector3 euler = QuaternionToEuler(q2);    
    euler.Print();
    
    printf("Hello! \n");

    Vector3 pos(1, 2, 3);
    Vector3 s(1, 1, 2);
    Matrix4x4 mat3 = TRS(pos, q2, s);
    mat3.Print();

    Angle(q1, q2);
}
