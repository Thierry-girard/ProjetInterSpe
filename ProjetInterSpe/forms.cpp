#include <cmath>
#include <SDL_opengl.h>
#include <GL/GLU.h>
#include "forms.h"


using namespace std;


Sphere::Sphere(Point c, double r, Color cl)
{
	position = c;
    radius = r;
	color = cl;
}


void Sphere::render()
{
    GLUquadric *quad;

    quad = gluNewQuadric();

	glRotated(rotation.x, 1, 0, 0);
	glRotated(rotation.y, 0, 1, 0);
	glTranslated(position.x, position.y, position.z);
	glColor3f(color.r, color.g, color.b);
	gluSphere(quad, radius, 10, 10);

    gluDeleteQuadric(quad);
}
