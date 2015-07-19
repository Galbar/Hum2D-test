#ifndef LIFE_HPP
#define LIFE_HPP
#include "Hum2D/Behaviour.hpp"
using namespace h2d;

class Life : public Behaviour
{
public:
	Life():
	Behaviour(),
	life(100.0),
	alive(true){}
	~Life(){}

	void postUpdate()
	{
		if (life <= 0.0)
			actor().game().destroy(actor());
	}

	double life;
	bool alive;
};
#endif
