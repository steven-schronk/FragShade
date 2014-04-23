#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include <iostream>
#include "gfx.h"

void set_pix(int x, int y, float r, float g, float b)
{
	glColor3f(r, g, b);
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
    return;
}
