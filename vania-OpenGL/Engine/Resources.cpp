
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Resources::Resources() {
	this->quad = new Quad();
	// start the sound engine with default parameters
	this->iSoundEngine = irrklang::createIrrKlangDevice();
	if (!this->iSoundEngine) printf("Could not startup engine\n");
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Resources::~Resources() {
	delete this->quad;
	deleteMap(this->textures);
	deleteMap(this->shaders);
	this->iSoundEngine->drop(); // delete engine
}


/*------------------------------------------------------------------------------
< start > before GameObject defaultStart()
------------------------------------------------------------------------------*/
void Resources::start() {

	/* Shader
	..............................................................................*/
	Resources::loadShader("Sprite", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/Sprite.vs.glsl",  "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/Sprite.fs.glsl");
	Resources::loadShader("SpriteFlash", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/Sprite.vs.glsl",  "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/SpriteFlash.fs.glsl");
	Resources::loadShader("RenderPass", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/RenderPass.vs.glsl",  "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Shader/RenderPass.fs.glsl");

	/* Texture
	..............................................................................*/
	Resources::loadTexture("default", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/default_16x16.png");
	// tilesets & map & item
	Resources::loadTexture("tilesets", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/tilesets.png");
	Resources::loadTexture("map_block", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/map_block.png");
	Resources::loadTexture("item_orb", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/item_orb.png");
	Resources::loadTexture("background_2nd", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/background_2nd.png");
	Resources::loadTexture("background_4th", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/background_4th.png");
	Resources::loadTexture("map_check_point", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/map_check_point.png");
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
	Resources::loadTexture("ui_numbers", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/ui_numbers.png");
	Resources::loadTexture("ui_game_over_text", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/ui_game_over_text.png");
	Resources::loadTexture("title_title", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/title_title.png");
	Resources::loadTexture("title_text", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/title_text.png");
	Resources::loadTexture("title_star", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/title_star.png");
	Resources::loadTexture("title_enter", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/title_enter.png");
	Resources::loadTexture("title_option", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/title_option.png");
	Resources::loadTexture("title_credits", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Texture/title_credits.png");

	/* Audio
	..............................................................................*/
	Resources::loadAudio("title_enter", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Audio/SE/title_enter.wav");
	Resources::loadAudio("title_select", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Audio/SE/title_select.wav");
	Resources::loadAudio("title_curser", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Assets/Audio/SE/title_curser.wav");

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
void Resources::loadAudio(const char* name, const char* path) {
	this->audios.insert(std::make_pair(name, new Audio(path)));
}
Audio* Resources::getAudio(const char* name) {
	return this->audios[name];
}
