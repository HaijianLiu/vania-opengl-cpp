
#include "Engine.hpp"

GameObject::GameObject() {
	// GetGameObjects and push_back
	this->gameObjects = getGameObjects();
	this->gameObjects->push_back(this);
	// function class
	this->transform = new Transform();
	this->sprite = new Sprite();
}
GameObject::~GameObject() {
	delete this->transform;
	delete this->sprite;
}

void GameObject::preStart() {
	this->timer = getTimer();
	this->resources = getResources();
	this->birthTime = this->timer->currentTime;
}

void GameObject::updateTransform() {
	// this->transform->Update(this->sprite->vertex);
}

void GameObject::draw() {
	// this->sprite->Draw();
}

void GameObject::reset() {

}
