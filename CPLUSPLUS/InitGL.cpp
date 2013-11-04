#include "InitGL.h"
#include "Level.h"
#include "Player.h"
#include "Vector2f.h"

void Initialize_glDisplay()
{
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, WINDOW_WIDTH, WINDOW_HEIGHT, 0.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

}

void Update(Vector2f position)
{
	glPushMatrix();

	Render_Player(position);

	glPopMatrix();

	glPushMatrix();

	Draw_Level();

	glPopMatrix();
}