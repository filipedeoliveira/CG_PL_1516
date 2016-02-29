#include <GL/glut.h>
#include <math.h>


void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if (h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f, ratio, 1.0f, 1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}

int xAngle = 0, yAngle = 0, zAngle = 0;

void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(0.0, 2.0, 5.0,
		0.0, 0.0, 0.0,
		0.0f, 1.0f, 0.0f);

	// put the geometric transformations here
	glutPostRedisplay();


	// put drawing instructions here

	//rotates
	glRotatef(xAngle, 1, 0, 0);
	glRotatef(yAngle, 0, 1, 0);
	glRotatef(zAngle, 0, 0, 1);
	

	//base 
	glColor3f(0, 1, 1);
	glBegin(GL_TRIANGLES);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(1.0f, 0.0f, -1.0f);
	glEnd();
	glColor3f(0, 1, 1);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glEnd();
	//face da frente
	glColor3f(1, 1, 0);
	glBegin(GL_TRIANGLES);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 1.5f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 1.0f);
	glEnd();
	//face da direita
	glColor3f(0, 0, 1);
	glBegin(GL_TRIANGLES);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, 1.5f, 0.0f);
	glEnd();
	//face de tras
	glColor3f(1, 0.5, 0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, 1.5f, 0.0f);
	glVertex3f(1.0f, 0.0f, -1.0f);

	glEnd();
	//face da esquerda
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 1.5f, 0.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glEnd();
	// End of frame



	// End of frame
	glutSwapBuffers();
}



// write function to process keyboard events
/* void rotate(unsigned char key, int c1, int c2) {
	switch (key) {
	case('q') :
		yAngle -= 30;
		break;
	case('e') :
		yAngle += 30;
		break;
	case('w') :
		xAngle += 30;
		break;
	case('s') :
		xAngle -= 30;
		break;
	case('a') :
		zAngle += 30;
		break;
	case('d') :
		zAngle -= 30;
		break;
	}
	glutPostRedisplay();
}*/
void rotate(int key, int c1, int c2) {
	switch (key) {
	case GLUT_KEY_UP :
		yAngle -= 30;
		break;
	case GLUT_KEY_DOWN:
		yAngle += 30;
		break;
	case('w') :
		xAngle += 30;
		break;
	case('s') :
		xAngle -= 30;
		break;
	case('a') :
		zAngle += 30;
		break;
	case('d') :
		zAngle -= 30;
		break;
	}
	glutPostRedisplay();
}


// write function to process menu events




int main(int argc, char **argv) {

	// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("CG@DI-UM");


	// Required callback registry 
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

	// put here the registration of the keyboard and menu callbacks
	glutSpecialFunc(rotate);


	// put here the definition of the menu 




	//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	// enter GLUT's main cycle
	glutMainLoop();

	return 1;
}
