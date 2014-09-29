#include <iostream>
#include <cmath>
#include <GameEngine.h>
#include <GameObject.h>
#include <Math/Matrix.h>
#include <Math/ConstantDefine.h>
#include <Math/Quaternion.h>
#include <Transform.h>
#include <GLUT/GLUT.h>
using namespace KonTiKi;
#if defined(__APPLE__)
#define TEST_MACRO 100
#endif

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
    glEnd();
    glFlush();
}


int main(
    int    argc,
    char** argv
)
{
/*    glutInit(&argc, argv);
    glutCreateWindow("Xcode Glut Demo");
    glutDisplayFunc(display);
    glutMainLoop();

    int a = TEST_MACRO;
    std::cout << "Test begin" << std::endl;
*/
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

    printf("-------mat3 inverse:\n");
    Matrix4x4 mat4 = Inverse(mat3);
    mat4.Print();

    printf("-------mat3 inverse:\n");
    mat3.GetInverse().Print();
    Matrix4x4 mat5 = mat3 * mat4;
    mat5.Print();

    if( mat5.IsIdentity() )
    {
        printf("Yes \n");
    }
    else
    {
        printf("No \n");
    }

    printf("View Matrix: \n");
    mat5 = GetWorldToCameraMatrix(Vector3(10, 1, 1), Vector3(5, 10, 12), Vector3(1, 10, 1));
    mat5.Print();

    mat5 = Perspective(60, 2, 2, 100);
    mat5.Print();

    Quaternion q3 = EulerToQuaternion(12.42, 25.74, 34.35);
    mat5 = TRS(Vector3(5.9604, 0, -8.94069), q3, s);
    mat5.Print();

    mat5 = mat5.GetTranspose();
    mat5.Print();

    printf("---------Transform-------------\n");
    Transform t(nullptr);
    t.SetLocalPosition(Vector3(5.96, 1, -8.9));
    t.SetLocalEulerAngles(Vector3(12.42, 25.74, 34.35));
    t.SetLocalScale(Vector3(1, 1, 1));
    mat5 = t.GetLocalToWorldMatrix(); 
    mat5.Print();

    mat4 = t.GetWorldToLocalMatrix();
    mat4.Print();
    (mat4*mat5).Print();
}
