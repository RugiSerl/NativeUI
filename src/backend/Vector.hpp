#pragma once

#include "raylib.h"
namespace backend {
    class Vector2 : public ::Vector2 {
        public:
            Vector2(float x, float y);
            Vector2();
            Vector2 operator=(Vector2 other); // Copy vector data
    };

    class Vector3 : public ::Vector3 {
        public:
            Vector3(float x, float y, float z);
            Vector3();
            Vector3 operator=(Vector3 other); // Copy vector data

    };

    class Vector4 : public ::Vector4 {
        public:
            Vector4(float x, float y, float z, float w);
            Vector4();
            Vector4 operator=(Vector4 other); // Copy vector data

    };
}
