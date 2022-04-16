#pragma once
#include "../../Common/d3dApp.h"
#include <memory>
//#include "StateStack.hpp"
//#include "World.hpp"
//#include "ResourceIdentifiers.hpp"
#include "StateIdentifiers.hpp"
#include "SceneNode.hpp"



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
		Context(Player* player, Game* mGame);
		Game* mGame;
		Player* player;
	};

public:
	State(StateStack* mstack, Context* context);
	virtual ~State();

	virtual void draw() = 0;
	virtual bool update(const GameTimer& gt) = 0;
	virtual bool handleEvent(WPARAM btnState) = 0;
	virtual bool handleRealTimeInput() = 0;
	virtual void LoadScene() = 0;
	
	Context*		getContext() const;
protected:
	void	requestStackPush(States::ID stateID);
	void	requestStackPop();
	void	requestStateClear();

	std::unique_ptr<SceneNode> mSceneGraph;

	std::vector<std::unique_ptr<RenderItem>> mAllRitems;

	
	StateStack*		mStack;
	Context*		mContext;
private:
	
	
};

