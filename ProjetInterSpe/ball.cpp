#include "master.h"
#include <typeinfo>



const double Ball::DEFAULT_RADIUS = 3.0;


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


void Ball::update(Form* f) {
	{
		if (typeid(f) == typeid(Hole)) {
			if (distance(f->getAnim().getPosition(), this->getAnim().getPosition()) < this->getRadius()) {
				//removeBall(balls[i]);
			}
		}
	}

	{
		Vector Vector_tmp;
		if (typeid(f) == typeid(Ball)) {
			if (distance(this->getAnim().getPosition(), f->getAnim().getPosition()) < 2 * this->getRadius()) {
				// Vector_tmp = balls[i]->getAnim().getVelocity();
				// balls[j]->getAnim().setVelocity(Vector(Vector_tmp.x, 0, Vector_tmp.z));

				Vector_tmp = Vector(this->getAnim().getPosition(), f->getAnim().getPosition());
				f->getAnim().setVelocity(0.2*Vector_tmp);
			}
		}
	}

	{
		if (typeid(f) == typeid(Cushion)) {
			// TODO BAPTDUPR
			/*
			if (balls[i]->getAnim().getPosition().x + balls[i]->getRadius() > size.x && balls[i]->getAnim().getVelocity().x > 0) {
				Vector_tmp = balls[i]->getAnim().getVelocity();
				balls[i]->getAnim().setVelocity(Vector(-Vector_tmp.x, 0, Vector_tmp.z));
			}

			else if (balls[i]->getAnim().getPosition().x - balls[i]->getRadius() < 0 && balls[i]->getAnim().getVelocity().x < 0) {
				Vector_tmp = balls[i]->getAnim().getVelocity();
				balls[i]->getAnim().setVelocity(Vector(-Vector_tmp.x, 0, Vector_tmp.z));
			}

			else if (balls[i]->getAnim().getPosition().z + balls[i]->getRadius() > size.z && balls[i]->getAnim().getVelocity().z > 0) {
				Vector_tmp = balls[i]->getAnim().getVelocity();
				balls[i]->getAnim().setVelocity(Vector(Vector_tmp.x, 0, -Vector_tmp.z));
			}

			else if (balls[i]->getAnim().getPosition().z - balls[i]->getRadius() < 0 && balls[i]->getAnim().getVelocity().z < 0) {
				Vector_tmp = balls[i]->getAnim().getVelocity();
				balls[i]->getAnim().setVelocity(Vector(Vector_tmp.x, 0, -Vector_tmp.z));
			}
			*/

			// RECOPIER DANS CUSHION::UPDATE
		}
	}
}


void Ball::setNumber(int n) {
	number = n;
}