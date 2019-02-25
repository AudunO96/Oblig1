#include "matrix4x4.h"

Matrix4x4::Matrix4x4()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; i < 4; i++)
        {
            arr[i][j] = 0;
        }
    }
}

Matrix4x4 Matrix4x4::operator * (const Matrix4x4& v) const
{
    return (v.arr[0][0]*arr[0][0]
                );
}
