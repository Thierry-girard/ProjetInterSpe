#include "master.h"



Ball::Ball(int n, Point p, GLchar* path) : Form(path)
{
	number = n;
	position = p;
	rotation = Rotation(180, 0, 0);
	radius = 3;
}


Ball::~Ball() {

}



void Ball::setPosition(Point p) {
	position = p;
}



Point Ball::getPosition() {
	return position;
}



void Ball::setRadius(double r) {
	radius = r;
}



double Ball::getRadius() {
	return radius;
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

	glTranslated(position.x, position.y, position.z);
	glRotated(rotation.x, 1, 0, 0);
	glRotated(rotation.y, 0, 1, 0);

	if (texture != NULL) {
		gluQuadricNormals(quad, GLU_SMOOTH);
		gluQuadricTexture(quad, GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
		gluQuadricTexture(quad, GLU_TRUE);
	}

	gluSphere(quad, radius, 100, 100);
	glDisable(GL_TEXTURE_2D);

	gluDeleteQuadric(quad);

	glPopMatrix();
}


void Ball::update() {
	// This might never be called
}


void Ball::setNumber(int n) {
	number = n;
}