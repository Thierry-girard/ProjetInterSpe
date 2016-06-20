#pragma once

#include "geometry.h"
#include "math.h"

#define PI 3.14159265358979323846

class Animation
{
private:
	Point position;
	Vector velocity;
	Vector acceleration;
	Rotation rotation;
public:
	Animation();
	Animation(Point p, Vector v, Vector a, Rotation r);
	~Animation();
	void setPosition(Point p);
	Point getPosition();
	void setVelocity(Vector v);
	Vector getVelocity();
	void setAcceleration(Vector a);
	Vector getAcceleration();
	void setRotation(Rotation r);
	Rotation getRotation();
    void update();
};
