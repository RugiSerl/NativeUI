#pragma once

#include "raylib.h"
namespace backend {
    class Vector2 : public ::Vector2 {
        public:
            Vector2(float x, float y);
            Vector2();
    };

    class Vector3 : public ::Vector3 {
        public:
            Vector3(float x, float y, float z);
            Vector3();

    };

    class Vector4 : public ::Vector4 {
        public:
            Vector4(float x, float y, float z, float w);
            Vector4();

    };
}
