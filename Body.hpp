#ifndef BODY_HPP
#define BODY_HPP
#include <cmath>
#include "Hum2D/Behaviour.hpp"
#include "Life.hpp"
#include "Circle.hpp"
using namespace h2d;

class Body : public Behaviour
{
public:
	Body():Behaviour(){}
	~Body(){}

	void init()
	{
		life = actor().getBehaviour<Life>();
		circle = actor().getBehaviour<Circle>();
	}

	void update()
	{
		Life* other_life;
		for (Actor* a : actor().game().actors())
		{
			if (a->id() == actor().id()) continue;
			other_life = a->getBehaviour<Life>();
			if (other_life == nullptr) continue;
			if (not other_life->alive) continue;
			double d_x = actor().transform.x - a->transform.x;
			double d_y = actor().transform.y - a->transform.y;
			double l = sqrt(d_x * d_x + d_y * d_y);
			if (l < life->life + other_life->life and life->life > other_life->life)
			{
				double life_delta = (life->life + other_life->life -l) / 2.0;
				life->life += life_delta;
				other_life->life -= life_delta;
			}
		}
	}

private:
	Life* life;
	Circle* circle;
};
#endif
