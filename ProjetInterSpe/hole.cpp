#include "master.h"
#include <typeinfo>



Hole::Hole(Point p, double r) {
	position = p;
	radius = r;
}


Hole::~Hole() {

}


void Hole::render() {
	glPushMatrix();

	GLUquadric *quad = gluNewQuadric();

	Point p = getPosition();

	glTranslated(p.x, p.y, p.z);
	glColor3d(0.0, 0.0, 0.0);

	gluSphere(quad, radius, 100, 100);
	gluDeleteQuadric(quad);

	glPopMatrix();
}


void Hole::update(Form* f) {
	if (typeid(f) == typeid(Ball)) {
		Ball* b = (Ball*)f;
		if (distance(this->getAnim().getPosition(), f->getAnim().getPosition()) < b->getRadius()) {
			//removeBall(balls[i]);
		}
	}
}


void Hole::setPosition(Point p) {
	position = p;
}


Point Hole::getPosition() {
	return position;
}
