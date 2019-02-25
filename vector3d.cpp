#include "vector3d.h"
#include "math.h"

Vector3d::Vector3d(float x,float y,float z) : arr{x,y,z}
{   }

Vector3d Vector3d::operator + (const Vector3d& v) const
{
    return Vector3d(v.arr[0] + arr[0], v.arr[1] + arr[1], v.arr[2] + arr[2]);
}

Vector3d Vector3d::operator - (const Vector3d& v) const
{
    return Vector3d(v.arr[0] - arr[0], v.arr[1] - arr[1], v.arr[2] - arr[2]);
}

float Vector3d::operator * (const Vector3d& v) const
{
    return ((v.arr[0] * arr[0]) + (v.arr[1] * arr[1]) + (v.arr[2] * arr[2]));
}

Vector3d Vector3d::operator ^ (const Vector3d& v) const
{
    //a2b3-a3b2, a3b1-a1b3, a1b2-a2b1
    return Vector3d((v.arr[1]*arr[2])-(v.arr[2]*arr[1]),
                    -(v.arr[2]*arr[0])-(v.arr[0]*arr[2]),
                    (v.arr[0]*arr[1])-(v.arr[1])*arr[0]);
}

float Vector3d::length() const
{
    //square root of x^2+y^2+z^2
    return sqrt(arr[0]*arr[0]+arr[1]*arr[1]+arr[2]*arr[2]);
}

void Vector3d::normalize()
{
    arr[0] = arr[0]/length();
    arr[1] = arr[1]/length();
    arr[2] = arr[2]/length();
}

Vector3d Vector3d::operator * (float c) const
{
    return Vector3d(arr[0]*c, arr[1]*c, arr[2]*c);
}

