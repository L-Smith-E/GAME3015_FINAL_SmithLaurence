#pragma once
#include "SceneNode.hpp"
#include "Aircraft.hpp"
#include "SpriteNode.h"
#include "../../Common/d3dApp.h"
#include "../../Common/MathHelper.h"
#include "../../Common/UploadBuffer.h"
#include "../../Common/GeometryGenerator.h"
#include "CommandQueue.hpp"
#include "Command.hpp"
#include "../../Common/Camera.h"
#include "FrameResource.h"
#include <ctime>
#include <vector>




class World
{
public:
	explicit							World(Game* game);
	void								update(const GameTimer& gt);
	void								draw();

	//void								loadTextures();
	void								buildScene();

	CommandQueue& getCommandQueue();
private:
	enum class Layer
	{
		Background,
		Air
	};

	CommandQueue						mCommandQueue;
	void								adaptPlayerPosition();
	void								adaptPlayerVelocity();
private:
	Game* mGame;

	SceneNode* mSceneGraph;
	std::array<SceneNode*, 2>	mSceneLayers;

	XMFLOAT4							mWorldBounds;
	XMFLOAT2		    				mSpawnPosition;
	float								mScrollSpeed;
	Aircraft* mPlayerAircraft;
	Aircraft* plane1;
	Aircraft* plane2;
	SpriteNode* mBackground;
	Aircraft* mEnemy;
};
