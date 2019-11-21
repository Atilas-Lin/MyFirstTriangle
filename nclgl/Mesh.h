#pragma once
#include "OGLRenderer.h"

/* enum are named intergers, incrementing from a starting valu 0 */
/* so if we add extra attributes(ex. texture) BEFORE MAX_BUFFER , it will always equal to array size! */
enum MeshBuffer {
	VERTEX_BUFFER, COLOUR_BUFFER, MAX_BUFFER
};

class Mesh
{
public:
	Mesh();
	~Mesh();

	// return a pointer to a Mesh, containing VAO and VBO data for a coloured triangle. 
	static Mesh* GenerateTriangle(); 
	// draw the mesh
	virtual void Draw();

protected:
	// copy the mesh vertex data into graphics memory (copy into VBOs)
	void BufferData();

	GLuint arrayObject; // object names
	GLuint bufferObject[MAX_BUFFER]; // store object names
	GLuint numVertices; // hold how many vertices the mesh has
	GLuint type; // what is the mesh's draw type

	Vector3* vertices;
	Vector4* colours;

};

