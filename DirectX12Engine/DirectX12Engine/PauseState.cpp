#pragma region step 3
#include "PauseState.hpp"
#include "GameState.hpp"
#include "Game.hpp"

PauseState::PauseState(StateStack& stack, Context context, Game* game)
	:State(stack, context, game)
,  mBackgroundSprite(nullptr)
,  mPausedText()
,  mInstructionText()
,	mSceneGraph(new SceneNode(game))
{
	LoadScene();
}

PauseState::~PauseState()
{
}

void PauseState::draw()
{
	mSceneGraph->draw();
}

bool PauseState::update(const GameTimer& gt)
{
	return false;
}

bool PauseState::handleEvent(WPARAM btn)
{

	if (btn == VK_ESCAPE)
	{
		requestStackPop();
	}
	else if (btn == VK_BACK)
	{
		requestStateClear();
		requestStackPush(States::Menu);
	}
	return false;
}

void PauseState::LoadScene()
{
	
}
#pragma endregion