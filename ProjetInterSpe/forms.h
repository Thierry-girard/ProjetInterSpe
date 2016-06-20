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
public:
    //Color color;
	GLint texture;
public:
	Form(GLchar* path = NULL);
    // Virtual method : Form is a generic type, no rendering is possible
    virtual void render() = 0;
	virtual void update() = 0;
private:
	GLuint LoadTexture(GLchar* path);
};
