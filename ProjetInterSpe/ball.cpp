#include "master.h"



Ball::Ball()
{

}


Ball::~Ball() {

}


void Ball::setPosition(Point p) {
	position = p;
}



Point Ball::getPosition() {
	return position;
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


void Ball::setColor(Color c) {
	color = c;
}


/*void Ball::setTexture(Texture t) {

}*/


void Ball::setNumber(int n) {
	number = n;
}