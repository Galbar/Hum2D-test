#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "SFML/Shape.hpp"
#include "Life.hpp"
using namespace h2d;

class Circle : public Shape
{
public:
	Circle():Shape(){}
	~Circle(){}

	void init()
	{
		Shape::init();
		life = actor().getBehaviour<Life>();
		p_shape.setRadius(life->life);
		p_shape.setOrigin(life->life,life->life);
		setShape(p_shape);
		auto sfml = actor().game().getPlugin<SFMLPlugin>();
		sfml->textures().load("tex1","texture.png");
		p_shape.setTexture(sfml->textures().get("tex1"));
	}

	void update()
	{
		auto sfml = actor().game().getPlugin<SFMLPlugin>();
		p_shape.setRadius(life->life);
		p_shape.setOrigin(life->life,life->life);
	}

	sf::CircleShape& getCircle()
	{
		return p_shape;
	}

private:
	sf::CircleShape p_shape;
	Life* life;
};
#endif
