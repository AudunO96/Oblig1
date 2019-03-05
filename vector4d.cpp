#include "vector4d.h"

Vector4d::Vector4d(Vector3d vec3d) : arr{vec3d.arr[0],vec3d.arr[1],vec3d.arr[2], 0.0f}
{

}

Vector4d::Vector4d()
{
    for (int i = 0; i < 4; i++)
        arr[i] = 0;
}

std::ostream &operator << (std::ostream& out, const Vector4d &vec4d)
{
    out << vec4d.arr[0] << ", " << vec4d.arr[1] << ", " << vec4d.arr[2] << ", " << vec4d.arr[3];
    return out;
}
