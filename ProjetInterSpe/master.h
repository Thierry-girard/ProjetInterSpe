#pragma once
#include "geometry.h"
#include "animation.h"
#include "forms.h"

class Cue
{
public:
	Point position;
	Rotation rotation;
	Cue();
	~Cue();
protected:
	Color color;
	// Texture texture;
	void setColor(Color c);
	// void setTexture(Texture);
private:
};

class Ball
{
public:
	Rotation rotation;
	Vector shift;
	Ball();
	~Ball();
	void setPosition(Point p);
	Point getPosition();
	void setRotation(Rotation r);
	Rotation getRotation();
	void setShift(Vector s);
	Vector getShift();
	void setMass(int m);
	int getMass();
	int getNumber();
	int getTeam();
	bool isWhite();
protected:
	Color color;
	// Texture texture;
	Point position;
	int mass;
	int number;
	void setColor(Color c);
	//void setTexture(Texture);
	void setNumber(int n);
private:
};

class Hole
{
public:
	Point center;
	float radius;
	Hole();
	~Hole();
};

class Cushion
{
public:
	Cushion();
	~Cushion();
	void setSize(Size s);
	Size getSize();
	void setPosition(Point p);
	Point getPosition();
	void setAbsCoeff(float c);
	float getAbsCoeff();
protected:
	float absorption_coeff;
	Point position;
	Size size;
private:
};

class Table
{
public:
	Table();
	~Table();
	void setFrictionCoeff(float c);
	float getFricCoeff();
	void setSize(Size s);
	Size getSize();
	void setCue();
	void getCue();
	void addBall(Ball b);
	void removeBall(Ball b);
	void clearBalls();
	Ball* getBalls();
	void addCushion(Cushion c);
	void clearCushions();
	Cushion* getCushions();
	void addHole(Hole h);
	void clearHoles();
	Hole* getHole();
	void render();
protected:
	float friction_coeff;
	Size size;
	Cue* cue;
	Ball* balls;
	Cushion* cushions;
	Hole* holes;
	void setBalls(Ball* b);
	void setCushions(Cushion* c);
	void setHoles(Hole* h);
private:
};
