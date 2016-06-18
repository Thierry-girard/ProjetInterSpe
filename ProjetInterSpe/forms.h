#pragma once

#include "geometry.h"
#include "animation.h"


class Color
{
public:
    float r, g, b;
    Color(float rr = 1.0f, float gg = 1.0f, float bb = 1.0f) {r=rr; g=gg; b=bb;}
};

// Constant Colors
const Color BLACK(0.0f, 0.0f, 0.0f);
const Color RED(1.0f, 0.0f, 0.0f);
const Color GREEN(0.0f, 1.0f, 0.0f);
const Color BLUE(0.0f, 0.0f, 1.0f);
const Color YELLOW(1.0f, 1.0f, 0.0f);
const Color MAGENTA(1.0f, 0.0f, 1.0f);
const Color CYAN(0.0f, 1.0f, 1.0f);
const Color WHITE(1.0f, 1.0f, 1.0f);

// Generic class to render and animate an object
class Form
{
protected:
    Color color;
	// Texture texture;
	Point position;
	Rotation rotation;
public:
	Form() {}
    // Virtual method : Form is a generic type, no rendering is possible
    virtual void render() = 0;
	virtual void update() = 0;
};


// A particular Form
class Sphere : public Form
{
protected:
	double radius;
public:
	Sphere(Point c = Point(), double r = 1.0, Color cl = Color());
	const Point getCenter() { return position; }
	void setCenter(Point c) { position = c; }
	const double getRadius() { return radius; }
	void setRadius(double rad) { if (rad < 0)return; radius = rad; }
	void render();
};
