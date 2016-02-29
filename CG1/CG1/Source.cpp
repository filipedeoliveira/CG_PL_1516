#include <stdlib.h>
#include <GL/glut.h>


#define _USE_MATH_DEFINES
#include <math.h>

void renderScene(void) {
	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// set camera
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 5.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 1.0f, 0.0f);
	// put drawing instructions here
	// End of frame
	glutSwapBuffers();
}

int main(int argc, char **argv) {

	// put GLUT’s init here
	// put callback registry here
	// some OpenGL settings

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// enter GLUT’s main cycle

	glutMainLoop();

	return 1;
}

