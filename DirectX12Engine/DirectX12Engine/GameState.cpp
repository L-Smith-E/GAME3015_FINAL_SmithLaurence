#include "GameState.hpp"
#include "Game.hpp"

GameState::GameState(StateStack& stack, Context context, Game* game)
	:State(stack, context, game)
	, mWorld(&(mGame->mWorld))
	, mPlayer(*context.player)
{
	LoadScene();
}

void GameState::draw()
{
	mWorld->draw();
}

void GameState::ProcessInput()
{
	CommandQueue& commands = mWorld->getCommandQueue();
	(getContext().player)->handleEvent(commands);
	(getContext().player)->handleRealtimeInput(commands);
}

bool GameState::update(const GameTimer& gt)
{
	ProcessInput();
	mWorld->update(gt);
	
	//mPlayer.handleRealtimeInput(commands);
	return true;
}

bool GameState::handleEvent(WPARAM btn)
{
	//CommandQueue& commands = mWorld->getCommandQueue();
	//mPlayer.handleEvent(commands);

	if (btn == 'P')
	{
		requestStackPush(States::Pause);
	}
	return true;
}

void GameState::LoadScene()
{
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
