#include "MenuState.hpp"
#include "World.hpp"
#include "Game.hpp"
//#include "Utility.hpp"
//#include "Game.hpp"


MenuState::MenuState(StateStack* stack, Context* context)
	: State(stack, context)
, mOptionsBtn(nullptr)
, mOptionIndex(0)
, mPlayBtn(nullptr)
, mQuitBtn(nullptr)
{
	LoadScene();
}
MenuState::~MenuState()
{
}

void MenuState::draw()
{
	mSceneGraph->draw();
}

bool MenuState::update(const GameTimer& gt)
{
	return true;
}

bool MenuState::handleEvent(WPARAM btnState)
{
	if (btnState == 'E')
	{
		//requestStackPop();
		requestStateClear();
		requestStackPush(States::Game);
		return true;
	}
	else if (btnState == VK_BACK)
	{
		requestStackPop();
		requestStackPush(States::Title);
		return true;
	}
	else
		return true;
}

bool MenuState::handleRealTimeInput()
{
	return true;
}

void MenuState::LoadScene()
{
	mContext->mGame->mAllRitems.clear();
	mContext->mGame->mOpaqueRitems.clear();
	mContext->mGame->mFrameResources.clear();
	mContext->mGame->BuildMaterials();

	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(mContext->mGame, "MenuBGTex"));
	mBackgroundSprite = backgroundSprite.get();
	mBackgroundSprite->setPosition(0, 0, 0);
	mBackgroundSprite->setScale(600.0, 100000.0, 400);
	mBackgroundSprite->setVelocity(0, 0, 0);
	mSceneGraph->attachChild(std::move(backgroundSprite));

	std::unique_ptr<SpriteNode> mSelect(new SpriteNode(mContext->mGame, "QuitBtnTex"));
	mBackgroundSprite = mSelect.get();
	mBackgroundSprite->setPosition(6, 0, 20);
	mBackgroundSprite->setScale(1, 1, 1);
	mBackgroundSprite->setWorldRotation(0, 0, 0);
	mBackgroundSprite->setVelocity(0, 0, 0);
	mSceneGraph->attachChild(std::move(mSelect));

	std::unique_ptr<SpriteNode> mQuit(new SpriteNode(mContext->mGame, "QuitBtnTex"));
	mBackgroundSprite = mQuit.get();
	mBackgroundSprite->setPosition(6, 0, 18.5f);
	mBackgroundSprite->setScale(1, 1, 1);
	mBackgroundSprite->setWorldRotation(0, 0, 0);
	mBackgroundSprite->setVelocity(0, 0, 0);
	mSceneGraph->attachChild(std::move(mQuit));

	mSceneGraph->build();
	for (auto& e : mContext->mGame->mAllRitems)
		mContext->mGame->mOpaqueRitems.push_back(e.get());

	mContext->mGame->BuildFrameResources();
}

//bool MenuState::handleRealtimeInput()
//{
//	return true;
//}