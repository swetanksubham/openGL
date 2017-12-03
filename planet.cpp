#include<GL/glut.h>
float rotateInAxis;
GLfloat yellow[] = {1.0,1.0,0.0,0.0};
GLfloat white2[] = {1.0,1.0,1.0,0.0};
GLfloat mat_shininess[] = {50.0};
GLfloat white[] = {1.0,1.0,1.0,1.0};
GLfloat light_position[] = {0.0,0.0,1.0,0.0};
void Init()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-500,500,-500,500,-500,500);
}
void timer(int t)
{
	rotateInAxis += 5;
	glutPostRedisplay();
	glutTimerFunc(70,timer,0);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(45,0.3,0,1);
	glPushMatrix();
	
	glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,yellow);
	glMaterialfv(GL_FRONT,GL_SPECULAR,white2);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	
	glRotatef(-45,0.3,0,1);
	glutSolidSphere(100,200,200);
	glPopMatrix();
	glPushMatrix();
	
	glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,white);
	glMaterialfv(GL_FRONT,GL_SPECULAR,white);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	
	GLfloat light_position[] = {0.0,0.0,0.0,0.0};
	glRotatef(rotateInAxis,0,1,0);
	glTranslatef(0.0,0.0,450);
	glRotatef(180,0,1,0);
	glutSolidSphere(40,200,200);
	glPopMatrix();
	glPopMatrix();
	glFlush();
}
int main(int roy, char** troy)
{
	glutInit(&roy, troy);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Roy");
	Init();
	glutDisplayFunc(display);
	glutTimerFunc(70,timer,0);
	glutMainLoop();
}
