#include "MenuState.hpp"
#include "World.hpp"
#include "Game.hpp"
//#include "Utility.hpp"
//#include "Game.hpp"


MenuState::MenuState(StateStack& stack, Context context, Game* game)
	: State(stack, context, game)
, mOptionsBtn(nullptr)
, mOptionIndex(0)
, mSceneGraph(new SceneNode(game))
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

bool MenuState::handleEvent(WPARAM btn)
{
	if (btn == VK_SPACE)
	{
		//requestStackPop();
		requestStateClear();
		requestStackPush(States::Game);
		return true;
	}
	else if (btn == VK_BACK)
	{
		requestStackPop();
		requestStackPush(States::Title);
		return true;
	}
	else
		return false;
}

void MenuState::LoadScene()
{
	mGame->mAllRitems.clear();
	mGame->mOpaqueRitems.clear();
	mGame->mFrameResources.clear();

	/*std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(mGame, "TitleBGTex"));
	mBackgroundSprite = backgroundSprite.get();
	mBackgroundSprite->setPosition(0, 0, 0);
	mBackgroundSprite->setScale(600.0, 100000.0, 400);
	mBackgroundSprite->setVelocity(0, 0, 0);
	mSceneGraph->attachChild(std::move(backgroundSprite));*/

	std::unique_ptr<SpriteNode> mSelect(new SpriteNode(mGame, "SelectionBtnTex"));
	mBackgroundSprite = mSelect.get();
	mBackgroundSprite->setPosition(0, 0, 0);
	mBackgroundSprite->setScale(60.0, 10, 40);
	mBackgroundSprite->setVelocity(0, 0, 0);
	mSceneGraph->attachChild(std::move(mSelect));

	mSceneGraph->build();
	for (auto& e : mGame->mAllRitems)
		mGame->mOpaqueRitems.push_back(e.get());

	mGame->BuildFrameResources();
}

//bool MenuState::handleRealtimeInput()
//{
//	return true;
//}