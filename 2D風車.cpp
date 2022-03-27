#include<GL/glut.h>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#define _USE_MATH_DEFINES 
#include<cmath>
#include <mmsystem.h>

float angle = 0;

void circle(GLfloat center_x, GLfloat center_y , GLfloat radius ,float *colors){
	glColor3f(colors[0], colors[1] ,colors[2]);
	glBegin(GL_POLYGON);
		float theta = M_PI/1000.f;
		for( float angle = 0.0; angle < 2*M_PI; angle += theta )
			glVertex2f(center_x + radius*cos(angle), center_y + radius*sin(angle));
	glEnd();
	glFlush();
}
void circle_Line(GLfloat center_x, GLfloat center_y , GLfloat radius ,float *colors){
	glColor3f(colors[0], colors[1] ,colors[2]);
	glBegin(GL_LINE_LOOP);
		float theta = M_PI/1000.f;
		for( float angle = 0.0; angle < 2*M_PI; angle += theta )
			glVertex2f(center_x + radius*cos(angle), center_y + radius*sin(angle));
	glEnd();
	glFlush();
}
void Rect_Line(GLint lowerLeft_x, GLint lowerLeft_y, GLfloat *colors, GLint width, GLint height){
	glColor3f(colors[0],colors[1],colors[2]);
	glBegin(GL_LINES);
		glVertex2i(lowerLeft_x,lowerLeft_y);
		glVertex2i(lowerLeft_x,lowerLeft_y+height);
		glVertex2i(lowerLeft_x,lowerLeft_y);
		glVertex2i(lowerLeft_x+width,lowerLeft_y);
		glVertex2i(lowerLeft_x+width,lowerLeft_y+height);
		glVertex2i(lowerLeft_x+width,lowerLeft_y);
		glVertex2i(lowerLeft_x+width,lowerLeft_y+height);
		glVertex2i(lowerLeft_x,lowerLeft_y+height);
	glEnd();
	glFlush();

}
void Rect(GLint lowerLeft_x, GLint lowerLeft_y, GLfloat *colors, GLint width, GLint height){
	glColor3f(colors[0],colors[1],colors[2]);
	glBegin(GL_POLYGON);
		glVertex2i(lowerLeft_x,lowerLeft_y);
		glVertex2i(lowerLeft_x,lowerLeft_y+height);
		glVertex2i(lowerLeft_x,lowerLeft_y);
		glVertex2i(lowerLeft_x+width,lowerLeft_y);
		glVertex2i(lowerLeft_x+width,lowerLeft_y+height);
		glVertex2i(lowerLeft_x+width,lowerLeft_y);
		glVertex2i(lowerLeft_x+width,lowerLeft_y+height);
		glVertex2i(lowerLeft_x,lowerLeft_y+height);
	glEnd();
}
void Triangle(GLint vert_x,GLint vert_y,GLint side,float*colors,int number){
	glColor3f(colors[0],colors[1],colors[2]);
	switch(number){
	case 1:
		glBegin(GL_POLYGON);
			glVertex2i(vert_x,vert_y);
			glVertex2i(vert_x,vert_y+side);
			glVertex2i(vert_x+side,vert_y);
			glVertex2i(vert_x,vert_y);
		glEnd();
		glFlush();
		break;
	case 2:
		glBegin(GL_POLYGON);
			glVertex2i(vert_x,vert_y);
			glVertex2i(vert_x,vert_y+side);
			glVertex2i(vert_x+side,vert_y+side);
			glVertex2i(vert_x,vert_y);
		glEnd();
		glFlush();
		break;
	case 3:
		glBegin(GL_POLYGON);
			glVertex2i(vert_x,vert_y);
			glVertex2i(vert_x+side,vert_y+side);
			glVertex2i(vert_x+side,vert_y);
			glVertex2i(vert_x,vert_y);
		glEnd();
		glFlush();
		break;
	case 4:
		glBegin(GL_POLYGON);
			glVertex2i(vert_x,vert_y+side);
			glVertex2i(vert_x+side,vert_y+side);
			glVertex2i(vert_x+side,vert_y);
			glVertex2i(vert_x,vert_y+side);
		glEnd();
		glFlush();
		break;
	}	
}
void Triangle_Line(GLint vert_x,GLint vert_y,GLint side,float*colors,int number){
	glColor3f(colors[0],colors[1],colors[2]);
		switch(number){
	case 1:
		glBegin(GL_LINES);
			glVertex2i(vert_x,vert_y);
			glVertex2i(vert_x,vert_y+side);
			glVertex2i(vert_x,vert_y);
			glVertex2i(vert_x+side,vert_y);
			glVertex2i(vert_x+side,vert_y);
			glVertex2i(vert_x,vert_y+side);
		glEnd();
		glFlush();
		break;
	case 2:
		glBegin(GL_LINES);
			glVertex2i(vert_x,vert_y);
			glVertex2i(vert_x,vert_y+side);
			glVertex2i(vert_x,vert_y);
			glVertex2i(vert_x+side,vert_y+side);
			glVertex2i(vert_x,vert_y+side);
			glVertex2i(vert_x+side,vert_y+side);
		glEnd();
		glFlush();
		break;
	case 3:
		glBegin(GL_LINES);
			glVertex2i(vert_x,vert_y);
			glVertex2i(vert_x+side,vert_y+side);
			glVertex2i(vert_x,vert_y);
			glVertex2i(vert_x+side,vert_y);
			glVertex2i(vert_x+side,vert_y+side);
			glVertex2i(vert_x+side,vert_y);	
		glEnd();
		glFlush();
		break;
	case 4:
		glBegin(GL_LINES);
			glVertex2i(vert_x,vert_y+side);
			glVertex2i(vert_x+side,vert_y+side);
			glVertex2i(vert_x,vert_y+side);
			glVertex2i(vert_x+side,vert_y);
			glVertex2i(vert_x+side,vert_y+side);
			glVertex2i(vert_x+side,vert_y);
		glEnd();
		glFlush();
		break;
	}
}
void Branch(){
		glLineWidth(2);
		GLfloat color_Rect[]={0.8,0.8,0.6};
		GLfloat color_Line[]={0.7,0.5,0.4};
		GLfloat color_circle[]={1,0.7,0.8};	
			
		Rect(295,200,color_Rect,10,200);
		Rect_Line(295,200,color_Line,10,200);
		
		circle(300,400,20,color_circle);
		circle_Line(300,400,20,color_Line);
}
void Picture(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	float center[2]={300,400};
	
	GLfloat color_Triangle_lowleft[]={1,1,0.1};
	GLfloat color_Triangle_upleft[]={0.9,0.2,0.2};
	GLfloat color_Triangle_lowright[]={0.7,1,0.1};
	GLfloat color_Triangle_upright[]={0.3,0.3,1};	
	GLfloat color_Line[]={0.7,0.5,0.4};

	glLineWidth(2);
	glPushMatrix();
		glTranslatef(center[0],center[1],0);	//Translate  center (origin center =(0,0)=>(center[0],center[1]))
		glRotatef(angle,0.0, 0.0, 1.0);			//Rotate wings of angle 
		glTranslatef(-center[0],-center[1],0);	//Translate back  to center 
			Triangle(200,400,100,color_Triangle_upleft,1);
			Triangle_Line(200,400,100,color_Line,1);
			Triangle(300,400,100,color_Triangle_upright,2);
			Triangle_Line(300,400,100,color_Line,2);
			Triangle(200,300,100,color_Triangle_lowleft,3);
			Triangle_Line(200,300,100,color_Line,3);
			Triangle(300,300,100,color_Triangle_lowright,4);
			Triangle_Line(300,300,100,color_Line,4);
	glPopMatrix();
	Branch();
	glutSwapBuffers(); 							// using double buffer to solve the flashing problem
}

int num =0;
void drive(int t){	//timer
	glutTimerFunc(10, drive, t+1); 
	angle+=num;
	glutPostRedisplay();

}
void mouseFunc(GLint button,GLint state,GLint X,GLint Y)
{
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
        if(state == GLUT_DOWN)
        {
        	num+=10;
        }
        break;
        case GLUT_RIGHT_BUTTON:
        if(state == GLUT_DOWN)
        {
        	num-=10;
        }
        break;
    }
}


int main(int argc , char**argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);	//DOUBLE_BUFFER | RGB
	glutInitWindowPosition(480,270);			//Window Position 
	glutInitWindowSize(800,600);				//Size of Window
	glutCreateWindow("HW1");					
	glMatrixMode(GL_PROJECTION);				//3d=>2d
	
	
	glClearColor(0.0f, 0.8f, 0.9f, 1.0f);		 
	gluOrtho2D(0.0,800,0.0,600);				// projection size to place in
	glutDisplayFunc(Picture);					// function to show
	glutTimerFunc(10, drive, 0);				// timer
	glutMouseFunc(mouseFunc);

	glutMainLoop();	
}



