#include "master.h"

#include <stdio.h>


Table::Table() : Table(Point(0, -1, 0), Size(100, 0, 190)) {

}


Table::Table(Point p, Size s) {
	position = p;
	size = s;

	unsigned short i;
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
		balls[i] = new Ball(i, p_ball, path);
	}

	balls[0]->setShift(Vector(1, 0, 1));

	for (i = 0; i < NB_OF_CUSHIONS; i++)
	{
		cushions[i] = NULL;
	}

	for (i = 0; i < NB_OF_HOLES; i++)
	{
		holes[i] = NULL;
	}
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



void Table::setCue() {

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



void Table::addHole(Hole h) {

}



void Table::clearHoles() {

}



Hole** Table::getHole() {
	return holes;
}


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

	glColor3d(1, 1, 1);

	unsigned short i = 0;
	for (i = 0; i < NB_OF_BALLS; i++)
	{
		if (balls[i] != NULL)
		{
			balls[i]->render();
		}
	}
}


void Table::update() { // calcul des éléments physiques
	unsigned short i = 0;
	unsigned short j = 0;

	Vector Vector_tmp;

	for (i = 0; i < NB_OF_BALLS; i++)
	{
		if (balls[i] != NULL)
		{
		    // Ce qu'il faut réaliser :
            // - Collisions entre les rebords
            // - Collisions entre les balles
            // - Verifier la position de la balle par rapport aux trous.
            // - Actualiser la position & la vitesse de la balle.

            // Verification position Ball & Trous
            for (j = 0; j < NB_OF_HOLES; j++) {
                if (holes[j] != NULL) {
                    if (distance(holes[j]->position, balls[i]->getPosition()) < balls[i]->getRadius()) {
                        //removeBall(balls[i]);
                    }
                }
            }
            // --

            // Gestion des rebonds balles / balles
            	for (j = 0; j < NB_OF_BALLS; j++) {
                    if (balls[j] != NULL && i != j) {
                        if (distance(balls[i]->getPosition(), balls[j]->getPosition()) < 2*balls[i]->getRadius()) {
                            // Vector_tmp = balls[i]->getShift();
                            // balls[j]->setShift(Vector(Vector_tmp.x, 0, Vector_tmp.z));

                            Vector_tmp = Vector(balls[i]->getPosition(), balls[j]->getPosition());
                            balls[j]->setShift(0.2*Vector_tmp);
                        }
                    }
            	}


            // Gestion des rebonds balles / rebords
            if (balls[i]->getPosition().x + balls[i]->getRadius() > size.x) {
                Vector_tmp = balls[i]->getShift();
                balls[i]->setShift(Vector(-Vector_tmp.x, 0, Vector_tmp.z));
            }

            else if (balls[i]->getPosition().x - balls[i]->getRadius() < 0) {
                Vector_tmp = balls[i]->getShift();
                balls[i]->setShift(Vector(-Vector_tmp.x, 0, Vector_tmp.z));
            }

            else if (balls[i]->getPosition().z + balls[i]->getRadius() > size.z) {
                Vector_tmp = balls[i]->getShift();
                balls[i]->setShift(Vector(Vector_tmp.x, 0, -Vector_tmp.z));
            }

            else if (balls[i]->getPosition().z - balls[i]->getRadius() < 0) {
                Vector_tmp = balls[i]->getShift();
                balls[i]->setShift(Vector(Vector_tmp.x, 0, -Vector_tmp.z));
            }
            // --

            balls[i]->setPosition(Point(balls[i]->getPosition().x + balls[i]->getShift().x, balls[i]->getPosition().y + balls[i]->getShift().y, balls[i]->getPosition().z + balls[i]->getShift().z));

		}
	}
}


void Table::setBalls(Ball* balls[NB_OF_BALLS]) {

}



void Table::setCushions(Cushion* cushions[NB_OF_CUSHIONS]) {

}



void Table::setHoles(Hole* halls[NB_OF_HOLES]) {

}


