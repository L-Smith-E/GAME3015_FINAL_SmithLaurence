#include "GameState.hpp"
#include "Game.hpp"

GameState::GameState(StateStack* stack, Context* context)
	:State(stack, context)
	, mWorld(mContext->mGame)

{
	LoadScene();
}

void GameState::draw()
{
	mWorld.draw();
}

void GameState::ProcessInput()
{
	CommandQueue& commands = mWorld.getCommandQueue();
	(getContext()->player)->handleEvent(commands);
	(getContext()->player)->handleRealtimeInput(commands);
}

bool GameState::update(const GameTimer& gt)
{
	ProcessInput();
	mWorld.update(gt);
	
	//mPlayer.handleRealtimeInput(commands);
	return true;
}

bool GameState::handleEvent(WPARAM btnState)
{
	//CommandQueue& commands = mWorld->getCommandQueue();
	//mPlayer.handleEvent(commands);

	if (btnState == 'P')
	{
		requestStackPush(States::Pause);
	}
	return true;
}

 bool GameState::handleRealTimeInput()
 {
	 return true;
 }

void GameState::LoadScene()
{
	//Clear items, and resources.
	mContext->mGame->mAllRitems.clear();
	mContext->mGame->mOpaqueRitems.clear();
	mContext->mGame->mFrameResources.clear();
	// Build our materials
	mContext->mGame->BuildMaterials();
	mWorld.buildScene();

	for (auto& e : mContext->mGame->mAllRitems)
		mContext->mGame->mOpaqueRitems.push_back(e.get());

	mContext->mGame->BuildFrameResources();
	/*mGame->mAllRitems.clear();
	mGame->mOpaqueRitems.clear();
	mGame->mFrameResources.clear();

	mGame->BuildMaterials();

	mWorld->buildScene();

	mSceneNode->build();

	for (auto& e : mGame->mAllRitems)
		mGame->mOpaqueRitems.push_back(e.get());

	mGame->BuildFrameResources();*/
}
