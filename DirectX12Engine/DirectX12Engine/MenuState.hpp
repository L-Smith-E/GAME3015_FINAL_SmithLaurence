#ifndef BOOK_MENUSTATE_HPP
#define BOOK_MENUSTATE_HPP

#include "State.hpp"
#include "SpriteNode.h"
#include "../../Common/d3dApp.h"

class MenuState : public State
{
public:
	MenuState(StateStack& stack, Context context, Game* game);
	virtual ~MenuState();
	virtual void			draw() override;
	virtual bool			update(const GameTimer& gt) override;
	virtual bool			handleEvent(WPARAM btn) override;
	//virtual bool			handleRealtimeInput()override;
	void					updateOptionText();


private:
	enum OptionNames
	{
		Play,
		Exit,
	};


private:
	//sf::Sprite				mBackgroundSprite;

	//std::vector<DirectX::SpriteFont>	mOptions;
	SceneNode* mSceneGraph;
	SpriteNode* mBackgroundSprite;
	SpriteNode* mPlayBtn;
	SpriteNode* mOptionsBtn;
	SpriteNode* mQuitBtn;
	SpriteNode* mSelect;
	std::size_t				mOptionIndex;

	virtual void LoadScene() override;
};

#endif // BOOK_MENUSTATE_HPP
