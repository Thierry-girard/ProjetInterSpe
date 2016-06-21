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
	void setAnim(Animation a);
	Animation getAnim();
protected:
	Animation anim;
};

class Ball : public Form
{
public:
	const double DEFAULT_RADIUS = 3;
	Ball(int number, GLchar* path);
	~Ball();
	void setRadius(double r);
	double getRadius();
	void setMass(int m);
	int getMass();
	int getNumber();
	int getTeam();
	bool isWhite();
	void render();
	void setAnim(Animation a);
	Animation getAnim();
protected:
	double radius;
	int mass;
	int number;
	Animation anim;
	void setNumber(int n);
};

class Hole : public Form
{
public:
	Point position;
	double radius;
	Hole();
	~Hole();
	void setPosition(Point p);
	Point getPosition();
	void render();
};

class Cushion : public Form
{
public:
	Cushion(GLchar* path);
	~Cushion();
	void setAbsCoeff(float c);
	float getAbsCoeff();
	void setPosition(Point p);
	Point getPosition();
	void setSize(Size s);
	Size getSize();
	void render();
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
	void addHole(Point P, double radius);
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
