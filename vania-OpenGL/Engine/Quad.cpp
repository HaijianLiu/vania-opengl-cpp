
#include "Engine.hpp"

Quad::Quad() {
	// setup plane VAO
	unsigned int vbo;
	float vertices[] = {
		// vertex              // texCoord    // color (R,G,B,A)
		-1.0f,  1.0f, 0.0f,    0.0f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,  // left top
		-1.0f, -1.0f, 0.0f,    0.0f, 1.0f,    1.0f, 1.0f, 1.0f, 1.0f,  // left bottom
		 1.0f,  1.0f, 0.0f,    1.0f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,  // right top
		 1.0f, -1.0f, 0.0f,    1.0f, 1.0f,    1.0f, 1.0f, 1.0f, 1.0f,  // right bottom
	};
	glGenVertexArrays(1, &this->vao);
	glGenBuffers(1, &vbo);
	glBindVertexArray(vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
}

Quad::~Quad() {

}

void Quad::draw() {

}
