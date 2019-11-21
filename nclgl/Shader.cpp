#include "Shader.h"



Shader::Shader(string vFile, string fFile, string gFile)
{
	program = glCreateProgram();
	objects[SHADER_VERTEX] = GenerateShader(vFile, GL_VERTEX_SHADER);
	objects[SHADER_FRAGMENT] = GenerateShader(fFile, GL_FRAGMENT_SHADER);
	objects[SHADER_GEOMETRY] = 0;

	// if have geometry shader
	if (!gFile.empty()) {
		objects[SHADER_GEOMETRY] = GenerateShader(gFile, GL_GEOMETRY_SHADER);
		glAttachShader(program, objects[SHADER_GEOMETRY]);
	}
	glAttachShader(program, objects[SHADER_VERTEX]);
	glAttachShader(program, objects[SHADER_FRAGMENT]);
	SetDefaultAttributes();
}

/* Free up memory, and objects's & program's name can be reused */
Shader::~Shader()
{
	// delete shader objects
	for (int i = 0; i < 3; i++) {
		glDetachShader(program, objects[i]);
		glDeleteShader(objects[i]);
	}
	// delete program
	glDeleteProgram(program);
}

GLuint Shader::GenerateShader(string from, GLenum type)
{
	
	return GLuint();
}
