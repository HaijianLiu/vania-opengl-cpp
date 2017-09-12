
#ifndef Engine_hpp
#define Engine_hpp

/*------------------------------------------------------------------------------
< Macross >
------------------------------------------------------------------------------*/
#define PIXEL_SCALE (2.0f)
#define PIXEL_TO_UNIT (0.01f)
#define UNIT_TO_PIXEL (100)
#define SCREEN_WIDTH (25 * 16 * PIXEL_SCALE)
#define SCREEN_HEIGHT (15 * 16 * PIXEL_SCALE)
#define SCREEN_WIDTH_CENTER (SCREEN_WIDTH / 2)
#define SCREEN_HEIGHT_CENTER (SCREEN_HEIGHT / 2)
#define PI (3.141593f)

/*------------------------------------------------------------------------------
< Libraries >
------------------------------------------------------------------------------*/
// Include standard libraries
#include <iostream>
#include <random>
#include <vector>
#include <string>
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
< Engine >
------------------------------------------------------------------------------*/
#include "Window.hpp"
#include "Shader.hpp"
#include "Quad.hpp"
#include "Texture.hpp"
#include "Sprite.hpp"
#include "Transform.hpp"
#include "Camera.hpp"

/*------------------------------------------------------------------------------
< GameObject >
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
< Scene >
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
< Global Functions >
------------------------------------------------------------------------------*/
// main.cpp
GLFWwindow* getWindow();
Camera* getCamera();
Shader* getShader();

#endif /* Engine_hpp */
