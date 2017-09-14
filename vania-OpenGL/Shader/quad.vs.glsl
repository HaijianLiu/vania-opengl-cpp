
#version 330 core
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec2 aTexCoord;

out vec2 texCoord;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;
uniform mat3 slice;

void main() {
	gl_Position = projection * view * model * vec4(aPosition, 1.0);
	texCoord = (slice * vec3(aTexCoord, 1.0)).xy;
}
