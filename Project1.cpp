#include <GL/glut.h>
#include <GL/GLU.h>
#include <GL/GL.h>
#define WIDTH 400
#define HEIGHT 400

GLboolean IsWire = true;
GLboolean IsSolid = true;
int ViewX = 0, ViewY = 0;				// 마우스 움직임에 따라 시점을 바꾸기 위한 변수

void InitLight()
{
	GLfloat mat_diffuse[] = { 0.5,0.4,0.3,1.0 };
	GLfloat mat_specular[] = { 1.0,1.0,1.0,1.0 };
	GLfloat mat_ambient[] = { 0.5,0.4,0.3,1.0 };
	GLfloat mat_shininess[] = { 15.0 };

	GLfloat light_specular[] = { 1.0,1.0,1.0,1.0 };
	GLfloat light_diffuse[] = { 0.8,0.8,0.8,1.0 };
	GLfloat light_ambient[] = { 0.3,0.3,0.3,1.0 };
	GLfloat light_position[] = { -3,6,3.0,0.0 };

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void MyMouseMove(GLint X, GLint Y)
{
	ViewX = X;
	ViewY = Y;
	glutPostRedisplay();
}

void MyDisplay()
{
	int X = ((ViewX) - (WIDTH / 2));
	int Y = -((ViewY) - (HEIGHT / 2));
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0, 0.0, 0.0, X, Y, -1.0, 0.0, 1.0, 0.0);


	if (IsWire)
	{
		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(0.0, 0.57, 0.0);
		glutWireTeapot(0.15);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(0.3, 0.2, 0.175);
		glScalef(1.0, 8.0, 1.0);
		glutWireCube(0.05);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(-0.3, 0.2, 0.175);
		glScalef(1.0, 8.0, 1.0);
		glutWireCube(0.05);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(-0.3, 0.2, -0.175);
		glScalef(1.0, 8.0, 1.0);
		glutWireCube(0.05);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(-0.3, 0.2, -0.175);
		glScalef(1.0, 8.0, 1.0);
		glutWireCube(0.05);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(0.3, 0.2, -0.175);
		glScalef(1.0, 8.0, 1.0);
		glutWireCube(0.05);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(0.0, 0.37, 0.0);
		glScalef(13.0, 2.0, 8.0);
		glutWireCube(0.05);
		glPopMatrix();

	}
	else
	{
		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(0.0, 0.57, 0.0);
		glutSolidTeapot(0.15);
		glPopMatrix();


		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(0.3, 0.2, 0.175);
		glScalef(1.0, 8.0, 1.0);
		glutSolidCube(0.05);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(-0.3, 0.2, 0.175);
		glScalef(1.0, 8.0, 1.0);
		glutSolidCube(0.05);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(-0.3, 0.2, -0.175);
		glScalef(1.0, 8.0, 1.0);
		glutSolidCube(0.05);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(-0.3, 0.2, -0.175);
		glScalef(1.0, 8.0, 1.0);
		glutSolidCube(0.05);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(0.3, 0.2, -0.175);
		glScalef(1.0, 8.0, 1.0);
		glutSolidCube(0.05);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(0.0, 0.37, 0.0);
		glScalef(13.0, 2.0, 8.0);
		glutSolidCube(0.05);
		glPopMatrix();
	}
	if (IsSolid)
	{
		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(0.0, 0.57, 0.0);
		glutSolidTeapot(0.15);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(0.3, 0.2, 0.175);
		glScalef(1.0, 8.0, 1.0);
		glutSolidCube(0.05);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(-0.3, 0.2, 0.175);
		glScalef(1.0, 8.0, 1.0);
		glutSolidCube(0.05);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(-0.3, 0.2, -0.175);
		glScalef(1.0, 8.0, 1.0);
		glutSolidCube(0.05);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(-0.3, 0.2, -0.175);
		glScalef(1.0, 8.0, 1.0);
		glutSolidCube(0.05);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(0.3, 0.2, -0.175);
		glScalef(1.0, 8.0, 1.0);
		glutSolidCube(0.05);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(0.0, 0.37, 0.0);
		glScalef(13.0, 2.0, 8.0);
		glutSolidCube(0.05);
		glPopMatrix();

	}
	else
	{
		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(0.0, 0.57, 0.0);
		glutWireTeapot(0.15);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(0.3, 0.2, 0.175);
		glScalef(1.0, 8.0, 1.0);
		glutWireCube(0.05);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(-0.3, 0.2, 0.175);
		glScalef(1.0, 8.0, 1.0);
		glutWireCube(0.05);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(-0.3, 0.2, -0.175);
		glScalef(1.0, 8.0, 1.0);
		glutWireCube(0.05);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(-0.3, 0.2, -0.175);
		glScalef(1.0, 8.0, 1.0);
		glutWireCube(0.05);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(0.3, 0.2, -0.175);
		glScalef(1.0, 8.0, 1.0);
		glutWireCube(0.05);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0.0, -0.38);
		glTranslatef(0.0, 0.37, 0.0);
		glScalef(13.0, 2.0, 8.0);
		glutWireCube(0.05);
		glPopMatrix();
	}

	glFlush();
}

void MyKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case'q':
	case 'Q':
		exit(0);
		break;
	case 's':
	case 'S':
		IsSolid = true;
		IsWire = false;
		glutPostRedisplay();
		break;
	case 'w':
	case'W':
		IsSolid = false;
		IsWire = true;
		glutPostRedisplay();
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("PROJCET 1/4");
	glClearColor(0.4, 0.4, 0.4, 0.0);
	InitLight();

	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);		//??
	glutPassiveMotionFunc(MyMouseMove);

	glutMainLoop();
}
