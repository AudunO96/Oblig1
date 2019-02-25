#ifndef VECTOR4D_H
#define VECTOR4D_H

#include "vector3d.h"
#include <iostream>

class Vector4d
{
public:
    Vector4d(Vector3d vec3d);
    float arrei[4];

    Vector3d returnVec4dto3d(){ return Vector3d(arrei[0],arrei[1],arrei[2]); }
    // Overload stream operators << and >>. Let the vector look like (1.0, 2.0, 3.0) when stored
    // on a text file.
    friend std::ostream& operator << (std::ostream& out, const Vector4d &vec4d);

};

#endif // VECTOR4D_H
