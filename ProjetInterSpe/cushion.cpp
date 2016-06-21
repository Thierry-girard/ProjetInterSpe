#include "master.h"
#include <typeinfo>



Cushion::Cushion(GLchar* path) : Form(path)
{

}


Cushion::~Cushion()
{
}


void Cushion::setSize(Size s) {

}


Size Cushion::getSize() {
	return size;
}


void Cushion::setPosition(Point p) {

}


Point Cushion::getPosition() {
	return position;
}


void Cushion::setDirector(Vector d) {
	director = d;
}


Vector Cushion::getDirector() {
	return director;
}


void Cushion::setAbsCoeff(float c) {

}



float Cushion::getAbsCoeff() {
	return absorption_coeff;
}


void Cushion::render() {

}


void Cushion::update(Form* f) {
	if (typeid(f) == typeid(Ball)) {
		// TODO BAPTDUPR
	}
}
