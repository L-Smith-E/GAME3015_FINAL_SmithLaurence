#define NOMINMAX
#include "World.hpp"

World::World(Game* game)
	: mSceneGraph(new SceneNode(game))
	, mGame(game)
	, mPlayerAircraft(nullptr)
	, mBackground(nullptr)
	, mWorldBounds(-1.25f, 1.25f, 200.0f, 0.0f) //Left, Right, Down, Up
	, mSpawnPosition(0.f, 0.f)
	, mScrollSpeed(1.0f)
	//m_featureLevel(D3D_FEATURE_LEVEL_11_0),
{
}

CommandQueue& World::getCommandQueue()
{
	return mCommandQueue;
}

void World::adaptPlayerPosition()
{
	const float borderDistance = 100.f;
	XMFLOAT3 position = mPlayerAircraft->getWorldPosition();
	position.x = std::max(position.x, mWorldBounds.x);
	position.x = std::min(position.x, mWorldBounds.y);
	position.z = std::max(position.z, mWorldBounds.z);
	position.z = std::min(position.z, mWorldBounds.w);
	mPlayerAircraft->setPosition(position.x, position.y, position.z);
}

void World::adaptPlayerVelocity()
{
	XMFLOAT3 velocity = mPlayerAircraft->getVelocity();

	if (velocity.x != 0.f && velocity.z != 0.f)
		mPlayerAircraft->setVelocity(velocity.x / std::sqrt(2.f), velocity.y / std::sqrt(2.f), velocity.z / std::sqrt(2.f));
}



void World::update(const GameTimer& gt)
{
	while (!mCommandQueue.isEmpty())
		mSceneGraph->onCommand(mCommandQueue.pop(), gt);

	//adaptPlayerVelocity();
	mSceneGraph->update(gt);
	//adaptPlayerPosition();

	//AirCraft Bouncing
	/*if (mPlayerAircraft->getWorldPosition().x < mWorldBounds.x
		|| mPlayerAircraft->getWorldPosition().x > mWorldBounds.y)
	{
		mPlayerAircraft->setVelocity(XMFLOAT3(mPlayerAircraft->getVelocity().x * -1.0f, 0, 0));
	}*/
}

void World::draw()
{
	mSceneGraph->draw();
}

void World::buildScene()
{
	auto pos = XMVECTOR{ 6, 1, 20 };
	std::unique_ptr<Aircraft> player(new Aircraft(Aircraft::Type::Eagle, mGame));
	mPlayerAircraft = player.get();
	//mPlayerAircraft->setPosition(pos.m128_f32[0], pos.m128_f32[1], pos.m128_f32[2]);
	mPlayerAircraft->setPosition(pos.m128_f32[0], 10, pos.m128_f32[2]);
	mPlayerAircraft->setScale(1, 1, 1);
	mPlayerAircraft->setVelocity(mScrollSpeed, 0.0f, 0.0f);
	mSceneGraph->attachChild(std::move(player));

	std::unique_ptr<Aircraft> enemy1(new Aircraft(Aircraft::Type::Raptor, mGame));
	auto raptor = enemy1.get();
	raptor->setPosition(-2, 0, -1);
	raptor->setScale(1.0f, 1.0f, 1.0f);
	raptor->setWorldRotation(0.0f,  0, 0.0f);
	mPlayerAircraft->attachChild(std::move(enemy1));

	std::unique_ptr<Aircraft> enemy2(new Aircraft(Aircraft::Type::Raptor, mGame));
	auto raptor2 = enemy2.get();
	raptor2->setPosition(2, 0, -1);
	raptor2->setScale(1.0, 1.0, 1.0);
	raptor2->setWorldRotation(0, 0, 0);
	mPlayerAircraft->attachChild(std::move(enemy2));

	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(mGame));
	mBackground = backgroundSprite.get();
	//mBackground->setPosition(mWorldBounds.left, mWorldBounds.top);
	mBackground->setPosition(0, 0, 0.0);
	mBackground->setScale(200.0, 1.0, 200.0);
	mBackground->setVelocity(0,0, -mScrollSpeed);
	mSceneGraph->attachChild(std::move(backgroundSprite));

	mSceneGraph->build();
}
