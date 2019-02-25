#ifndef VECTOR3D_H
#define VECTOR3D_H


class Vector3d
{
public:
       Vector3d(float x=0.0f, float y=0.0f, float z=0.0);  	// Constructor
       Vector3d operator + (const Vector3d& v) const;       // Addition
       Vector3d operator - (const Vector3d& v) const;       // Subtraction
       float operator * (const Vector3d& v) const;         	// Dot product
       Vector3d operator ^ (const Vector3d& v) const;           // Cross product
       float length() const;                               	// return length
       void normalize();                                   	// Normalize to unit length
       Vector3d operator * (float c) const;                	// Scaling

       float arr[3];
};

#endif // VECTOR3D_H
