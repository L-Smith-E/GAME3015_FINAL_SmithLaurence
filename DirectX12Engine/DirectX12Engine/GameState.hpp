#ifndef BOOK_GAMESTATE_HPP
#define BOOK_GAMESTATE_HPP

#include "State.hpp"
#include "World.hpp"
#include  "Player.hpp"
#include "SpriteNode.h"

class GameState : public State
{
public:
	GameState(StateStack& stack, Context context, Game* game);

	virtual void		draw();
	virtual bool		update(const GameTimer& gt);
	virtual bool		handleEvent(WPARAM btn);
	void ProcessInput();

private:
	World*		mWorld;
	Player&		mPlayer;

public:
	SceneNode* mSceneNode;
	SpriteNode* mPauseSprite;

private:
	virtual void LoadScene() override;
};

#endif // BOOK_GAMESTATE_HPP
