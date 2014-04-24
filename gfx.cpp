#include <assert.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include <iostream>
#include "gfx.h"
#include "point.h"

void set_pix(int x, int y, float r, float g, float b){
	glColor3f(r, g, b);
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
    return;
}

void draw_line(point_t p0, point_t p1){
	if(p0.getx()>p1.getx()){ draw_line(p1, p0); return; }
	int x;
	double dy = p1.gety() - p0.gety();
	double dx = p1.getx() - p0.getx();
	if(dx == 0) return;
	double m = dy/dx;
	double y = p0.gety();
	for(x = p0.getx(); x < p1.getx(); x++){
		set_pix(x, floor(y), 1.0, 1.0, 1.0);
		y += m;
		std::cout << x << ":" << y << std::endl;
	}
}
