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

}

void MenuState::LoadScene()
{
	mContext->mGame->mAllRitems.clear();
	mContext->mGame->mOpaqueRitems.clear();
	mContext->mGame->mFrameResources.clear();
	mContext->mGame->BuildMaterials();

	/*std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(mGame, "TitleBGTex"));
	mBackgroundSprite = backgroundSprite.get();
	mBackgroundSprite->setPosition(0, 0, 0);
	mBackgroundSprite->setScale(600.0, 100000.0, 400);
	mBackgroundSprite->setVelocity(0, 0, 0);
	mSceneGraph->attachChild(std::move(backgroundSprite));*/

	std::unique_ptr<SpriteNode> mSelect(new SpriteNode(mContext->mGame, "SelectionBtnTex"));
	mBackgroundSprite = mSelect.get();
	mBackgroundSprite->setPosition(300, 0, 200);
	mBackgroundSprite->setScale(1.0, 10, 40);
	mBackgroundSprite->setVelocity(0, 0, 0);
	mSceneGraph->attachChild(std::move(mSelect));

	mSceneGraph->build();
	for (auto& e : mContext->mGame->mAllRitems)
		mContext->mGame->mOpaqueRitems.push_back(e.get());

	mContext->mGame->BuildFrameResources();
}

//bool MenuState::handleRealtimeInput()
//{
//	return true;
//}