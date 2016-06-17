#pragma once

#include "geometry.h"
#include "math.h"

#define PI 3.14159265358979323846

class Animation
{
private:
    double angle;
    Rotation rot_vect;

public:
	Animation(double agl = 0.0, Rotation vect = Rotation(1, 0, 0)) { angle = agl; rot_vect = vect; }
    const double getAngle() {return angle;}
    void setAngle(double agl) {angle = agl;}
    const Rotation getRotVect() {return rot_vect;}
    void setRotVect(Rotation vect) {rot_vect = vect;}
    void update();
};
