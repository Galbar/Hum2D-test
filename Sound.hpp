#ifndef SOUND_HPP
#define SOUND_HPP
#include "SFML/SFMLPlugin.hpp"
#include "Hum2D/Behaviour.hpp"
using namespace h2d;

class Sound : public Behaviour
{
public:
	void init() override
	{
		sfml = actor().game().getPlugin<SFMLPlugin>();
		sfml->sounds().load("sound1.wav");
		sound.setBuffer(*sfml->sounds().get("sound1.wav"));
	}

	void update() override
	{
		if (sfml->input().isMouseButtonPressed(sf::Mouse::Button::Left))
		{
			sound.play();
		}
	}

private:
	SFMLPlugin* sfml;
	sf::Sound sound;
};
#endif
