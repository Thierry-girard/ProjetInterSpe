#include <cmath>
#include <SDL_opengl.h>
#include <GL/GLU.h>
#include "forms.h"


using namespace std;


Sphere::Sphere(Point c, double r, Color cl)
{
    center = c;
    radius = r;
    col = cl;
}


void Sphere::render()
{
    GLUquadric *quad;

    quad = gluNewQuadric();

	glRotated(anim.getAngle(), anim.getRotVect().x, anim.getRotVect().y, anim.getRotVect().z);
	glTranslated(center.x, center.y, center.z);
	glColor3f(col.r, col.g, col.b);
	gluSphere(quad, radius, 10, 10);

    gluDeleteQuadric(quad);
}
