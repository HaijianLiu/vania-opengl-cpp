
#include "Engine.hpp"

Resources::Resources() {

}
Resources::~Resources() {

}

void Resources::loadShader(const char* name, const char* vertexPath, const char* fragmentPath) {
	this->shaders.insert(std::make_pair(name, new Shader(vertexPath,fragmentPath)));
}
Shader* Resources::getShader(const char* name) {
	return this->shaders[name];
}
void Resources::loadTexture(const char* name, const char* path) {
	this->textures.insert(std::make_pair(name, new Texture(path)));
}
Texture* Resources::getTexture(const char* name) {
	return this->textures[name];
}
