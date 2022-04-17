#ifndef BOOK_MENUSTATE_HPP
#define BOOK_MENUSTATE_HPP

#include "State.hpp"
#include "SpriteNode.h"
#include "../../Common/d3dApp.h"

class MenuState : public State
{
public:
	MenuState(StateStack* stack, Context* context);
	virtual ~MenuState();

	virtual void		draw() override;
	virtual bool		update(const GameTimer& gt) override;
	virtual bool		handleEvent(WPARAM btnState) override;
	virtual bool 		handleRealTimeInput() override;
	virtual void 		LoadScene() override;
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
	SpriteNode* mBackgroundSprite;
	SpriteNode* mPlayBtn;
	SpriteNode* mOptionsBtn;
	SpriteNode* mQuitBtn;
	SpriteNode* mSelect;
	std::vector<SpriteNode*>	mOptions;
	std::size_t				mOptionIndex;



};
#endif // BOOK_MENUSTATE_HPP