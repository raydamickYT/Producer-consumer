////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
template <typename V>
inline Vector3<V>::Vector3() :
x(0),
y(0),
z(0)
{

}


////////////////////////////////////////////////////////////
template <typename V>
inline Vector3<V>::Vector3(V X, V Y, V Z) :
x(X),
y(Y),
z(Z)
{

}


////////////////////////////////////////////////////////////
template <typename V>
template <typename U>
inline Vector3<V>::Vector3(const Vector3<U>& vector) :
x(static_cast<V>(vector.x)),
y(static_cast<V>(vector.y)),
z(static_cast<V>(vector.z))
{
}


////////////////////////////////////////////////////////////
template <typename V>
inline Vector3<V> operator -(const Vector3<V>& left)
{
    return Vector3<V>(-left.x, -left.y, -left.z);
}


////////////////////////////////////////////////////////////
template <typename V>
inline Vector3<V>& operator +=(Vector3<V>& left, const Vector3<V>& right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;

    return left;
}


////////////////////////////////////////////////////////////
template <typename V>
inline Vector3<V>& operator -=(Vector3<V>& left, const Vector3<V>& right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;

    return left;
}


////////////////////////////////////////////////////////////
template <typename V>
inline Vector3<V> operator +(const Vector3<V>& left, const Vector3<V>& right)
{
    return Vector3<V>(left.x + right.x, left.y + right.y, left.z + right.z);
}


////////////////////////////////////////////////////////////
template <typename V>
inline Vector3<V> operator -(const Vector3<V>& left, const Vector3<V>& right)
{
    return Vector3<V>(left.x - right.x, left.y - right.y, left.z - right.z);
}


////////////////////////////////////////////////////////////
template <typename V>
inline Vector3<V> operator *(const Vector3<V>& left, V right)
{
    return Vector3<V>(left.x * right, left.y * right, left.z * right);
}


////////////////////////////////////////////////////////////
template <typename V>
inline Vector3<V> operator *(V left, const Vector3<V>& right)
{
    return Vector3<V>(right.x * left, right.y * left, right.z * left);
}


////////////////////////////////////////////////////////////
template <typename V>
inline Vector3<V>& operator *=(Vector3<V>& left, V right)
{
    left.x *= right;
    left.y *= right;
    left.z *= right;

    return left;
}


////////////////////////////////////////////////////////////
template <typename V>
inline Vector3<V> operator /(const Vector3<V>& left, V right)
{
    return Vector3<V>(left.x / right, left.y / right, left.z / right);
}


////////////////////////////////////////////////////////////
template <typename V>
inline Vector3<V>& operator /=(Vector3<V>& left, V right)
{
    left.x /= right;
    left.y /= right;
    left.z /= right;

    return left;
}


////////////////////////////////////////////////////////////
template <typename V>
inline bool operator ==(const Vector3<V>& left, const Vector3<V>& right)
{
    return (left.x == right.x) && (left.y == right.y) && (left.z == right.z);
}


////////////////////////////////////////////////////////////
template <typename V>
inline bool operator !=(const Vector3<V>& left, const Vector3<V>& right)
{
    return (left.x != right.x) || (left.y != right.y) || (left.z != right.z);
}
