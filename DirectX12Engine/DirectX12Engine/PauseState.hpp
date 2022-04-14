#pragma region step 2
#pragma once

#include "State.hpp"
#include "Player.hpp"
#include "SpriteNode.h"

class PauseState : public State
{
public:
	PauseState(StateStack& stack, Context context, Game* game);
	~PauseState();

	virtual void  draw();
	virtual bool update(const GameTimer& gt);
	virtual bool handleEvent(WPARAM btn);

private:
	SceneNode* mSceneGraph;
	SpriteNode* mBackgroundSprite;
	SpriteNode* mPausedText;
	SpriteNode* mInstructionText;

private:
	virtual void LoadScene() override;
};
#pragma endregion

