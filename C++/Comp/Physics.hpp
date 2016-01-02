#ifndef PHYSICSHPP
#define PHYSICSHPP

#include "../Vector.hpp"

///////////////////////
/// Vector velocity = Vector::ZERO, Vector orgigin = Vector::ZERO, float radians = 0.0f, float maxSpeed = 0.0f
///////////////////////
struct Physics{
	Vector velocity;
	float maxSpeed;
	Vector origin;
	float radians;

	Physics(Vector velocity = Vector::ZERO, Vector origin = Vector::ZERO, float radians = 0.0f, float maxSpeed = 0.0f)
		: velocity(velocity), origin(origin), radians(radians), maxSpeed(maxSpeed) {}
};

#endif