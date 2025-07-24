#ifndef __UTILS_H__
#define __UTILS_H__
#include <vector>
#include "raylib-cpp.hpp"

template<class T> std::vector<T> rotateVector(std::vector<T> vector, int offset);
raylib::Rectangle getInnerRect(raylib::Rectangle, float);

#endif // !__UTILS_H__