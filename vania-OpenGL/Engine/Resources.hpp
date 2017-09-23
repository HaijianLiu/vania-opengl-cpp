
#ifndef Resources_hpp
#define Resources_hpp

class Resources {
private:
	// Resource storage
	std::map<const char*, Shader*> shaders;
	std::map<const char*, Texture*> textures;
	std::map<const char*, Audio*> audios;

public:
	// Quad
	Quad* quad;
	irrklang::ISoundEngine* iSoundEngine;

	Resources();
	~Resources();

	void start();

	// Loads (and generates) a shader program from file loading vertex, fragment
	void loadShader(const char* name, const char* vertexPath, const char* fragmentPath);
	// Retrieves a stored sader
	Shader* getShader(const char* name);
	// Loads (and generates) a texture from file
	void loadTexture(const char* name, const char* path);
	// Retrieves a stored texture
	Texture* getTexture(const char* name);
	// Create a Audio with path
	void loadAudio(const char* name, const char* path);
	// Retrieves a stored Audio
	Audio* getAudio(const char* name);
};

#endif /* Resources_hpp */
