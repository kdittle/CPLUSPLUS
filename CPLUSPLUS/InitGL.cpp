#include "InitGL.h"

void Initialize_glDisplay()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, WINDOW_WIDTH, WINDOW_HEIGHT, 0.0, 1.0, -1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

}

void Update()
{

}

void Render(float xPos, float yPos)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(xPos, yPos, 0.0f);

	glBegin(GL_QUADS);
		glVertex2f(-10.0f, -10.0f);
		glVertex2f(10.0f, -10.0f);
		glVertex2f(10.0f, 10.0f);
		glVertex2f(-10.0f, 10.0f);
	glEnd();

}