
#version 330 core
layout (location = 0) out vec4 colorPass;

in vec2 texCoord;

uniform sampler2D texColor;

void main() {
	colorPass = texture(texColor, texCoord);
}
