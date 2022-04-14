#include "State.hpp"
#include "StateStack.hpp"
#include "Game.hpp"


State::Context::Context(Player& player)
	: player(&player)
{
}

State::State(StateStack& stack, Context context, Game* game)
	:mStack(&stack), mGame(game), mContext(context)
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

State::Context State::getContext() const
{
	return mContext;
}

void State::LoadScene()
{
	
}
