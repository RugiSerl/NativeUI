#include "shaders.hpp"
#include "raylib.h"

namespace backend {
    Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
        set(::LoadShader(vertexShaderPath.c_str(), fragmentShaderPath.c_str()));
    }

    Shader::~Shader() {
        ::UnloadShader(*this);
    }

    void Shader::BeginMode() const {
        ::BeginShaderMode(*this);
    }

    void Shader::EndMode() const {
        ::EndShaderMode();
    }

    void Shader::SetUniformValue(const std::string& uniformName, const void* value, int uniformType) {
        ::SetShaderValue(*this, GetUniformLocation(uniformName), value, uniformType);
    }

    int Shader::GetUniformLocation(const std::string& uniformName) {
        // Key not found in stored locations.
        if (uniformLocations.find(uniformName) == uniformLocations.end()) {
            uniformLocations[uniformName] = ::GetShaderLocation(*this, uniformName.c_str());
        }
        return uniformLocations[uniformName];
    }

    void Shader::set(const ::Shader& shader) {
        id = shader.id;
        locs = shader.locs;
    }
}
