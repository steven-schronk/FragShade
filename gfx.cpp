#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include <iostream>
#include "gfx.h"

void set_pix(GLint x, GLint y, GLfloat r, GLfloat g, GLfloat b)
{
	glColor3f(r, g, b);
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
    return;
}
