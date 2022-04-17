#ifndef BOOK_TITLESTATE_HPP
#define BOOK_TITLESTATE_HPP

#include "State.hpp"
#include "SpriteNode.h"
#include "../../Common/d3dApp.h"

class TitleState : public State
{

public:
	TitleState(StateStack* stack, Context* context);

	virtual void		draw() override;
	virtual bool		update(const GameTimer& gt) override;
	virtual bool		handleEvent(WPARAM btnState) override;
	virtual bool 		handleRealTimeInput() override;
	virtual void 		LoadScene() override;

private:
	//SceneNode* mSceneGraph;
	SpriteNode* mBackgroundSprite;
	SpriteNode* mPlayBtn;
	bool	mShowText;
	//float	mTextEffectTime;
	

};
#endif // BOOK_TITLESTATE_HPP


