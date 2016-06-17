#include "master.h"



Table::Table() : Table(Point(0, -1, 0), Size(100, 0, 190)) {

}


Table::Table(Point p, Size s) {
	position = p;
	size = s;

	unsigned short i;
	for (i = 0; i < NB_OF_BALLS; i++)
	{
		Color c;
		switch (i)
		{
		case 0:
			c = Color(1.0f, 1.0f, 1.0f);
			break;
		case 1:
		case 9:
			c = Color(1.0f, 0.8f, 0.0f);
			break;
		case 2:
		case 10:
			c = Color(0.2f, 0.2f, 1.0f);
			break;
		case 3:
		case 11:
			c = Color(1.0f, 0.2f, 0.2f);
			break;
		case 4:
		case 12:
			c = Color(0.0f, 0.0f, 0.5f);
			break;
		case 5:
		case 13:
			c = Color(1.0f, 0.5f, 0.0f);
			break;
		case 6:
		case 14:
			c = Color(0.2f, 0.5f, 0.2f);
			break;
		case 7:
		case 15:
			c = Color(0.8f, 0.0f, 0.0f);
			break;
		default:
			c = Color(0.0f, 0.0f, 0.0f);
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
		balls[i] = new Ball(i, c, p_ball);
	}

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



Cue Table::getCue() {
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


void Table::render() {
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

	unsigned short i = 0;
	for (i = 0; i < NB_OF_BALLS; i++)
	{
		if (balls[i] != NULL)
		{
			// Code de rendu de boules
			balls[i]->render();
		}
	}
}


void Table::setBalls(Ball* balls[NB_OF_BALLS]) {

}



void Table::setCushions(Cushion* cushions[NB_OF_CUSHIONS]) {

}



void Table::setHoles(Hole* halls[NB_OF_HOLES]) {

}


