#define INPUT_DISABLE_JOYSTICK 1
#include "Hum2D/Game.hpp"
#include "SFML/SFMLPlugin.hpp"
#include "Circle.hpp"
#include "Body.hpp"
#include "Life.hpp"
#include "SFML/Sprite.hpp"
#include "Foto.hpp"
#include "Music.hpp"
#include "Sound.hpp"
#include "Control.hpp"
using namespace h2d;

int main()
{
	SFMLPlugin sfml(500, 500, "Game");
	Game game(60);
	game.addPlugin(sfml);
	Actor& y = game.makeActor();
	y.addBehaviour<AnimatedSprite>();
	y.addBehaviour<Foto>();
	y.addBehaviour<Music>();
	Actor& player = game.makeActor();
	player.addBehaviour<Life>().life = 10.0;
	player.addBehaviour<Control>();
	player.addBehaviour<Body>();
	player.addBehaviour<Sound>();
	player.addBehaviour<Circle>().getCircle().setFillColor(sf::Color(56, 158, 176));
	player.transform.x = player.transform.y = 100.0;

	for (int i = 0; i < 10; ++i)
	{
		Actor& a = game.makeActor();
		a.addBehaviour<Body>();
		a.addBehaviour<Circle>().getCircle().setFillColor(sf::Color(150, 158, 176));
		a.addBehaviour<Life>().life = 5.0;
		a.transform.x = 55*i+50;
		a.transform.y = 300.0;
	}
	game.run();
	return 0;
}
