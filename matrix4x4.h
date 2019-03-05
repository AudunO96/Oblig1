#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include "vector4d.h"
#include "vector3d.h"


class Matrix4x4
{
public:

    //flere typer konstruktorer for forskjellige use cases
    Matrix4x4(float arr[4][4]);
    Matrix4x4();

    //array for å store verdier i objektets matrise
    float arr[4][4];

    //overloaders
    Matrix4x4 operator * (float v);
    Matrix4x4 operator * (const Matrix4x4& v) const;
    Vector4d operator * (const Vector4d& v) const;

    //skalering, rotering og translering av en 4x4 matrise i 3d
    void scale(float x, float y, float z);
    void rotate(float rotateAng, Vector3d rotate);
    void translate(float tx, float ty, float tz);

    //hjelpefunksjon for å lage en identitetsmatrise
    void setToIdentity();
};

#endif // MATRIX4X4_H
