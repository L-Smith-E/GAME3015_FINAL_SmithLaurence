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
		requestStateClear();
		//requestStackPop();
		requestStackPush(States::Game);
	}
	else if (btnState == VK_BACK)
	{
		
		requestStackPush(States::Menu);
	}
	return false;
}
 bool PauseState::handleRealTimeInput()
 {
	 return true;
 }

void PauseState::LoadScene()
{
	mContext->mGame->mAllRitems.clear();
	mContext->mGame->mOpaqueRitems.clear();
	mContext->mGame->mFrameResources.clear();
	mContext->mGame->BuildMaterials();

	std::unique_ptr<SpriteNode> PauseScrn(new SpriteNode(mContext->mGame, "PauseTex"));
	mBackgroundSprite = PauseScrn.get();
	mBackgroundSprite->setPosition(6, 0, 20);
	mBackgroundSprite->setScale(10, 5, 10);
	mBackgroundSprite->setWorldRotation(0, 0, 0);
	mBackgroundSprite->setVelocity(0, 0, 0);
	mSceneGraph->attachChild(std::move(PauseScrn));

	mSceneGraph->build();
	for (auto& e : mContext->mGame->mAllRitems)
		mContext->mGame->mOpaqueRitems.push_back(e.get());

	mContext->mGame->BuildFrameResources();
}
#pragma endregion