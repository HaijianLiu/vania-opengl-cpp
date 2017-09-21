
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Resources::Resources() {
	this->quad = new Quad();
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Resources::~Resources() {
	delete this->quad;
	deleteMap(this->textures);
	deleteMap(this->shaders);
}


/*------------------------------------------------------------------------------
< start > before GameObject defaultStart()
------------------------------------------------------------------------------*/
void Resources::start() {
	// Shader
	Resources::loadShader("Sprite", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/Sprite.vs.glsl",  "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/Sprite.fs.glsl");
	Resources::loadShader("RenderPass", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/RenderPass.vs.glsl",  "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/RenderPass.fs.glsl");

	// Texture
	Resources::loadTexture("default", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/default_16x16.png");
	// tilesets & map & item
	Resources::loadTexture("tilesets", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/tilesets.png");
	Resources::loadTexture("map_block", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/map_block.png");
	Resources::loadTexture("item_orb", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/item_orb.png");
	Resources::loadTexture("background_2nd", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/background_2nd.png");
	Resources::loadTexture("background_4th", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/background_4th.png");
	// player
	Resources::loadTexture("player_idle", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/player_idle.png");
	Resources::loadTexture("player_shoot", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/player_shoot.png");
	Resources::loadTexture("player_run_shoot", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/player_run_shoot.png");
	Resources::loadTexture("player_jump", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/player_jump.png");
	Resources::loadTexture("player_duck", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/player_duck.png");
	Resources::loadTexture("player_duck_shoot", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/player_duck_shoot.png");
	Resources::loadTexture("player_hurt", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/player_hurt.png");
	Resources::loadTexture("player_bullet", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/player_bullet.png");
	// enemy
	Resources::loadTexture("enemy_crab_walk", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/enemy_crab_walk.png");
	Resources::loadTexture("enemy_jumper_jump", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/enemy_jumper_jump.png");
	// destroy
	Resources::loadTexture("player_destroy", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/player_destroy.png");
	Resources::loadTexture("enemy_destroy", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/enemy_destroy.png");
	// UI
	Resources::loadTexture("ui_player_energy", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/ui_player_energy.png");
}


/*------------------------------------------------------------------------------
< Load & Get >
------------------------------------------------------------------------------*/
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
