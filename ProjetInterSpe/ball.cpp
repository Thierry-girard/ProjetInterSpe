#include "master.h"



Ball::Ball(int n, Color c, Point p) {
	number = n;
	color = c;
	center = p;
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

	glTranslated(center.x, center.y, center.z);
	glColor3d(color.r, color.g, color.b);
	gluSphere(gluNewQuadric(), radius, 50, 50);

	glPopMatrix();
}


void Ball::setColor(Color c) {
	color = c;
}


/*void Ball::setTexture(Texture t) {

}*/


void Ball::setNumber(int n) {
	number = n;
}