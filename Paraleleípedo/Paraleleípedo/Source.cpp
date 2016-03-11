#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>


int xAngle = 0, yAngle = 0, zAngle = 0;
int x = 0, y = 0, z = 0;

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
void drawParallelepiped( float largura, float altura, float comprimento) {
			float x = largura / 2, y = altura / 2, z = comprimento / 2;

	glTranslatef(x, y, z);
	glRotatef(xAngle, 1, 0, 0);
	glRotatef(yAngle, 0, 1, 0);
	glRotatef(zAngle, 0, 0, 1);

	glBegin(GL_TRIANGLES);

		//base inferior
		//glColor3f(0, 0, 1);
		glVertex3f(-x, 0, 0);
		glVertex3f(0, 0, -z);
		glVertex3f(0, 0, z);
		glVertex3f(0, 0, z);
		glVertex3f(0, 0, -z);
		glVertex3f(x, 0, 0);
		//frente
		glColor3f(1, 0, 0);
		glVertex3f(x, 0, 0);
		glVertex3f(x, y, 0);
		glVertex3f(0, y, z);
		glVertex3f(x, 0, 0);
		glVertex3f(0, y, z);
		glVertex3f(0, 0, z);
		//tras
	 	glColor3f(2, 1, 0);
		glVertex3f(-x, 0, 0);
		glVertex3f(-x, y, 0);
		glVertex3f(0, 0, -z);
		glVertex3f(-x, y, 0);
		glVertex3f(0, y, -z);
		glVertex3f(0, 0, -z);
		//esquerda
     	glColor3f(1, 0.5, 0);
		glVertex3f(-x, 0, 0);
		glVertex3f(0, 0, z);
		glVertex3f(0, y, z);
		glVertex3f(0, y, z);
		glVertex3f(-x, y, 0);
		glVertex3f(-x, 0, 0);
		//direita
	    glColor3f(1, 1, 1);
		glVertex3f(x, 0, 0);
		glVertex3f(0, 0, -z);
		glVertex3f(x, y, 0);
		glVertex3f(0, 0, -z);
		glVertex3f(0, y, -z);
		glVertex3f(x, y, 0);
		//base superior
		glColor3f(0.0, 0.5, 0.0);
		glVertex3f(x, y, 0);
		glVertex3f(0, y, -z);
		glVertex3f(0, y, z);
		glVertex3f(0, y, z);
		glVertex3f(0, y, -z);
		glVertex3f(-x, y, 0);
		glEnd();
/*

		//Lateral
		//Triangulos laterais Inferiores. 
		glColor3f(0, 1, 0); //VERDE
		glVertex3f(raio*sin(angulo), 0.0, raio*cos(angulo));
		glVertex3f(raio*sin(angulo + alfa), 0.0, raio*cos(angulo + alfa));
		glVertex3f(raio*sin(angulo + alfa), altura, raio*cos(angulo + alfa));

		//Triangulos laterais Superiores
		glColor3f(1, 0, 0); //Laranja
		glVertex3f(raio*sin(angulo + alfa), altura, raio*cos(angulo + alfa));
		glVertex3f(raio*sin(angulo), altura, raio*cos(angulo));
		glVertex3f(raio*sin(angulo), 0.0, raio*cos(angulo));

		//base de cima
		glColor3f(0, 1, 0); //VERDE
		glVertex3f(raio*sin(angulo), altura, raio*cos(angulo));
		glVertex3f(raio*sin(angulo + alfa), altura, raio*cos(angulo + alfa));
		glVertex3f(0.0, altura, 0.0);

		angulo += alfa;

	}*/
	


}


void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(0.0, 5.0, 10.0,
		0.0, 1.0, 0.0,
		0.0f, 1.0f, 0.0f);

	// put the geometric transformations here
	drawParallelepiped(1.0, 2.0, 1.0);

	// put drawing instructions here


	// End of frame
	glutSwapBuffers();
}



// write function to process keyboard events
void rodar(unsigned char key, int x, int y) {
	switch (key)
	{
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
}

void mover(int key, int c1, int c2) {
	switch (key)
	{
	case(GLUT_KEY_LEFT) :
		x--;
		break;
	case(GLUT_KEY_RIGHT) :
		x++;
		break;
	case(GLUT_KEY_UP) :
		z--;
		break;
	case(GLUT_KEY_DOWN) :
		z++;
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
	glutKeyboardFunc(rodar);
	glutSpecialFunc(mover);


	// put here the definition of the menu 




	//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	// enter GLUT's main cycle
	glutMainLoop();

	return 1;
}
