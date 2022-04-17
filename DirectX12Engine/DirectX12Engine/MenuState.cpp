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
	if (btnState == 'W' || btnState == VK_UP)
	{
		if (mOptionIndex > 0)
		{
			mOptionIndex--;
			//LoadScene();
		}
		else
			mOptionIndex = mOptions.size() - 1;
	}
	else if (btnState == 'S' || btnState == VK_DOWN)
	{
		if (mOptionIndex < mOptions.size() - 1)
		{
			mOptionIndex++;
		}
		else
			mOptionIndex = 0;
	}

	else if (btnState == 'E' || btnState == VK_RETURN)
	{
		if (mOptionIndex == Play)
		{
			requestStackPop();
			requestStackPush(States::Game);
		}
		else if (mOptionIndex == Exit)
		{
			requestStackPop();
			requestStackPush(States::Title);
		}
		//requestStateClear();
		return true;
	}
	else if (btnState == VK_BACK)
	{
		requestStackPop();
		requestStackPush(States::Title);
		return true;
	}
	else
	{
		return false;
	}
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
	mBackgroundSprite->setPosition(6, 0, 20);
	mBackgroundSprite->setScale(26.0, 1.0, 19);
	mBackgroundSprite->setVelocity(0, 0, 0);
	mSceneGraph->attachChild(std::move(backgroundSprite));

	std::unique_ptr<SpriteNode> SelectionBtnTex(new SpriteNode(mContext->mGame, "SelectionBtnTex"));
	mSelect = SelectionBtnTex.get();
	mSelect->setPosition(12.5, 1, 20);
	mSelect->setScale(1, 1, 1);
	mSelect->setWorldRotation(0, 0, 0);
	mSelect->setVelocity(0, 0, 0);
	mSceneGraph->attachChild(std::move(SelectionBtnTex));

	std::unique_ptr<SpriteNode> mPlay(new SpriteNode(mContext->mGame, "PlayBtnTex"));
	mBackgroundSprite = mPlay.get();
	mBackgroundSprite->setPosition(15, 1, 20.0f);
	mBackgroundSprite->setScale(4, 1, 2);
	mBackgroundSprite->setWorldRotation(0, 0, 0);
	mBackgroundSprite->setVelocity(0, 0, 0);
	mSceneGraph->attachChild(std::move(mPlay));

	std::unique_ptr<SpriteNode> mQuit(new SpriteNode(mContext->mGame, "QuitBtnTex"));
	mBackgroundSprite = mQuit.get();
	mBackgroundSprite->setPosition(15, 1, 16.5f);
	mBackgroundSprite->setScale(4, 1, 2);
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