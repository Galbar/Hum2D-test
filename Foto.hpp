#ifndef FOTO_HPP
#define FOTO_HPP
#include <cassert>
#include "SFML/AnimatedSprite.hpp"
#include "SFML/SFMLPlugin.hpp"
using namespace h2d;

class Foto : public Behaviour
{
public:
    Foto ():Behaviour(){}
    ~Foto (){}

	void init()
	{
		actor().transform.z = 10;
		auto sfml = actor().game().getPlugin<SFMLPlugin>();
		AnimatedSprite& spr = *actor().getBehaviour<AnimatedSprite>();
		sfml->textures().load("texture2.png");
		sf::Texture* texture = sfml->textures().get("texture2.png");
		spr.setFrameSize(32, 32);
		spr.setFrameOrder({Frame{0, 300}, Frame{10, 300}, Frame{0, 300}, Frame{20, 300}});
		spr.sprite().setTexture(*texture);
	}
};
#endif
