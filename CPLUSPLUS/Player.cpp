#include "Player.h"

void Render_Player(float xPos, float yPos)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	glTranslatef(xPos, yPos, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
		glVertex2f(-25.0f, -25.0f);
		glVertex2f(25.0f, -25.0f);
		glVertex2f(25.0f, 25.0f);
		glVertex2f(-25.0f, 25.0f);
	glEnd();
}