#pragma region step 3
#include "PauseState.hpp"
#include "GameState.hpp"
#include "Game.hpp"

PauseState::PauseState(StateStack* stack, Context* context)
	:State(stack, context)
,  mBackgroundSprite(nullptr)
,  mPausedText()
,  mInstructionText()
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

bool PauseState::handleEvent(WPARAM btnState)
{

	if (btnState == 'P')
	{
		requestStackPop();
	}
	else if (btnState == VK_BACK)
	{
		requestStateClear();
		requestStackPush(States::Menu);
	}
	return false;
}
 bool PauseState::handleRealTimeInput()
 {

 }

void PauseState::LoadScene()
{
	
}
#pragma endregion