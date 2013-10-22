#ifndef INITGL_H
#define INITGL_H

#include "OpenGLHeaders.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int SCREEN_FPS = 60;

void Initialize_glDisplay();

void Update();

void Render(float xPos, float yPos);

#endif