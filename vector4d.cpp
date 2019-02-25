#include "vector4d.h"

Vector4d::Vector4d(Vector3d vec3d) : arrei{vec3d.arr[0],vec3d.arr[1],vec3d.arr[2], 0.0f}
{

}

std::ostream &operator << (std::ostream& out, const Vector4d &vec4d)
{
    out << vec4d.arrei[0] << ", " << vec4d.arrei[1] << ", " << vec4d.arrei[2] << ", " << vec4d.arrei[3];
    return out;
}
