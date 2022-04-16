#ifndef BOOK_GAMESTATE_HPP
#define BOOK_GAMESTATE_HPP

#include "State.hpp"
#include "World.hpp"
#include "Player.hpp"
#include "SpriteNode.h"

class GameState : public State
{
public:
	GameState(StateStack* stack, Context* context);

	virtual void		draw() override;
	virtual bool		update(const GameTimer& gt) override;
	virtual bool		handleEvent(WPARAM btnState) override; 
	virtual bool 		handleRealTimeInput() override;
	virtual void 		LoadScene() override;
	void ProcessInput();

private:
	World		mWorld;
	

public:
	SceneNode* mSceneNode;
	SpriteNode* mPauseSprite;
};

#endif // BOOK_GAMESTATE_HPP
