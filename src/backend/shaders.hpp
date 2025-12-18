#pragma once

#include "raylib.h"
#include <string>
#include <unordered_map>
namespace backend {
    class Shader : public ::Shader {
    public:
        Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
        ~Shader();

        void BeginMode() const;
        void EndMode() const;

        void SetUniformValue(const std::string& uniformName, const void* value, int uniformType);

    protected:
        void set(const ::Shader& shader);

        int GetUniformLocation(const std::string& uniformName);

    private:
        std::unordered_map<std::string, int> uniformLocations;
    };
}
