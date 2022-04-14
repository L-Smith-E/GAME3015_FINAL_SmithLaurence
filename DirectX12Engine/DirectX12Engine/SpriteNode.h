#pragma once
#include "Entity.hpp"

class SpriteNode :
    public Entity
{
public:
	SpriteNode(Game* game, std::string sprite = "Desert");
	RenderItem* mSpriteNodeRitem;

private:
	virtual void		drawCurrent() const;
	virtual void		buildCurrent();

	std::string		mSprite;
};
