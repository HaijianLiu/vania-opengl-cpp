
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
	Resources::loadShader("Sprite", "./Shader/Sprite.vs.glsl",  "./Shader/Sprite.fs.glsl");
	Resources::loadShader("SpriteFlash", "./Shader/Sprite.vs.glsl",  "./Shader/SpriteFlash.fs.glsl");
	Resources::loadShader("RenderPass", "./Shader/RenderPass.vs.glsl",  "./Shader/RenderPass.fs.glsl");

	/* Texture
	..............................................................................*/
	Resources::loadTexture("default", "./Assets/Texture/default_16x16.png");
	// tilesets & map & item
	Resources::loadTexture("tilesets", "./Assets/Texture/tilesets.png");
	Resources::loadTexture("map_block", "./Assets/Texture/map_block.png");
	Resources::loadTexture("item_orb", "./Assets/Texture/item_orb.png");
	Resources::loadTexture("item_icon", "./Assets/Texture/item_icon.png");
	Resources::loadTexture("item_info_bronze", "./Assets/Texture/item_info_bronze.png");
	Resources::loadTexture("item_info_dark", "./Assets/Texture/item_info_dark.png");
	Resources::loadTexture("item_info_gold", "./Assets/Texture/item_info_gold.png");
	Resources::loadTexture("item_info_sliver", "./Assets/Texture/item_info_sliver.png");
	Resources::loadTexture("map_check_point", "./Assets/Texture/map_check_point.png");
	Resources::loadTexture("background_forest_0", "./Assets/Texture/background_forest_0.png");
	Resources::loadTexture("background_forest_2nd", "./Assets/Texture/background_forest_2nd.png");
	Resources::loadTexture("background_tissue_2nd", "./Assets/Texture/background_tissue_2nd.png");
	Resources::loadTexture("background_ship_2nd", "./Assets/Texture/background_ship_2nd.png");
	// player
	Resources::loadTexture("player_idle", "./Assets/Texture/player_idle.png");
	Resources::loadTexture("player_shoot", "./Assets/Texture/player_shoot.png");
	Resources::loadTexture("player_run_shoot", "./Assets/Texture/player_run_shoot.png");
	Resources::loadTexture("player_jump", "./Assets/Texture/player_jump.png");
	Resources::loadTexture("player_duck", "./Assets/Texture/player_duck.png");
	Resources::loadTexture("player_duck_shoot", "./Assets/Texture/player_duck_shoot.png");
	Resources::loadTexture("player_hurt", "./Assets/Texture/player_hurt.png");
	Resources::loadTexture("player_bullet", "./Assets/Texture/player_bullet.png");
	// enemy
	Resources::loadTexture("enemy_crab_walk", "./Assets/Texture/enemy_crab_walk.png");
	Resources::loadTexture("enemy_flyer", "./Assets/Texture/enemy_flyer.png");
	Resources::loadTexture("enemy_jumper_jump", "./Assets/Texture/enemy_jumper_jump.png");
	Resources::loadTexture("enemy_jumper_idle", "./Assets/Texture/enemy_jumper_idle.png");
	Resources::loadTexture("enemy_ghost", "./Assets/Texture/enemy_ghost.png");
	Resources::loadTexture("enemy_ball", "./Assets/Texture/enemy_ball.png");
	// boss
	Resources::loadTexture("boss_body", "./Assets/Texture/boss_body.png");
	Resources::loadTexture("boss_bullet", "./Assets/Texture/boss_bullet.png");
	Resources::loadTexture("boss_death_bite_appear", "./Assets/Texture/boss_death_bite_appear.png");
	Resources::loadTexture("boss_death_bite_bite", "./Assets/Texture/boss_death_bite_bite.png");
	Resources::loadTexture("boss_death_bite_disappear", "./Assets/Texture/boss_death_bite_disappear.png");
	Resources::loadTexture("boss_death_wall", "./Assets/Texture/boss_death_wall.png");
	Resources::loadTexture("boss_eye", "./Assets/Texture/boss_eye.png");
	// destroy
	Resources::loadTexture("player_destroy", "./Assets/Texture/player_destroy.png");
	Resources::loadTexture("enemy_destroy", "./Assets/Texture/enemy_destroy.png");
	// UI
	Resources::loadTexture("ui_player_energy", "./Assets/Texture/ui_player_energy.png");
	Resources::loadTexture("ui_boss_energy", "./Assets/Texture/ui_boss_energy.png");
	Resources::loadTexture("ui_numbers", "./Assets/Texture/ui_numbers.png");
	Resources::loadTexture("ui_game_over_text", "./Assets/Texture/ui_game_over_text.png");
	Resources::loadTexture("title_title", "./Assets/Texture/title_title.png");
	Resources::loadTexture("title_text", "./Assets/Texture/title_text.png");
	Resources::loadTexture("title_star", "./Assets/Texture/title_star.png");
	Resources::loadTexture("title_enter", "./Assets/Texture/title_enter.png");
	Resources::loadTexture("title_option", "./Assets/Texture/title_option.png");
	Resources::loadTexture("title_credits", "./Assets/Texture/title_credits.png");

	/* Audio
	..............................................................................*/
	// title
	Resources::loadAudio("title_enter", "./Assets/Audio/SE/title_enter.wav");
	Resources::loadAudio("title_select", "./Assets/Audio/SE/title_select.wav");
	Resources::loadAudio("title_curser", "./Assets/Audio/SE/title_curser.wav");
	// player
	Resources::loadAudio("player_dead", "./Assets/Audio/SE/player_dead.wav");
	Resources::loadAudio("player_destroy", "./Assets/Audio/SE/player_destroy.wav");
	Resources::loadAudio("player_hurt", "./Assets/Audio/SE/player_hurt.wav");
	Resources::loadAudio("player_no_ammo", "./Assets/Audio/SE/player_no_ammo.wav");
	Resources::loadAudio("player_shoot", "./Assets/Audio/SE/player_shoot.wav");
	Resources::loadAudio("player_landing", "./Assets/Audio/SE/player_landing.wav");
	// enemy
	Resources::loadAudio("enemy_ball_bounce", "./Assets/Audio/SE/enemy_ball_bounce.wav");
	Resources::loadAudio("enemy_destroy", "./Assets/Audio/SE/enemy_destroy.wav");
	Resources::loadAudio("enemy_hurt", "./Assets/Audio/SE/enemy_hurt.wav");
	// boss
	Resources::loadAudio("boss_intro", "./Assets/Audio/BGM/boss_intro.wav");
	Resources::loadAudio("boss_main", "./Assets/Audio/BGM/boss_main.wav");
	Resources::loadAudio("boss_destroy", "./Assets/Audio/SE/boss_destroy.wav");
	Resources::loadAudio("boss_win", "./Assets/Audio/SE/boss_win.wav");
	// item
	Resources::loadAudio("item_orb", "./Assets/Audio/SE/item_orb.wav");
	Resources::loadAudio("item_player_orb", "./Assets/Audio/SE/item_player_orb.wav");
	// map
	Resources::loadAudio("map_check_point", "./Assets/Audio/SE/map_check_point.wav");
	// BGM
	Resources::loadAudio("map_silence", "./Assets/Audio/BGM/map_silence.wav");
	Resources::loadAudio("map_basic", "./Assets/Audio/BGM/map_basic.wav");
	Resources::loadAudio("map_normal", "./Assets/Audio/BGM/map_normal.wav");
	Resources::loadAudio("map_mars", "./Assets/Audio/BGM/map_mars.wav");
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
