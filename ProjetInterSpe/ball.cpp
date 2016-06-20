#include "master.h"



Ball::Ball(int n, GLchar* path) : Form(path)
{
	number = n;
	radius = DEFAULT_RADIUS;
}


Ball::~Ball() {

}



void Ball::setRadius(double r) {
	radius = r;
}



double Ball::getRadius() {
	return radius;
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
	
	Point p = getAnim().getPosition();
	Rotation r = getAnim().getRotation();

	glTranslated(p.x, p.y, p.z);
	glRotated(r.phi, 1, 0, 0);
	glRotated(r.theta, 0, 1, 0);

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


void Ball::setAnim(Animation a) {
	anim = a;
}


Animation Ball::getAnim() {
	return anim;
}


void Ball::setNumber(int n) {
	number = n;
}