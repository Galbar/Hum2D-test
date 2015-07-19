#ifndef MUSIC_HPP
#define MUSIC_HPP
#include "SFML/SFMLPlugin.hpp"
#include "Hum2D/Behaviour.hpp"
using namespace h2d;

class Music : public Behaviour
{
public:
	void init() override
	{
		sfml = actor().game().getPlugin<SFMLPlugin>();
		sfml->music().load("main theme", "music1.wav");
		sfml->music().get("main theme")->play();
	}

	void update() override
	{
		if (sfml->input().isKeyPressed(sf::Keyboard::Key::Space))
		{
			sf::Music* music = sfml->music().get("main theme");
			switch (music->getStatus()) {
				case sf::SoundSource::Status::Paused:
				case sf::SoundSource::Status::Stopped:
					music->play();
					break;
				default:
					music->pause();
			}
		}
	}
private:
	SFMLPlugin* sfml;
};
#endif
