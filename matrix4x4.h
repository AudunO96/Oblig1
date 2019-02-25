#ifndef MATRIX4X4_H
#define MATRIX4X4_H


class Matrix4x4
{
public:
    Matrix4x4();
    Matrix4x4 operator * (const Matrix4x4& v) const;
    float arr[4][4];

};

#endif // MATRIX4X4_H
