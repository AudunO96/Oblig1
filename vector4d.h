#ifndef VECTOR4D_H
#define VECTOR4D_H

#include "vector3d.h"
#include <iostream>

class Vector4d
{
public:
    Vector4d(Vector3d vec3d);
    Vector4d();
    float arr[4];

    Vector3d returnVec4dto3d(){ return Vector3d(arr[0],arr[1],arr[2]); }
    // Overload stream operators << and >>. Let the vector look like (1.0, 2.0, 3.0) when stored
    // on a text file.
    friend std::ostream& operator << (std::ostream& out, const Vector4d &vec4d);

};

#endif // VECTOR4D_H
