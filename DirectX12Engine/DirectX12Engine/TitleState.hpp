#ifndef BOOK_TITLESTATE_HPP
#define BOOK_TITLESTATE_HPP

#include "State.hpp"
#include "SpriteNode.h"
#include "../../Common/d3dApp.h"

class TitleState : public State
{

public:
	TitleState(StateStack& stack, Context context, Game* game);

	virtual void	draw();
	virtual bool	update(const GameTimer& gt);
	virtual bool	handleEvent(WPARAM btn);
	

private:
	SceneNode* mSceneGraph;
	SpriteNode* mBackgroundSprite;
	SpriteNode* mPlayBtn;
	bool	mShowText;
	//float	mTextEffectTime;
	virtual void LoadScene() override;

};
#endif // BOOK_TITLESTATE_HPP


