#include "master.h"

#include <stdio.h>


Table::Table() : Table(Point(0, -1, 0), Size(100, 0, 190)) {

}


Table::Table(Point p, Size s) {
	position = p;
	size = s;

	unsigned short i;
	for (i = 0; i < 50; i++) {
		forms[i] = NULL;
	}







	for (i = 0; i < NB_OF_BALLS; i++)
	{
		GLchar* path = NULL;
		switch (i)
		{
		case 0:
			path = "../ProjetInterSpe/resources/Ball0.jpg";
			break;
		case 1:
			path = "../ProjetInterSpe/resources/Ball1.jpg";
			break;
		case 2:
			path = "../ProjetInterSpe/resources/Ball2.jpg";
			break;
		case 3:
			path = "../ProjetInterSpe/resources/Ball3.jpg";
			break;
		case 4:
			path = "../ProjetInterSpe/resources/Ball4.jpg";
			break;
		case 5:
			path = "../ProjetInterSpe/resources/Ball5.jpg";
			break;
		case 6:
			path = "../ProjetInterSpe/resources/Ball6.jpg";
			break;
		case 7:
			path = "../ProjetInterSpe/resources/Ball7.jpg";
			break;
		case 8:
			path = "../ProjetInterSpe/resources/Ball8.jpg";
			break;
		case 9:
			path = "../ProjetInterSpe/resources/Ball9.jpg";
			break;
		case 10:
			path = "../ProjetInterSpe/resources/Ball10.jpg";
			break;
		case 11:
			path = "../ProjetInterSpe/resources/Ball11.jpg";
			break;
		case 12:
			path = "../ProjetInterSpe/resources/Ball12.jpg";
			break;
		case 13:
			path = "../ProjetInterSpe/resources/Ball13.jpg";
			break;
		case 14:
			path = "../ProjetInterSpe/resources/Ball14.jpg";
			break;
		case 15:
			path = "../ProjetInterSpe/resources/Ball15.jpg";
			break;
		default:
			path = NULL;
			break;
		}
		Point p_ball = Point(0, 3, 0);
		if (i == 0)
			p_ball = Point(size.x / 2, 3, 3 * size.z / 4);
		else if (i == 8)
			p_ball = Point(size.x / 2, 3, size.z / 4);
		else
		{
			if (i < 8)
				p_ball = Point(20, p_ball.y, 10 * i);
			else
				p_ball = Point(80, p_ball.y, -80 + 10 * i);
		}
		Ball* b = new Ball(i, path);
		if (i != 0)
			b->setAnim(Animation(p_ball, Vector(0, 0, 0), Vector(0, 0, 0), Rotation(0, 0)));
		else
			b->setAnim(Animation(p_ball, Vector(1, 0, 1), Vector(0, 0, 0), Rotation(0, 0)));

		addForm(b);
	}

	for (i = 0; i < NB_OF_CUSHIONS; i++)
	{
		// TODO
	}


	for (i = 0; i < NB_OF_HOLES; i++)
	{
		// TODO
	}

	double rayon_trou;
	double X1_trou, Z1_trou;
	double X2_trou, Z2_trou;
	double X3_trou, Z3_trou;
	double X4_trou, Z4_trou;
	double X5_trou, Z5_trou;
	double X6_trou, Z6_trou;

	rayon_trou = Ball::DEFAULT_RADIUS+2;

	X1_trou = position.x;
	Z1_trou = 0;
	X2_trou = position.x;
	Z2_trou = size.z / 2;
	X3_trou = position.x;
	Z3_trou = size.z;

	X4_trou = position.x + size.x;
	Z4_trou = 0;
	X5_trou = position.x + size.x;
	Z5_trou = size.z / 2;
	X6_trou = position.x + size.x;
	Z6_trou = size.z;

	addForm(new Hole(Point(X1_trou, 0, Z1_trou), rayon_trou));
	addForm(new Hole(Point(X2_trou, 0, Z2_trou), rayon_trou));
	addForm(new Hole(Point(X3_trou, 0, Z3_trou), rayon_trou));
	addForm(new Hole(Point(X4_trou, 0, Z4_trou), rayon_trou));
	addForm(new Hole(Point(X5_trou, 0, Z5_trou), rayon_trou));
	addForm(new Hole(Point(X6_trou, 0, Z6_trou), rayon_trou));
}


Table::~Table() {

}


void Table::setFrictionCoeff(float c) {

}


float Table::getFricCoeff() {
	return friction_coeff;
}


void Table::setSize(Size s) {

}


Size Table::getSize() {
	return size;
}



/*void Table::setCue() {

}



Cue* Table::getCue() {
	return cue;
}



void Table::addBall(Ball b) {

}



void Table::removeBall(Ball b) {

}



void Table::clearBalls() {

}



Ball** Table::getBalls() {
	return balls;
}



void Table::addCushion(Cushion c) {

}



void Table::clearCushions() {

}



Cushion** Table::getCushions() {
	return cushions;
}



void Table::addForm(new Hole(Hole h) {

}

void Table::addHole(Point P, double radius) {
	unsigned int i = 0);
	bool stop = false;

	for (i = 0; i < NB_OF_HOLES && stop == false; i++) {
		if (holes[i] == NULL) {

			holes[i] = new Hole;

			holes[i]->position = P;
			holes[i]->radius = radius;

			stop = true;
		}
	}
}



void Table::clearHoles() {

}



Hole** Table::getHole() {
	return holes;
}*/


void Table::render() { // calcul du rendu graphique
	glBegin(GL_QUADS); // TABLE
	{
		// Front
		glColor3d(0, 1, 0);
		glVertex3d(position.x, position.y, position.z);
		glColor3d(0, 1, 0);
		glVertex3d(position.x, position.y, position.z);
		glColor3d(0, 1, 0);
		glVertex3d(position.x + size.x, position.y + size.y, position.z);
		glColor3d(0, 1, 0);
		glVertex3d(position.x, position.y + size.y, position.z);

		// Back
		glColor3d(0, 1, 0);
		glVertex3d(position.x, position.y, position.z + size.z);
		glColor3d(0, 1, 0);
		glVertex3d(position.x + size.x, position.y, position.z + size.z);
		glColor3d(0, 1, 0);
		glVertex3d(position.x + size.x, position.y + size.y, position.z + size.z);
		glColor3d(0, 1, 0);
		glVertex3d(position.x, position.y + size.y, position.z + size.z);

		// Top
		glColor3d(0, 1, 0);
		glVertex3d(position.x, position.y, position.z + size.z);
		glColor3d(0, 1, 0);
		glVertex3d(position.x + size.x, position.y, position.z + size.z);
		glColor3d(0, 1, 0);
		glVertex3d(position.x + size.x, position.y, position.z);
		glColor3d(0, 1, 0);
		glVertex3d(position.x, position.y, position.z);

		// Bot
		glColor3d(0, 1, 0);
		glVertex3d(position.x, position.y + size.y, position.z + size.z);
		glColor3d(0, 1, 0);
		glVertex3d(position.x + size.x, position.y + size.y, position.z + size.z);
		glColor3d(0, 1, 0);
		glVertex3d(position.x + size.x, position.y + size.y, position.z);
		glColor3d(0, 1, 0);
		glVertex3d(position.x, position.y + size.y, position.z);

		// Left
		glColor3d(0, 1, 0);
		glVertex3d(position.x, position.y, position.z);
		glColor3d(0, 1, 0);
		glVertex3d(position.x, position.y, position.z + size.z);
		glColor3d(0, 1, 0);
		glVertex3d(position.x, position.y + size.y, position.z + size.z);
		glColor3d(0, 1, 0);
		glVertex3d(position.x, position.y + size.y, position.z);

		// Right
		glColor3d(0, 1, 0);
		glVertex3d(position.x + size.x, position.y, position.z);
		glColor3d(0, 1, 0);
		glVertex3d(position.x + size.x, position.y, position.z + size.z);
		glColor3d(0, 1, 0);
		glVertex3d(position.x + size.x, position.y + size.y, position.z + size.z);
		glColor3d(0, 1, 0);
		glVertex3d(position.x + size.x, position.y + size.y, position.z);
	}
	glEnd();

	glBegin(GL_QUADS); // BORD GAUCHE
	{
		Point p1 = Point(position.x - 5, position.y, position.z);
		Point p2 = Point(position.x, position.y + size.y + 2, position.z + size.z);

		// Front
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p1.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p1.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p2.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p2.y, p1.z);

		// Back
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p1.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p1.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p2.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p2.y, p2.z);

		// Top
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p1.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p1.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p1.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p1.y, p1.z);

		// Bot
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p2.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p2.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p2.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p2.y, p1.z);

		// Left
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p1.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p1.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p2.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p2.y, p1.z);

		// Right
		glColor3d(0, 0.2, 0);
		glVertex3d(p2.x, p1.y, p1.z);
		glColor3d(0, 0.2, 0);
		glVertex3d(p2.x, p1.y, p2.z);
		glColor3d(0, 0.2, 0);
		glVertex3d(p2.x, p2.y, p2.z);
		glColor3d(0, 0.2, 0);
		glVertex3d(p2.x, p2.y, p1.z);
	}
	glEnd();

	glBegin(GL_QUADS); // BORD DROIT
	{
		Point p1 = Point(position.x + size.x, position.y, position.z);
		Point p2 = Point(position.x + size.x + 5, position.y + size.y + 2, position.z + size.z);

		// Front
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p1.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p1.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p2.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p2.y, p1.z);

		// Back
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p1.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p1.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p2.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p2.y, p2.z);

		// Top
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p1.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p1.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p1.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p1.y, p1.z);

		// Bot
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p2.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p2.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p2.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p2.y, p1.z);

		// Left
		glColor3d(0, 0.2, 0);
		glVertex3d(p1.x, p1.y, p1.z);
		glColor3d(0, 0.2, 0);
		glVertex3d(p1.x, p1.y, p2.z);
		glColor3d(0, 0.2, 0);
		glVertex3d(p1.x, p2.y, p2.z);
		glColor3d(0, 0.2, 0);
		glVertex3d(p1.x, p2.y, p1.z);

		// Right
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p1.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p1.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p2.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p2.y, p1.z);
	}
	glEnd();

	glBegin(GL_QUADS); // BORD AVANT
	{
		Point p1 = Point(position.x - 5, position.y, position.z - 5);
		Point p2 = Point(position.x + size.x + 5, position.y + size.y + 2, position.z);

		// Front
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p1.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p1.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p2.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p2.y, p1.z);

		// Back
		glColor3d(0, 0.2, 0);
		glVertex3d(p1.x, p1.y, p2.z);
		glColor3d(0, 0.2, 0);
		glVertex3d(p2.x, p1.y, p2.z);
		glColor3d(0, 0.2, 0);
		glVertex3d(p2.x, p2.y, p2.z);
		glColor3d(0, 0.2, 0);
		glVertex3d(p1.x, p2.y, p2.z);

		// Top
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p1.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p1.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p1.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p1.y, p1.z);

		// Bot
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p2.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p2.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p2.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p2.y, p1.z);

		// Left
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p1.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p1.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p2.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p2.y, p1.z);

		// Right
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p1.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p1.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p2.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p2.y, p1.z);
	}
	glEnd();

	glBegin(GL_QUADS); // BORD ARRIERE
	{
		Point p1 = Point(position.x - 5, position.y, position.z + size.z);
		Point p2 = Point(position.x + size.x + 5, position.y + size.y + 2, position.z + size.z + 5);

		// Front
		glColor3d(0, 0.2, 0);
		glVertex3d(p1.x, p1.y, p1.z);
		glColor3d(0, 0.2, 0);
		glVertex3d(p2.x, p1.y, p1.z);
		glColor3d(0, 0.2, 0);
		glVertex3d(p2.x, p2.y, p1.z);
		glColor3d(0, 0.2, 0);
		glVertex3d(p1.x, p2.y, p1.z);

		// Back
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p1.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p1.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p2.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p2.y, p2.z);

		// Top
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p1.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p1.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p1.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p1.y, p1.z);

		// Bot
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p2.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p2.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p2.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p2.y, p1.z);

		// Left
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p1.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p1.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p2.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p1.x, p2.y, p1.z);

		// Right
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p1.y, p1.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p1.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p2.y, p2.z);
		glColor3d(0, 0.5, 0);
		glVertex3d(p2.x, p2.y, p1.z);
	}
	glEnd();

	//Ajout des pieds

	glColor3d(0.52, 0.37, 0.26);
	//pied haut gauche
	glPushMatrix();
		GLUquadric *quad = gluNewQuadric();
		GLUquadric *quadp = gluNewQuadric();
		glTranslated(position.x+9, position.y, position.z+9);
		glRotated(90, 1, 0, 0);
		gluCylinder(quad,9, 7, 70,100, 100);
		glTranslated(0, 0, 70);
		gluDisk(quadp, 0, 7, 100, 100);
		gluDeleteQuadric(quad);
		gluDeleteQuadric(quadp);
	glPopMatrix();
	//pied haut droit
	glPushMatrix();
		quad = gluNewQuadric();
		quadp = gluNewQuadric();
		glTranslated(position.x + size.x - 9, position.y, position.z + 9);
		glRotated(90, 1, 0, 0);
		gluCylinder(quad, 9, 7, 70, 100, 100);
		glTranslated(0, 0, 70);
		gluDisk(quadp, 0, 7, 100, 100);
		gluDeleteQuadric(quad);
		gluDeleteQuadric(quadp);
	glPopMatrix();
	////pied bas gauche
	glPushMatrix();
		quad = gluNewQuadric();
		quadp = gluNewQuadric();
		glTranslated(position.x + 9, position.y, position.z + size.z - 9);
		glRotated(90, 1, 0, 0);
		gluCylinder(quad, 9, 7, 70, 100, 100);
		glTranslated(0, 0, 70);
		gluDisk(quadp, 0, 7, 100, 100);
		gluDeleteQuadric(quad);
		gluDeleteQuadric(quadp);
	glPopMatrix();
	////pied bas droit
	glPushMatrix();
		quad = gluNewQuadric();
		quadp = gluNewQuadric();
		glTranslated(position.x + size.x - 9, position.y, position.z + size.z - 9);
		glRotated(90, 1, 0, 0);
		gluCylinder(quad, 9, 7, 70, 100, 100);
		glTranslated(0, 0, 70);
		gluDisk(quadp, 0, 7, 100, 100);
		gluDeleteQuadric(quad);
		gluDeleteQuadric(quadp);
	glPopMatrix();

	




	glColor3d(1, 1, 1);

	unsigned short i = 0;
	for (i = 0; i < 50; i++)
	{
		if (forms[i] != NULL)
		{
			forms[i]->render();
		}
	}
}


void Table::update(Form* h) { // calcul des éléments physiques
	unsigned short i = 0;
	unsigned short j = 0;

	Vector Vector_tmp;

	for (i = 0; i < 50; i++)
	{
		if (forms[i] != NULL)
		{
			// Ce qu'il faut réaliser :
			// - Collisions entre les rebords
			// - Collisions entre les balles
			// - Verifier la position de la balle par rapport aux trous.
			// - Actualiser la position & la vitesse de la balle.

			// Verification position Ball & Trous
			for (j = i + 1; j < 50; j++) {
				if (forms[j] != NULL) {
					forms[i]->update(forms[j]);
				}
			}

			Animation a = forms[i]->getAnim();
			a.setPosition(Point(forms[i]->getAnim().getPosition().x + forms[i]->getAnim().getVelocity().x, forms[i]->getAnim().getPosition().y + forms[i]->getAnim().getVelocity().y, forms[i]->getAnim().getPosition().z + forms[i]->getAnim().getVelocity().z));
			forms[i]->setAnim(a);
		}
	}
}



Form** Table::getForms() {
	return forms;
}


int Table::addForm(Form* f) {
	unsigned int i = 0;

	for (i = 0; i < 50; i++) {
		if (forms[i] == NULL) {
			forms[i] = f;
			return 0;
		}
	}

	return -1;
}


void Table::removeForm(Form* f) {
	// TODO
}


void Table::clearForms() {
	// TODO
}


void Table::setBalls(Ball* balls[NB_OF_BALLS]) {

}



void Table::setCushions(Cushion* cushions[NB_OF_CUSHIONS]) {

}



void Table::setHoles(Hole* halls[NB_OF_HOLES]) {

}
