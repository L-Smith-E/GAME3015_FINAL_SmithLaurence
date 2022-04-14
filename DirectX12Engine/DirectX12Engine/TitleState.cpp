#include "TitleState.hpp"
#include "World.hpp"
#include "Game.hpp"


TitleState::TitleState(StateStack& stack, Context context, Game* game)
	: State(stack, context, game)
,	mShowText(true)
,	mBackgroundSprite(nullptr)
,	mSceneGraph(new SceneNode(game))
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

bool TitleState::handleEvent(WPARAM btn)
{
	requestStackPop();
	
	requestStackPush(States::Menu);
	
	return true;
	
}

void TitleState::LoadScene()
{
	//Clear items, and resources.
	mGame->mAllRitems.clear();
	mGame->mOpaqueRitems.clear();
	mGame->mFrameResources.clear();
	// Build our materials
	mGame->BuildMaterials();

	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(mGame, "TitleBGTex"));
	mBackgroundSprite = backgroundSprite.get();
	mBackgroundSprite->setPosition(0, 0, 0);
	mBackgroundSprite->setScale(600.0, 100000.0, 400);
	mBackgroundSprite->setVelocity(0, 0, 0);
	mSceneGraph->attachChild(std::move(backgroundSprite));

	/*std::unique_ptr<SpriteNode> playBtnTex(new SpriteNode(mGame, "PlayBtnTex"));
	mBackgroundSprite = playBtnTex.get();
	mBackgroundSprite->setPosition(500, 500, 1);
	mBackgroundSprite->setScale(12.0, 1.0, 8.5);
	mBackgroundSprite->setVelocity(0, 0, 0);
	mSceneGraph->attachChild(std::move(playBtnTex));*/

	mSceneGraph->build();
	for (auto& e : mGame->mAllRitems)
		mGame->mOpaqueRitems.push_back(e.get());

	mGame->BuildFrameResources();
}

