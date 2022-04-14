#pragma once
#include "../../Common/d3dApp.h"
#include <memory>
//#include "StateStack.hpp"
//#include "World.hpp"
//#include "ResourceIdentifiers.hpp"
#include "StateIdentifiers.hpp"




class StateStack;
class Player;
class Game;

//namespace render
//{
//	class RenderWindow;
//}

class State
{
public:
	typedef std::unique_ptr<State> Ptr;

	struct Context
	{
		Context(Player& player);
		
		Player* player;
	};

public:
	State(StateStack& stack, Context context, Game* game);
	virtual ~State();

	virtual void draw() = 0;
	virtual bool update(const GameTimer& gt) = 0;
	virtual bool handleEvent(WPARAM btn) = 0;
	//virtual bool handleRealtimeInput() = 0;
	virtual void LoadScene();
	Game* mGame;

protected:
	void	requestStackPush(States::ID stateID);
	void	requestStackPop();
	void	requestStateClear();

	Context		getContext() const;
StateStack* mStack;
private:
	
	Context		mContext;
};

