#include "matrix4x4.h"
#include "math.h"

//constructor
Matrix4x4::Matrix4x4(float arrei[4][4]) : arr{{arrei[0][0],arrei[0][1],arrei[0][2],arrei[0][3]},
                                              {arrei[1][0],arrei[1][1],arrei[1][2],arrei[1][3]},
                                              {arrei[2][0],arrei[2][1],arrei[2][2],arrei[2][3]},
                                              {arrei[3][0],arrei[3][1],arrei[3][2],arrei[3][3]}}
{

}
//constructor
Matrix4x4::Matrix4x4()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = 0;
        }
    }
}
//Matrise med konstant
Matrix4x4 Matrix4x4::operator * (float v)
{
    float arrB[4][4];
    for(int i= 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            arrB[j][i] = arr[j][i] * v;
        }
    }
    return Matrix4x4(arrB);
}

//Matrise * Vector4d
Vector4d Matrix4x4::operator * (const Vector4d& v) const
{
    Vector4d u;
    for(int i= 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            u.arr[i] += v.arr[j] * arr[i][j];
        }
    }
    return u;
}

//Matrise * Matrise
Matrix4x4 Matrix4x4::operator * (const Matrix4x4& v) const
{
    Matrix4x4 u;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j <4; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                u.arr[i][j] += arr[i][k] * v.arr[k][j];
            }
        }
    }
    return u;
}

void Matrix4x4::scale(float x, float y, float z)
{
    Vector3d scale(x,y,z);
    Matrix4x4 u;
    u.setToIdentity();
    u.operator*(scale);
    *this * u;
}

/*
Rotasjonsmatriser for x, y og z

Om X-aksen
|1    0        0    0|
|0  cos(v)  -sin(v) 0|
|0  sin(v)  cos(v)  0|
|0    0       0     1|

Om Y-aksen
|cos(v)  0  sin(v)  0|
|   0    1    0     0|
|-sin(v) 0  cos(v)  0|
|   0    0    0     1|

Om Z-aksen
|cos(v) -sin(v)  0   0|
|sin(v)  cos(v)  0   0|
|0         0     1   0|
|0         0     0   1|

*/
void Matrix4x4::rotate(float rotateAng, Vector3d rotate)
{
    Matrix4x4 u;

    u.setToIdentity();

    if(rotate.arr[0] == 1.0f && rotate.arr[1] == 0.0f && rotate.arr[2] == 0.0f)
    {
        u.arr[1][1] = cosf(rotateAng);
        u.arr[1][2] = -sinf(rotateAng);
        u.arr[2][1] = sinf(rotateAng);
        u.arr[2][2] = cosf(rotateAng);
    *this * u;

    }
    else if(rotate.arr[0] == 0.0f && rotate.arr[1] == 1.0f && rotate.arr[2] == 0.0f)
    {
        u.arr[0][0] = cosf(rotateAng);
        u.arr[0][2] = sinf(rotateAng);
        u.arr[2][0] = -sinf(rotateAng);
        u.arr[2][2] = cosf(rotateAng);
    *this * u;
    }
    else if(rotate.arr[0] == 0.0f && rotate.arr[1] == 0.0f && rotate.arr[2] == 1.0f)
    {
        u.arr[0][0] = cosf(rotateAng);
        u.arr[0][1] = -sinf(rotateAng);
        u.arr[1][0] = sinf(rotateAng);
        u.arr[1][1] = cosf(rotateAng);
    *this * u;
    }
    else {
        std::cout << "Wrong input \n";
    }
}

void Matrix4x4::translate(float tx, float ty, float tz)
{

}

//funksjon for å gjøre en matrise om til en identitetsmatrise
void Matrix4x4::setToIdentity()
{
    for(int i = 0; i<4; i++)
        arr[i][i] = 1.0f;
}
