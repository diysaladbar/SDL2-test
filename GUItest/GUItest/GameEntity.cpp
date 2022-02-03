#include "GameEntity.h"

GameEntity::GameEntity() {
	xPos = 0;
	yPos = 0;
	mRotation = 0.0;
	mActive = true;
	mParent = NULL;
	xScale = 1;
	yScale = 1;
}

GameEntity::GameEntity(float x, float y) {

	xPos = x;
	yPos = y;
	mRotation = 0.0;
	mActive = true;
	mParent = NULL;
	xScale = 1;
	yScale = 1;
}

GameEntity::~GameEntity() {

	mParent = NULL;
}

void GameEntity::setPos(float x, float y) {

	xPos = x;
	yPos = y;
}


	//The object's local position is rotated by the parent's rotation
	//Vector2 rotPos = RotateVector(Vector2(mPos.x * parentScale.x, mPos.y * parentScale.y), mParent->Rotation(local));
	//The final position also depends on the parent's scale (if the parent is scaled up, the object should be further away from the parent)
	//return mParent->Pos(world) + rotPos;
float GameEntity::getxPos(SPACE space) {
	if (space == local || mParent == NULL)
		return xPos;

	float parentxScale = mParent->getxScale(world);
}

float GameEntity::getyPos(SPACE space) {
	if (space == local || mParent == NULL)
		return yPos;

	float parentxScale = mParent->getyScale(world);
}


void GameEntity::Rotation(float r) {
	mRotation = r;
}

float GameEntity::getRotation(SPACE space) {

	if(space == local || mParent == NULL)
		return mRotation;

	return mParent->getRotation(world) + mRotation;
}

void GameEntity::setScale(float x, float y) {

	xScale = x;
	yScale = y;

}


float GameEntity::getxScale(SPACE space) {
	if (space == local || mParent == NULL)
		return xScale;

	float s = mParent->getxScale(world);
	s *= xScale;
	return s;
}

float GameEntity::getyScale(SPACE space) {
	if (space == local || mParent == NULL)
		return yScale;

	float s = mParent->getyScale(world);
	s *= yScale;
	return s;
}


void GameEntity::setActive(bool active) {

	mActive = active;
}

bool GameEntity::getActive() {

	return mActive;
}

void GameEntity::setParent(GameEntity* parent) {

	//If the parent is removed, The Position/Rotation/Scale are the GameEntity's world values, to keep the object looking the same after the removal of the parent;
	if(parent == NULL) {

		xPos = getxPos(world);
		yPos = getyPos(world);
		xScale = getxScale(world);
		yScale = getyScale(world);
		mRotation = getRotation(world);

	} else {

		//If the object already has a parent, remove the current parent to get it ready to be the child for the new parent
		if(mParent != NULL)
			parent = NULL;

		float parentxScale = parent->getxScale(world);
		float parentyScale = parent->getyScale(world);

		//Setting the local position to be relative to the new parent (while maintaining the same world position as before)
		xPos = getxPos(world) - parent->getxPos(world);
		yPos = getyPos(world) - parent->getyPos(world);
		mRotation = parent->getRotation(world);
		xPos /= parent->getxScale(world);
		yPos /= parent->getyScale(world);

		//Setting the local rotation to be relative to the new parent (while maintaining the same world rotation as before)
		mRotation = mRotation - parent->getRotation(world);

		//Setting the new scale to be relative to the new parent (while maintaining the same world scale as before)
		xScale = xScale / parent->getxScale(world);
		yScale = yScale / parent->getyScale(world);
	}

	mParent = parent;
}

GameEntity* GameEntity::setParent() {

	return mParent;
}

void GameEntity::Translate(float x, float y) {

	xPos += x;
	yPos += y;
}

void GameEntity::Rotate(float amount) {

	mRotation += amount;
}

void GameEntity::Update() {


}

void GameEntity::Render() {


}
