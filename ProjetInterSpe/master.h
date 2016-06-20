#pragma once
#include "geometry.h"
#include "animation.h"
#include "forms.h"

class Cue : public Form
{
public:
	Cue();
	~Cue();
	void render();
	void update();
protected:
	//void setColor(Color c);
private:
};

class Ball : public Form
{
public:
	Vector shift;
	Ball(int number, Point position, GLchar* path);
	~Ball();
	void setPosition(Point p);
	Point getPosition();
	void setRadius(double r);
	double getRadius();
	void setRotation(Rotation r);
	Rotation getRotation();
	void setShift(Vector s);
	Vector getShift();
	void setMass(int m);
	int getMass();
	int getNumber();
	int getTeam();
	bool isWhite();
	void render();
	void update();
protected:
	Point position;
	double radius;
	Rotation rotation;
	int mass;
	int number;
	//void setColor(Color c);
	//void setTexture(Texture);
	void setNumber(int n);
private:
};

class Hole : public Form
{
public:
	Point position;
	float radius;
	Hole();
	~Hole();
	void render();
	void update();
};

class Cushion : public Form
{
public:
	Cushion(GLchar* path);
	~Cushion();
	void setSize(Size s);
	Size getSize();
	void setPosition(Point p);
	Point getPosition();
	void setAbsCoeff(float c);
	float getAbsCoeff();
	void render();
	void update();
protected:
	float absorption_coeff;
	Point position;
	Size size;
private:
};

class Table : public Form
{
public:
	Table();
	Table(Point p, Size s);
	~Table();
	void setFrictionCoeff(float c);
	float getFricCoeff();
	void setSize(Size s);
	Size getSize();
	void setCue();
	Cue* getCue();
	void addBall(Ball b);
	void removeBall(Ball b);
	void clearBalls();
	Ball** getBalls();
	void addCushion(Cushion c);
	void clearCushions();
	Cushion** getCushions();
	void addHole(Hole h);
	void addHole(Point P, float radius);
	void clearHoles();
	Hole** getHole();
	void render();
	void update();
protected:
	const static unsigned short NB_OF_BALLS = 16;
	const static unsigned short NB_OF_CUSHIONS = 6;
	const static unsigned short NB_OF_HOLES = 6;
	float friction_coeff;
	Point position;
	Size size;
	Cue* cue;
	Ball* balls[NB_OF_BALLS];
	Cushion* cushions[NB_OF_CUSHIONS];
	Hole* holes[NB_OF_HOLES];
	void setBalls(Ball* b[NB_OF_BALLS]);
	void setCushions(Cushion* c[NB_OF_CUSHIONS]);
	void setHoles(Hole* h[NB_OF_HOLES]);
private:
};
