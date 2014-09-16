#include <Math/Vector.h>
namespace KonTiKi
{
        const Vector2 Vector2::up = Vector2(0, 1);
        const Vector3 Vector3::back = Vector3(0, 0, -1);
        const Vector3 Vector3::down = Vector3(0, -1, 0);
        const Vector3 Vector3::forward = Vector3(0, 0, 1);
        const Vector3 Vector3::left = Vector3(-1, 0, 0);
        const Vector3 Vector3::one = Vector3(1, 1, 1);
        const Vector3 Vector3::right = Vector3(1, 0, 0);
        const Vector3 Vector3::up = Vector3(0, 1, 0);
        const Vector3 Vector3::zero = Vector3(0, 0, 0);
        Vector2::Vector2(const Vector3& rhs)
        {
            m[0] = rhs.GetX();
            m[1] = rhs.GetY();
        }

        Vector2::Vector2(const Vector4& rhs)
        {
            m[0] = rhs.GetX();
            m[1] = rhs.GetY();
        }

        Vector3::Vector3(const Vector4& rhs)
        {
            m[0] = rhs.GetX();
            m[1] = rhs.GetY();
            m[2] = rhs.GetZ();
        }

        Vector3::Vector3(const Vector2& rhs)
        {
            m[0] = rhs.GetX();
            m[1] = rhs.GetY();
            m[2] = 0;
        }


}
