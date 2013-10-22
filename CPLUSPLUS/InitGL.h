#ifndef INITGL_H
#define INITGL_H

#include "OpenGLHeaders.h"

const float WINDOW_WIDTH = 800.0;
const float WINDOW_HEIGHT = 600.0;
const int SCREEN_FPS = 60;

void Initialize_glDisplay();

void Update();

void Render(float xPos, float yPos);

#endif