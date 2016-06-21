#include <cmath>
#include "geometry.h"


using namespace std;

Vector operator*(double const& coeff, Vector const& v) {
	return Vector(coeff * v.x, coeff * v.y, coeff * v.z);
}

Vector operator*(Vector const& v, double const& coeff) {
	return coeff * v;
}

Vector operator+(Vector const& v1, Vector const& v2) {
	return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector operator-(Vector const& v1, Vector const& v2) {
	return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

double operator*(Vector const& v1, Vector const& v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}




Coordinates::Coordinates(double xx, double yy, double zz) {
	x = xx;
	y = yy;
	z = zz;
}


Coordinates::Coordinates() {
	x = 0;
	y = 0;
	z = 0;
}


Point::Point(double xx, double yy, double zz) {
	x = xx;
	y = yy;
	z = zz;
}


Point::Point() {
	x = 0;
	y = 0;
	z = 0;
}


Vector::Vector(double xx, double yy, double zz) {
	x = xx;
	y = yy;
	z = zz;
}


Vector::Vector(double xx, double zz) {
	x = xx;
	y = 0;
	z = zz;
}


Vector::Vector(Point p1, Point p2) {
    x = p2.x - p1.x;
    y = p2.y - p1.y;
    z = p2.z - p1.z;
}


Vector::Vector() {
	x = 0;
	y = 0;
	z = 0;
}


double Vector::norm() {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}


Size::Size(double xx, double yy, double zz) {
	x = xx;
	y = yy;
	z = zz;
}


Size::Size(double xx, double zz) {
	x = xx;
	y = 0;
	z = zz;
}


Size::Size(Point p1, Point p2) {
	x = p2.x - p1.x;
	y = p2.y - p1.y;
	z = p2.z - p1.z;
}


Size::Size() {
	x = 0;
	y = 0;
	z = 0;
}


Rotation::Rotation(double p, double t) {
	phi = p;
	theta = t;
}


Rotation::Rotation() {
	phi = 0;
	theta = 0;
}



double distance(Point p1, Point p2)
{
    return Vector(p1, p2).norm();
}
