
#define STB_IMAGE_IMPLEMENTATION

#include "Engine.hpp"

void instantiate(GameObject* gameObject, Transform* transform) {
	gameObject->transform->position.x = transform->position.x;
	gameObject->transform->position.y = transform->position.y;
	gameObject->active = true;
	// gameObject->Reset();
}

float randomRange(float min, float max) {
	// return min + (float)(rand()%1000)/999.0f * (max - min);
  return min;
}

void destroy(GameObject* gameObject, float timer) {
	if ((float)gameObject->timer->currentTime - (float)gameObject->status->birthTime > timer) {
		gameObject->active = false;
	}
}

float distancePow(glm::vec3 a, glm::vec3 b) {
	return pow(a.x - b.x, 2.0f) + pow(a.y - b.y, 2.0f) + pow(a.z - b.z, 2.0f);
}
