#pragma once

#include "math.h"
#include "settings.h"

class Coordinates
{
public:
    double x, y, z;
	Coordinates(double xx, double yy, double zz);
	Coordinates();
};


class Point : public Coordinates
{
public:
	// Instantiates a Point from its coordinates
	// Point constructor calls the base class constructor and do nothing more
	Point(double xx, double yy, double zz);
	// Or default
	Point();
};

class Vector : public Coordinates
{
public:
    // Instantiates a Vector from its coordinates
	Vector(double xx, double yy, double zz);
	// Or without Y
	Vector(double xx, double zz);
    // Or with two points
	Vector(Point p1, Point p2);
	// Or default
	Vector();
	// Compute the vector norm
	double norm();
};

class Size : public Coordinates
{
public:
	// Instantiates a Size form its coordinates
	Size(double xx, double yy, double zz);
	// Or without Y
	Size(double xx, double zz);
	// Or with two points
	Size(Point p1, Point p2);
	// Or default
	Size();
};

class Rotation
{
public:
	double phi, theta;
	// Instantiates a Rotation from its coordinates
	Rotation(double p, double t);
	// Or default
	Rotation();
};

// Compute the distance between two points
double distance(Point p1, Point p2);

// Operator
Vector operator*(double const& coeff, Vector const& v);
Vector operator*(Vector const& v, double const& coeff);
Vector operator+(Vector const& v1, Vector const& v2);
Vector operator-(Vector const& v1, Vector const& v2);
double operator*(Vector const& v1, Vector const& v2);
