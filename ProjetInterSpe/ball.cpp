#include "master.h"



Ball::Ball(int n, Color c, Point p) {
	number = n;
	color = c;
	position = p;
	radius = 3;
}


Ball::~Ball() {

}



void Ball::setRotation(Rotation r) {
	rotation = r;
}



Rotation Ball::getRotation() {
	return rotation;
}



void Ball::setShift(Vector s) {
	shift = s;
}



Vector Ball::getShift() {
	return shift;
}



void Ball::setMass(int m) {
	mass = m;
}



int Ball::getMass() {
	return mass;
}



int Ball::getNumber() {
	return number;
}



int Ball::getTeam() {
	if (getNumber() < 8)
		return 1;
	if (getNumber() > 8)
		return 2;
	return 0;
}



bool Ball::isWhite() {
	if (getNumber() == 0)
		return true;
	return false;
}


void Ball::render() {
	glPushMatrix();

	GLUquadric *quad = gluNewQuadric();

	glRotated(rotation.x, 1, 0, 0);
	glRotated(rotation.y, 0, 1, 0);
	glTranslated(position.x, position.y, position.z);
	glColor3f(color.r, color.g, color.b);
	gluSphere(quad, radius, 10, 10);

	gluDeleteQuadric(quad);

	glPopMatrix();
}


void Ball::update() {
	// This might never be called
}


void Ball::setColor(Color c) {
	color = c;
}


/*void Ball::setTexture(Texture t) {

}*/


void Ball::setNumber(int n) {
	number = n;
}