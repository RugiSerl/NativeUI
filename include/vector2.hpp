#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__


namespace math {
    class Vector2 {
    public:
        float x, y;
        Vector2(float x, float y) : x(x), y(y) {};
        Vector2(float xy) : x(xy), y(xy) {};
        Vector2() : x(0), y(0) {};

        Vector2 operator+(Vector2 v2) const {
            return Vector2(x + v2.x, y + v2.y);
        }

        Vector2 operator*(float scalar) const {
            return Vector2(scalar * x, scalar * y);
        };
        Vector2 ToRaylibVector2() const {
            return Vector2(x, y);
        }    
    };
}

#endif //__VECTOR_HPP__
