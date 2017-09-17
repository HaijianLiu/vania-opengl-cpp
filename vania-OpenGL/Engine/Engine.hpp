
#ifndef Engine_hpp
#define Engine_hpp

/*------------------------------------------------------------------------------
< Macross >
------------------------------------------------------------------------------*/
#define PIXEL_SCALE (3.0f)
#define PIXEL_TO_UNIT (0.01f)
#define UNIT_TO_PIXEL (100)
#define SCREEN_WIDTH (25 * 16 * PIXEL_SCALE)
#define SCREEN_HEIGHT (15 * 16 * PIXEL_SCALE)
#define PI (3.141593f)


/*------------------------------------------------------------------------------
< Libraries >
------------------------------------------------------------------------------*/
// Include standard libraries
#include <iostream>
#include <thread>
#include <random>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

// Include GLEW (include before gl.h and glfw.h)
#include <GL/glew.h>
// Include GLFW
#include <GLFW/glfw3.h>
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Include stbi Library
#include "stb_image.h"


/*------------------------------------------------------------------------------
< Core >
------------------------------------------------------------------------------*/
class GameObject;


/*------------------------------------------------------------------------------
< Engine >
------------------------------------------------------------------------------*/
#include "Window.hpp"
#include "Input.hpp"
#include "Shader.hpp"
#include "Timer.hpp"
#include "Quad.hpp"
#include "Texture.hpp"
#include "Resources.hpp"
#include "RenderPass.hpp"
#include "Sprite.hpp"
#include "Animation.hpp"
#include "Transform.hpp"
#include "Camera.hpp"
#include "BoxCollider.hpp"
#include "Status.hpp"
#include "GameObject.hpp"


/*------------------------------------------------------------------------------
< GameObject >
------------------------------------------------------------------------------*/
#include "TileObject.hpp"
#include "ColliderObject.hpp"
#include "Player.hpp"


/*------------------------------------------------------------------------------
< Scene >
------------------------------------------------------------------------------*/
#include "Scene.hpp"


/*------------------------------------------------------------------------------
< Global Functions >
------------------------------------------------------------------------------*/
// main.cpp
Window* getWindow();
Timer* getTimer();
Camera* getCamera();
Resources* getResources();
std::vector<GameObject*>* getGameObjects();
std::vector<BoxCollider*>* getColliders();
std::vector<GameObject*> copyGameObjects();
std::vector<BoxCollider*> copyColliders();

// Engine.cpp
template <typename T> void deleteMap(T map) {
	for (typename T::iterator it = map.begin(); it != map.end(); it++) {
		delete it->second;
	}
	map.clear();
}

template <typename T> void deleteVector(T vector) {
	for (unsigned int i = 0; i < vector.size(); i++) {
		delete vector[i];
	}
	vector.shrink_to_fit();
}

template <typename T> void deleteVectorMap(T map) {
	for (typename T::iterator it = map.begin(); it != map.end(); it++) {
		deleteVector(it->second);
	}
	map.clear();
}

#endif /* Engine_hpp */
