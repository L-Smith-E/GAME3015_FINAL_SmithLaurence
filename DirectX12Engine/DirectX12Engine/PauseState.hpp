#pragma region step 2
#pragma once

#include "State.hpp"
#include "Player.hpp"
#include "SpriteNode.h"

class PauseState : public State
{
public:
	PauseState(StateStack* stack, Context* context);
	~PauseState();

	virtual void		draw() override;
	virtual bool		update(const GameTimer& gt) override;
	virtual bool		handleEvent(WPARAM btnState) override;
	virtual bool 		handleRealTimeInput() override;
	virtual void 		LoadScene() override;
private:
	//SceneNode* mSceneGraph;
	SpriteNode* mBackgroundSprite;
	SpriteNode* mPausedText;
	SpriteNode* mInstructionText;

	
public:

	
};
#pragma endregion

