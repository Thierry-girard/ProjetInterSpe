#include "animation.h"


Animation::Animation() : Animation(Point(0, 0, 0), Vector(0, 0, 0), Vector(0, 0, 0), Rotation(0, 0)) {}


Animation::Animation(Point p, Vector v, Vector a, Rotation r) {
	position = p;
	velocity = v;
	acceleration = a;
	rotation = r;
}


Animation::~Animation() {

}


void Animation::setPosition(Point p) {
	position = p;
}


Point Animation::getPosition() {
	return position;
}


void Animation::setVelocity(Vector v) {
	velocity = v;
}


Vector Animation::getVelocity() {
	return velocity;
}


void Animation::setAcceleration(Vector a) {
	acceleration = a;
}


Vector Animation::getAcceleration() {
	return acceleration;
}


void Animation::setRotation(Rotation r) {
	rotation = r;
}


Rotation Animation::getRotation() {
	return rotation;
}


void Animation::update()
{

}
