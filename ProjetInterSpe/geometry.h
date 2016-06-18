#pragma once

#include "math.h"
#include "settings.h"

class Coordinates
{
public:
    double x, y, z;
    Coordinates(double xx=0, double yy=0, double zz=0) {x=xx; y=yy; z=zz;}
};


class Point : public Coordinates
{
public:
	// Instantiates a Point from its coordinates
	// Point constructor calls the base class constructor and do nothing more
	Point(double xx, double yy, double zz) : Coordinates(xx, yy, zz) {}
	// Or default
	Point() : Coordinates(0, 0, 0) {}
};

class Vector : public Coordinates
{
public:
    // Instantiates a Vector from its coordinates
    Vector(double xx, double yy, double zz) : Coordinates(xx, yy, zz) {}
	// Or without Y
	Vector(double xx, double zz) : Coordinates(xx, 0, zz) {}
    // Or with two points
	Vector(Point p1, Point p2);
	// Or default
	Vector() : Coordinates(0, 0, 0) {}
	// Compute the vector norm
	double norm();
};

class Size : public Coordinates
{
public:
	// Instantiates a Size form its coordinates
	Size(double xx, double yy, double zz) : Coordinates(xx, yy, zz) {}
	// Or without Y
	Size(double xx, double zz) : Coordinates(xx, 0, zz) {}
	// Or with two points
	Size(Point p1, Point p2) : Coordinates(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z) {}
	// Or default
	Size() : Coordinates(0, 0, 0) {}
};

class Rotation : public Coordinates
{
public:
	// Instantiates a Rotation from its coordinates
	Rotation(double xx, double yy, double zz) : Coordinates(xx, yy, zz) {}
	// Or default
	Rotation() : Coordinates(0, 0, 0) {}
};

// Compute the distance between two points
double distance(Point p1, Point p2);
Vector operator*(double const& coeff, Vector const& a);
