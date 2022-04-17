#include "TitleState.hpp"
#include "World.hpp"
#include "Game.hpp"


TitleState::TitleState(StateStack* stack, Context* context)
	: State(stack, context)
,	mShowText(true)
,	mBackgroundSprite(nullptr)
//,	mTextEffectTime(())
{
	LoadScene();
}

void TitleState::draw()
{
	mSceneGraph->draw();
}

bool TitleState::update(const GameTimer& gt)
{
	mSceneGraph->update(gt);
	return true;
}

bool TitleState::handleEvent(WPARAM btnState)
{
	requestStackPop();
	
	requestStackPush(States::Menu);
	
	return true;
	
}

 bool TitleState::handleRealTimeInput()
 {
	 return true;
 }

void TitleState::LoadScene()
{
	//Clear items, and resources.
	mContext-> mGame->mAllRitems.clear();
	mContext->mGame->mOpaqueRitems.clear();
	mContext->mGame->mFrameResources.clear();
	// Build our materials
	mContext->mGame->BuildMaterials();

	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(mContext->mGame, "TitleBGTex"));
	mBackgroundSprite = backgroundSprite.get();
	mBackgroundSprite->setPosition(6, 0, 20);
	mBackgroundSprite->setScale(10, 1, 8);
	mBackgroundSprite->setWorldRotation(0, 0, 0);
	mBackgroundSprite->setVelocity(0, 0, 0);
	mSceneGraph->attachChild(std::move(backgroundSprite));

	/*std::unique_ptr<SpriteNode> playBtnTex(new SpriteNode(mGame, "PlayBtnTex"));
	mBackgroundSprite = playBtnTex.get();
	mBackgroundSprite->setPosition(500, 500, 1);
	mBackgroundSprite->setScale(12.0, 1.0, 8.5);
	mBackgroundSprite->setVelocity(0, 0, 0);
	mSceneGraph->attachChild(std::move(playBtnTex));*/

	mSceneGraph->build();
	for (auto& e : mContext->mGame->mAllRitems)
		mContext->mGame->mOpaqueRitems.push_back(e.get());

	mContext->mGame->BuildFrameResources();
}

