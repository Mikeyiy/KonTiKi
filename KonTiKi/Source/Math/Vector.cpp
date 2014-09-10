#include <Math/Vector.h>
namespace KonTiKi
{
        const Vector2 Vector2::up = Vector2(0, 1);
        const Vector3 Vector3::up = Vector3(0, 1, 0);
        Vector2::Vector2(const Vector3& rhs)
        {
            v[0] = rhs.GetX();
            v[1] = rhs.GetY();
        }

        Vector2::Vector2(const Vector4& rhs)
        {
            v[0] = rhs.GetX();
            v[1] = rhs.GetY();
        }

        Vector3::Vector3(const Vector4& rhs)
        {
            v[0] = rhs.GetX();
            v[1] = rhs.GetY();
            v[2] = rhs.GetZ();
        }

        Vector3::Vector3(const Vector2& rhs)
        {
            v[0] = rhs.GetX();
            v[1] = rhs.GetY();
            v[2] = 0;
        }


}
