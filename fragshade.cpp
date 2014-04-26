#include <assert.h>
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

#include "gfx.h"
#include "point.h"
#include "polygon.h"

void display(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	point_t p1(29.0, 118.0);
	point_t p2(250.0, 15.0);
	point_t p3(200.0, 170.0);

	point_t p4(0.0, 300.0);
	point_t p5(300.0, 300.0);

	//draw_edge(p4, p5);

	polygon_t poly, polyx;
	poly.add_point(p1);
	poly.add_point(p2);
	poly.add_point(p3);

	poly.draw_polygon();
	poly.draw_filled_polygon();

	p1.draw_point();
	p2.draw_point();
	p3.draw_point();

	//draw_edge(p1, p2);
	//draw_edge(p2, p3);
	//draw_edge(p3, p1);

	point_t pa(600.0, 600.0);
	point_t pb(600.0, 700.0);
	point_t pc(700.0, 600.0);
	point_t pd(700.0, 700.0);
	polyx.add_point(pa);
	polyx.add_point(pb);
	polyx.add_point(pc);
	polyx.add_point(pd);

	polyx.draw_filled_polygon();
	pa.draw_point();
	pb.draw_point();
	pc.draw_point();
	pd.draw_point();


	//set_pix(1, 1, 1.0, 0.0, 1.0);
	//set_pix(100, 100, 0.0, 1.0, 0.0);
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
	key = tolower(key);
	printf("Keypress: %c\n", key);
	switch (key){
	case 'q':
		exit(0);
		break;
	case 27:
		exit(0);
		break;
	}
	display();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(0,0);
	glutCreateWindow("FragShade");
	//glutFullScreen();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho( 0.0, WINDOW_WIDTH,WINDOW_HEIGHT, 0.0, -1.0, 1.0 );
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
