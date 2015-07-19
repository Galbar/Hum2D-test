#ifndef CONTROL_HPP
#define CONTROL_HPP
#include <iostream>
#include "Hum2D/Behaviour.hpp"
#include "SFML/SFMLPlugin.hpp"
#include "Life.hpp"
using namespace h2d;

class Control : public Behaviour
{
public:
	Control():Behaviour(){}
	~Control(){}

	void init()
	{
		dir_x = actor().transform.x;
		dir_y = actor().transform.y;
		sfml = actor().game().getPlugin<SFMLPlugin>();
		life = actor().getBehaviour<Life>();

		auto view = sfml->window().getView();
		view.setCenter(actor().transform.x, actor().transform.y);
		sfml->window().setView(view);
	}

	void update()
	{
		if (sfml->input().isMouseButtonDown(sf::Mouse::Left))
		{
			auto view = sfml->window().getView();
			dir_x = sfml->input().getMouseCurrentPosition().x + view.getCenter().x - view.getSize().x/2;
			dir_y = sfml->input().getMouseCurrentPosition().y + view.getCenter().y - view.getSize().y/2;
		}

		double d_x = dir_x - actor().transform.x;
		double d_y = dir_y - actor().transform.y;
		double l = sqrt(d_x * d_x + d_y * d_y);
		if (l > 1.0)
		{
			actor().transform.x += d_x/l * actor().game().deltaTime().asSeconds() * 75.0;
			actor().transform.y += d_y/l * actor().game().deltaTime().asSeconds() * 75.0;
			auto view = sfml->window().getView();
			view.setCenter(actor().transform.x, actor().transform.y);
			sfml->window().setView(view);
		}
	}

private:
	double dir_x;
	double dir_y;
	Life* life;
	SFMLPlugin* sfml;
};
#endif
