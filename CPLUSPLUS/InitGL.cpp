#include "InitGL.h"
#include "Level.h"

void Initialize_glDisplay()
{
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, WINDOW_WIDTH, WINDOW_HEIGHT, 0.0);

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

	glPushMatrix();

	glLoadIdentity();

	glTranslatef(xPos, yPos, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
		glVertex2f(-25.0f, -25.0f);
		glVertex2f(25.0f, -25.0f);
		glVertex2f(25.0f, 25.0f);
		glVertex2f(-25.0f, 25.0f);
	glEnd();

	glPopMatrix();

	//push matrix to draw level
	glPushMatrix();

	Draw_Level();

	glPopMatrix();

}