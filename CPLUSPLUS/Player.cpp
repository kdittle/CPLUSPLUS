#include "Player.h"
#include "Vector2f.h"

void Render_Player(Vector2f position)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	glTranslatef(position.x, position.y, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
		glVertex2f(-25.0f, -25.0f);
		glVertex2f(25.0f, -25.0f);
		glVertex2f(25.0f, 25.0f);
		glVertex2f(-25.0f, 25.0f);
	glEnd();
}