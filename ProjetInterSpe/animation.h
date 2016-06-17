#pragma once

#include "geometry.h"
#include "math.h"

#define PI 3.14159265358979323846

class Animation
{
private:
    double angle;
	double angle_incr;
    Vector rot_vect;

public:
	Animation(double agl = 0.0, double aglinc = PI / 12, Vector vect = Vector(1.0, 0.0, 0.0)) { angle = agl; rot_vect = vect; angle_incr = aglinc; }
    const double getAngle() {return angle;}
    void setAngle(double agl) {angle = agl;}
	/*const double getAngleIncr() { return angle_incr; }
	void setAngleIncr(double aglinc) { angle_incr = aglinc; }*/
    const Vector getRotVect() {return rot_vect;}
    void setRotVect(Vector vect) {rot_vect = vect;}
    void update();
};
