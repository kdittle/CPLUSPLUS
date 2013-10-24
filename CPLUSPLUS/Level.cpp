#include "Level.h"

void Draw_Level()
{
	glLoadIdentity();

	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
		glVertex2f(0.0f, 590.0f);
		glVertex2f(800.0f, 590.0f);
		glVertex2f(800.0f, 600.0f);
		glVertex2f(0.0f, 600.0f);
	glEnd();

	glBegin(GL_QUADS);
		glVertex2f(750.0f, 520.0f);
		glVertex2f(800.0f, 520.0f);
		glVertex2f(800.0f, 530.0f);
		glVertex2f(750.0f, 530.0f);
	glEnd();

}