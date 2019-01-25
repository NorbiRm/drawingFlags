/*
 * Sergio Ruiz.
 *
 * TC3022. Computer Graphics Course.
 * Basic template OpenGL project.
 */

// Please don't change lines 9-31 (It helps me to grade)
#ifdef __APPLE__
// For XCode only: New C++ terminal project. Build phases->Compile with libraries: add OpenGL and GLUT
// Import this whole code into a new C++ file (main.cpp, for example). Then run.
// Reference: https://en.wikibooks.org/wiki/OpenGL_Programming/Installation/Mac
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	#include <GLUT/glut.h>
#endif
#ifdef _WIN32
// For VS on Windows only: Download CG_Demo.zip. UNZIP FIRST. Double click on CG_Demo/CG_Demo.sln
// Run
	#include "freeglut.h"
#endif
#ifdef __unix__
// For Linux users only: g++ CG_Demo.cpp -lglut -lGL -o CG_Demo
// ./CG_Demo
// Reference: https://www.linuxjournal.com/content/introduction-opengl-programming
	#include "GL/freeglut.h"
	#include "GL/gl.h"
#endif

#include <stdio.h>
#include <math.h>

#define DEG2RAD 0.0174533f
/*
*
*Jesus Norberto Reyes A01651207
*Luis Antonio Villa A01335048
*Using an openGL templete made by Sergio Ruiz
*
*/

float theVar;
float leftPaddleY;
float rightPaddleY;
float ballX;
float ballY;
float ballAngle;
float starCenterX, starCenterY, starRadius;
int bandera;

/////////////FORMS///////////////////////////
void rectangle(float x, float y, float w, float h, float r, float g, float b)
{
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	{
		glVertex3f(x, y, 0);
		glVertex3f(x + w, y, 0);
		glVertex3f(x + w, y - h, 0);
		glVertex3f(x, y - h, 0);
	}
	glEnd();
}

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b) {
	glColor3f(r, g, b);
	glBegin(GL_TRIANGLES);
	{
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glVertex2f(x3, y3);
	}
	glEnd();
}

void DrawStar(float x, float y, float r, int n) {
	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLE_FAN);
	int count = 1;
	glVertex2f(starCenterX, starCenterY);
	for (int i = 0; i <= 360; i += 360 / (n * 2)) {
		float DegInRad = i * DEG2RAD - 360 / (n + 1);
		if (count % 2 != 0)
			glVertex3f(x + cos(DegInRad) * r, y + sin(DegInRad) * r, 0);
		else
			glVertex3f((x + cos(DegInRad) * r / 2), (y + sin(DegInRad) * r / 2), 0);
		count++;
	}
	glEnd();
}

void drawCircle(float cx, float cy, float radius, float R, float G, float B) {
	glColor3f(R, G, B);
	glBegin(GL_POLYGON);
	{
		for (int i = 0; i < 360; i++) {
			float radians = 2.5f*radius * float(i);
			float x = radius * float(cos(radians));
			float y = radius * float(-sin(radians));
			glVertex3f(cx+x,cy+y, 0);
		}
	}
	glEnd();
}

/////////////////////FLAGS//////////////////////////
void showJapan() {
	drawCircle(0, -5,10,1,0,0);
	rectangle(-25, 10, 50, 30, 1, 1, 1);
}

void showGermany() {
	rectangle(-25, 10, 50, 10, 0, 0.1, 0);
	rectangle(-25, 0, 50, 10, 1, 0, 0);
	rectangle(-25, -10, 50, 10, 1, 1, 0);
}

void showJamaica() {
	//Triangle Left
	drawTriangle(-25, 8, -5, -5, -25, -18, 0, 0, 0);
	//Triangle Right
	drawTriangle(25, 8, 5, -5, 25, -18, 0, 0, 0);
	//Triangle up
	drawTriangle(-23, 10, 0, -4, 23, 10, 0, 1, 0);
	//Triangle down
	drawTriangle(-23, -20, 0, -6, 23, -20, 0, 1, 0);
	rectangle(-25, 10, 50, 30, 1, 1, 0);
}

void showFinland() {
	rectangle(-10, 10, 10, 30, 0, 0, 1);
	rectangle(-25, 0, 50, 10, 0, 0, 1);
	rectangle(-25, 10, 50, 30, 1, 1, 1);
	
}

void showBahamas() {
	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLES);
	{
		glVertex2f(-25, 10);
		glVertex2f(0, -5);
		glVertex2f(-25, -20);
	}
	glEnd();
	rectangle(-25, 10, 50, 10, .24, .7, .9);
	rectangle(-25, 0, 50, 10, .9, .79, .25);
	rectangle(-25, -10, 50, 10, .24, .7, .9);
}

void showSomalia() {
	DrawStar(0, -5, 10, 5);
	rectangle(-25, 10, 50, 30, 0.6, 0.6, 1);
}

void showGreece() {
	int nt = 1;
	float y = 10;
	rectangle(-17, 10, 4, 16.66667, 1, 1, 1);
	rectangle(-25, 4, 20, 4, 1, 1, 1);
	rectangle(-25, 10, 20, 16.66667, 0, 0, 1);

	for (int i = 0; i < 9; i++) {
		if (i % 2 == 0) {
			rectangle(-25, y, 50, 3.33333, 0, 0, 1);
		}
		else {
			rectangle(-25, y, 50, 3.3333, 1, 1, 1);
		}
		y -= 3.33333;
	}
}

////////////////////////////////////////////////
void axes() {
	glBegin(GL_LINES); {
		glColor3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);

		glColor3f(0, 1, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 1, 0);

		glColor3f(0, 0, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 1);
	}
	glEnd();
}

void init() // FOR GLUT LOOP
{
	theVar = 0;
	leftPaddleY = 0;
	rightPaddleY = 0;
	bandera = 1;
	glEnable(GL_DEPTH_TEST);			// Enable check for close and far objects.
	glClearColor(0.0, 0.0, 0.0, 0.0);	// Clear the color state.
	glMatrixMode(GL_MODELVIEW);			// Go to 3D mode.
	glLoadIdentity();					// Reset 3D view matrix.
}

void display()							// Called for each frame (about 60 times per second).
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				// Clear color and depth buffers.
	glLoadIdentity();												// Reset 3D view matrix.
	gluLookAt(0.0, 0.0, 100.0,										// Where the camera is.
		      0.0, 0.0, 0.0,										// To where the camera points at.
		      0.0, 1.0, 0.0);										// "UP" vector.
	
	//rectangle(-30, leftPaddleY, 2, 4, 1, 0, 0);
	//rectangle(30, rightPaddleY, 2, 4, 0, 0, 1);
	switch (bandera) {
	case 1:
		showJapan();
		break;
	case 2:
		showGermany();
		break;
	case 3:
		showJamaica();
		break;
	case 4:
		showFinland();
		break;
	case 5:
		showBahamas();
		break;
	case 6:
		showSomalia();
		break;
	case 7:
		showGreece();
		break;
	}
		
	glutSwapBuffers();												// Swap the hidden and visible buffers.
}

void idle()															// Called when drawing is finished.
{
	glutPostRedisplay();											// Display again.
}

void reshape(int x, int y)											// Called when the window geometry changes.
{
	glMatrixMode(GL_PROJECTION);									// Go to 2D mode.
	glLoadIdentity();												// Reset the 2D matrix.
	gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 150.0);		// Configure the camera lens aperture.
	glMatrixMode(GL_MODELVIEW);										// Go to 3D mode.
	glViewport(0, 0, x, y);											// Configure the camera frame dimensions.
	gluLookAt(0.0, 1.0, 4.0,
		      0.0, 0.0, 0.0,
		      0.0, 1.0, 0.0);
	display();
}
void theKeys(unsigned char key, int x, int y) {
	//printf("%c %d %d\n", key,x,y);
	switch (key) {
	case '1':
		bandera=1;
		break;
	case '2':
		bandera = 2;
		break;
	case '3':
		bandera = 3;
		break;
	case '4':
		bandera = 4;
		break;
	case '5':
		bandera = 5;
		break;
	case '6':
		bandera = 6;
		break;
	case '7':
		bandera = 7;
		break;
	}
	
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);											// Init GLUT with command line parameters.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);		// Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
	glutInitWindowSize(800, 800);
	glutCreateWindow("CG first program");

	init();
	glutKeyboardFunc(theKeys);
	//glutSpecialFunc(specialKeys);
	glutReshapeFunc(reshape);										// Reshape CALLBACK function.
	glutDisplayFunc(display);										// Display CALLBACK function.
	glutIdleFunc(idle);												// Idle CALLBACK function.
	glutMainLoop();													// Begin graphics program.
	return 0;														// ANSI C requires a return value.
}
