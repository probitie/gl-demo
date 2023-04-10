
/*
 * This code is copied from LearnOpenGL Tutorial
 *
 */

#pragma once

#include "libs.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "error.h"

class shader_program_t
{
public:
    unsigned int ID;
    // constructor generates the shader on the fly
    // ------------------------------------------------------------------------
    shader_program_t(const char* vertexPath, const char* fragmentPath)
    {
        // 1. retrieve the vertex_t/fragment source code from filePath
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;
        // ensure ifstream objects can throw exceptions:
        vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            // open files
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);
            std::stringstream vShaderStream, fShaderStream;
            // read file's buffer contents into streams
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();
            // close file handlers
            vShaderFile.close();
            fShaderFile.close();
            // convert stream into string
            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();
        }
        catch (std::ifstream::failure& e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
        }
        const char* vShaderCode = vertexCode.c_str();
        const char* fShaderCode = fragmentCode.c_str();
        // 2. compile shaders
        unsigned int vertex, fragment;
        // vertex_t shader
        DBG(vertex = glCreateShader(GL_VERTEX_SHADER););
        DBG(glShaderSource(vertex, 1, &vShaderCode, NULL));
        DBG(glCompileShader(vertex));
        checkCompileErrors(vertex, "VERTEX");
        // fragment Shader
        DBG(fragment = glCreateShader(GL_FRAGMENT_SHADER));
        DBG(glShaderSource(fragment, 1, &fShaderCode, NULL));
        DBG(glCompileShader(fragment));
        checkCompileErrors(fragment, "FRAGMENT");
        // shader Program
        DBG(ID = glCreateProgram());
        DBG(glAttachShader(ID, vertex));
        DBG(glAttachShader(ID, fragment));
        DBG(glLinkProgram(ID));
        checkCompileErrors(ID, "PROGRAM");
        // delete the shaders as they're linked into our program now and no longer necessary
        DBG(glDeleteShader(vertex));
        DBG(glDeleteShader(fragment));
    }
    // activate the shader
    // ------------------------------------------------------------------------
    void use() const 
    {
        DBG(glUseProgram(ID));
    }

    // TODO enable()
    void activate() const
    {
        use(); 
    }

    void deactivate() const
    {
        DBG(glUseProgram(0));
    }

    // utility uniform functions
    // ------------------------------------------------------------------------
    void setBool(const std::string& name, bool value) const
    {
        DBG(glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value));
    }
    // ------------------------------------------------------------------------
    void setInt(const std::string& name, int value) const
    {
        DBG(glUniform1i(glGetUniformLocation(ID, name.c_str()), value));
    }
    // ------------------------------------------------------------------------
    void setFloat(const std::string& name, float value) const
    {
        DBG(glUniform1f(glGetUniformLocation(ID, name.c_str()), value));
    }

private:
    // utility function for checking shader compilation/linking errors.
    // ------------------------------------------------------------------------
    void checkCompileErrors(unsigned int shader, std::string type)
    {
        int success;
        char infoLog[1024];
        if (type != "PROGRAM")
        {
            DBG(glGetShaderiv(shader, GL_COMPILE_STATUS, &success));
            if (!success)
            {
                DBG(glGetShaderInfoLog(shader, 1024, NULL, infoLog));
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
        else
        {
            DBG(glGetProgramiv(shader, GL_LINK_STATUS, &success));
            if (!success)
            {
                DBG(glGetProgramInfoLog(shader, 1024, NULL, infoLog));
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
    }
};

