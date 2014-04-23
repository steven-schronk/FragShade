#include <assert.h>
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "gfx.h"

void display(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	set_pix(1, 1, 1.0, 0.0, 1.0);
	set_pix(100, 100, 0.0, 1.0, 0.0);
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
