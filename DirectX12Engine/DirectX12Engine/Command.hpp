#ifndef BOOK_COMMAND_HPP
#define BOOK_COMMAND_HPP
#include "Category.hpp"

#include "../../Common/d3dApp.h"

#include <functional>
#include <cassert>

class SceneNode;

class Game;


struct Command
{
	Command();

	std::function<void(SceneNode&, GameTimer)>	action;
	unsigned int	category;
};

template <typename GameObject, typename Function>
std::function<void(SceneNode&, const GameTimer)> derivedAction(Function fn)
{
	return [=](SceneNode& node, const GameTimer& gt)
	{
		assert(dynamic_cast<GameObject*>(&node) != nullptr);

		fn(static_cast<GameObject&>(node), gt);
	};
}
#endif // BOOK_COMMAND_HPP