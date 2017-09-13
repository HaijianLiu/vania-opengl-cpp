
#include "Engine.hpp"

Resources::Resources() {

}
Resources::~Resources() {

}

void Resources::loadShader(const char* vertexPath, const char* fragmentPath, const char* name) {
	this->shaders.insert(std::make_pair(name, new Shader(vertexPath,vertexPath)));
}
Shader* Resources::getShader(const char* name) {
	return this->shaders[name];
}
void Resources::loadTexture(const char* path, const char* name) {
	this->textures.insert(std::make_pair(name, new Texture(path)));
}
Texture* Resources::getTexture(const char* name) {
	return this->textures[name];
}
