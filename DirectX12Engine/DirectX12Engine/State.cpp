#include "State.hpp"
#include "StateStack.hpp"
#include "Game.hpp"
#include "SceneNode.hpp"


State::Context::Context( Player* player, Game* mGame)
	:player(player)
,	mGame(mGame)
{
}

State::State(StateStack* stack, Context* context)
	:mStack(stack), mContext(context), mSceneGraph(std::make_unique<SceneNode>(context->mGame))
{
}

State::~State()
{
}


void State::requestStackPush(States::ID stateID)
{
	mStack->pushState(stateID);
}

void State::requestStackPop()
{
	mStack->popState();
}

void State::requestStateClear()
{
	mStack->clearStates();
}

State::Context* State::getContext() const
{
	return mContext;
}

/*oid State::LoadScene()
{
	
}*/
