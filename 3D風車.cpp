#include  <math.h>
#include  <GL/glut.h>

#define  ColoredVertex(c,v) do{ glColor3fv(c); glVertex3fv(v); }while(0)

int a=0;

int num=0;

static GLdouble viewer[]= {4.0, 0.0, 2.0};
GLUquadricObj  *p;

GLfloat sun_light_position[] = {1.0f, 1.0f, 1.0f, 1.0f}; //¥ú·½ªº¦ì¸m¦b¥@¬É®y¼Ð¨t¶ê¤ß¡A»ô¦¸®y¼Ð§Î¦¡
GLfloat sun_light_ambient[]   = {0.4f, 0.6f, 0.0f, 1.0f}; //RGBA¼Ò¦¡ªºÀô¹Ò¥ú¡A¬°0
GLfloat sun_light_diffuse[]   = {1.0f, 1.0f, 1.0f, 1.0f}; //RGBA¼Ò¦¡ªºº©¤Ï®g¥ú¡A¥þ¥Õ¥ú
GLfloat sun_light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};  //RGBA¼Ò¦¡¤UªºÃè­±¥ú ¡A¥þ¥Õ¥ú
GLfloat angle  =   0.0f ;
GLfloat ColorR[]  =  { 1 , 0 , 0 },
		ColorG[]  =  { 0 , 1 , 0 },
		ColorB[]  =  { 0 , 0 , 1 },
		ColorY[]  =  { 1 , 1 , 0 };

GLfloat LEFT_UP[][3]={
{0.0,0.0,0.0},
{0.0, 0.0, 0.5},
{0.0,-0.5,0.5},
{-0.2, 0.0, 0.0},
{-0.2, 0.0, 0.5},
{-0.2, -0.5, 0.5}, 
} ;
GLfloat LEFT_DOWN[][3]={
{0.0,0.0,0.0},
{0.0, -0.5, 0.0},
{0.0, -0.5, -0.5},
{-0.2,0.0,0.0},
{-0.2, -0.5, 0.0},
{-0.2, -0.5, -0.5},
} ;
GLfloat RIGHT_UP[][3]={
{0.0,0.0,0.0},
{0.0, 0.5, 0.0},
{0.0, 0.5, 0.5},
{-0.2, 0.0, 0.0},
{-0.2, 0.5, 0.0},
{-0.2, 0.5, 0.5},
};
GLfloat RIGHT_DOWN[][3]={
{0.0,0.0,0.0},
{0.0,0.0,-0.5},
{0.0,0.5,-0.5},
{-0.2,0.0,0.0},
{-0.2, 0.0, -0.5},
{-0.2,0.5,-0.5}
};
GLfloat Branch[][3]={
{-0.05,0.0,0.0},
{0.0,-0.05,0.0},
{0.05,0.0,0.0},
{0.0,0.05,0.0},
{-0.05,0.0,-1.0},
{0.0,-0.05,-1.0},
{0.05,0.0,-1.0},
{0.0,0.05,-1.0},

};


void  RIGHT_DOWN_Triangle(){
        glBegin(GL_QUADS);
        	ColoredVertex(ColorR,RIGHT_DOWN[0]);
        	ColoredVertex(ColorY,RIGHT_DOWN[1]);
			ColoredVertex(ColorG,RIGHT_DOWN[4]);
        	ColoredVertex(ColorB,RIGHT_DOWN[3]);
        	
        	ColoredVertex(ColorR,RIGHT_DOWN[1]);
        	ColoredVertex(ColorY,RIGHT_DOWN[2]);
        	ColoredVertex(ColorG,RIGHT_DOWN[5]);
        	ColoredVertex(ColorB,RIGHT_DOWN[4]);

        	ColoredVertex(ColorB,RIGHT_DOWN[0]);
			ColoredVertex(ColorR,RIGHT_DOWN[2]);
        	ColoredVertex(ColorY,RIGHT_DOWN[5]);
        	ColoredVertex(ColorG,RIGHT_DOWN[3]);
        	
        glEnd();
        glBegin(GL_TRIANGLES);
        	ColoredVertex(ColorR,RIGHT_DOWN[0]);
        	ColoredVertex(ColorG,RIGHT_DOWN[1]);
			ColoredVertex(ColorY,RIGHT_DOWN[2]);
	        
			ColoredVertex(ColorB,RIGHT_DOWN[3]);
			ColoredVertex(ColorB,RIGHT_DOWN[4]);
			ColoredVertex(ColorB,RIGHT_DOWN[5]);
	    glEnd();
}
void  LEFT_DOWN_Triangle(){
        glBegin(GL_QUADS);
        	ColoredVertex(ColorG,LEFT_DOWN[1]);
        	ColoredVertex(ColorB,LEFT_DOWN[2]);
			ColoredVertex(ColorY,LEFT_DOWN[5]);
        	ColoredVertex(ColorR,LEFT_DOWN[4]);

        	ColoredVertex(ColorB,LEFT_DOWN[1]);
        	ColoredVertex(ColorR,LEFT_DOWN[4]);
			ColoredVertex(ColorG,LEFT_DOWN[3]);
        	ColoredVertex(ColorY,LEFT_DOWN[0]);
			
			ColoredVertex(ColorR,LEFT_DOWN[0]);
        	ColoredVertex(ColorB,LEFT_DOWN[3]);
			ColoredVertex(ColorG,LEFT_DOWN[5]);
        	ColoredVertex(ColorY,LEFT_DOWN[2]);
        glEnd();
        glBegin(GL_TRIANGLES);
        	ColoredVertex(ColorB,LEFT_DOWN[0]);
			ColoredVertex(ColorR,LEFT_DOWN[1]);
			ColoredVertex(ColorY,LEFT_DOWN[2]);
        	
        	ColoredVertex(ColorB,LEFT_DOWN[3]);
			ColoredVertex(ColorG,LEFT_DOWN[4]);
			ColoredVertex(ColorY,LEFT_DOWN[5]);
	    glEnd();
}
void  LEFT_UP_Triangle(){
        glBegin(GL_QUADS);
        	ColoredVertex(ColorR,LEFT_UP[0]);
			ColoredVertex(ColorB,LEFT_UP[1]);
			ColoredVertex(ColorY,LEFT_UP[4]);
        	ColoredVertex(ColorB,LEFT_UP[3]);
        
        	ColoredVertex(ColorB,LEFT_UP[1]);
			ColoredVertex(ColorG,LEFT_UP[4]);
			ColoredVertex(ColorY,LEFT_UP[5]);
        	ColoredVertex(ColorR,LEFT_UP[2]);
        
        	ColoredVertex(ColorB,LEFT_UP[2]);
			ColoredVertex(ColorR,LEFT_UP[5]);
			ColoredVertex(ColorY,LEFT_UP[3]);
        	ColoredVertex(ColorG,LEFT_UP[0]);
        glEnd();
        glBegin(GL_TRIANGLES);
        	ColoredVertex(ColorG,LEFT_UP[0]);
			ColoredVertex(ColorB,LEFT_UP[1]);
			ColoredVertex(ColorY,LEFT_UP[2]);
        
        	ColoredVertex(ColorG,LEFT_UP[3]);
			ColoredVertex(ColorY,LEFT_UP[4]);
			ColoredVertex(ColorB,LEFT_UP[5]);

	    glEnd();

}
void  RIGHT_UP_Triangle(){

	    glBegin(GL_QUADS);
			ColoredVertex(ColorR,RIGHT_UP[1]);
			ColoredVertex(ColorB,RIGHT_UP[2]);
			ColoredVertex(ColorG,RIGHT_UP[5]);
			ColoredVertex(ColorY,RIGHT_UP[4]);
	        
			ColoredVertex(ColorG,RIGHT_UP[1]);
			ColoredVertex(ColorY,RIGHT_UP[0]);
			ColoredVertex(ColorR,RIGHT_UP[3]);
			ColoredVertex(ColorB,RIGHT_UP[4]);
	
			
			ColoredVertex(ColorY,RIGHT_UP[0]);
			ColoredVertex(ColorB,RIGHT_UP[3]);
			ColoredVertex(ColorG,RIGHT_UP[5]);
	        ColoredVertex(ColorR,RIGHT_UP[2]);
	    glEnd();
	    glBegin(GL_TRIANGLES);
	    
	    	ColoredVertex(ColorR,RIGHT_UP[0]);
			ColoredVertex(ColorG,RIGHT_UP[1]);
			ColoredVertex(ColorG,RIGHT_UP[2]);
			
			ColoredVertex(ColorY,RIGHT_UP[3]);
			ColoredVertex(ColorB,RIGHT_UP[4]);
			ColoredVertex(ColorR,RIGHT_UP[5]);
		glEnd();
}
void circle(){
		gluQuadricNormals(p, GLU_SMOOTH);
		glPushMatrix();
	        glColor3fv(ColorB);
			glTranslatef(0.01, 0.0, 0.01)	;        
			gluSphere(p,0.05f,16,16);
			
	    glPopMatrix();
}
void branch(){
	
		glBegin(GL_QUADS);
			ColoredVertex(ColorR,Branch[0]);
			ColoredVertex(ColorB,Branch[1]);
			ColoredVertex(ColorG,Branch[2]);
			ColoredVertex(ColorY,Branch[3]);
		
			ColoredVertex(ColorR,Branch[4]);
			ColoredVertex(ColorY,Branch[5]);
			ColoredVertex(ColorG,Branch[6]);
			ColoredVertex(ColorB,Branch[7]);
		
            ColoredVertex(ColorY,Branch[2]);
			ColoredVertex(ColorR,Branch[1]);
			ColoredVertex(ColorB,Branch[5]);
			ColoredVertex(ColorG,Branch[6]);
	        
	        
	        ColoredVertex(ColorG,Branch[2]);
			ColoredVertex(ColorB,Branch[3]);
			ColoredVertex(ColorR,Branch[7]);
			ColoredVertex(ColorY,Branch[6]);
		
            
	    	ColoredVertex(ColorR,Branch[4]);
			ColoredVertex(ColorG,Branch[5]);
			ColoredVertex(ColorY,Branch[6]);
			ColoredVertex(ColorB,Branch[7]);
		
            ColoredVertex(ColorG,Branch[1]);
			ColoredVertex(ColorB,Branch[0]);
			ColoredVertex(ColorR,Branch[4]);
			ColoredVertex(ColorY,Branch[5]);
		
	        
	        ColoredVertex(ColorB,Branch[0]);
			ColoredVertex(ColorR,Branch[3]);
			ColoredVertex(ColorG,Branch[7]);
			ColoredVertex(ColorY,Branch[4]);
	    glEnd();

}

static void mydisplay(){
	static   int  list  =   0 ;
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();	
	gluPerspective(30,1.0,1.0,30.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	gluLookAt(viewer[0],viewer[1],viewer[2],0,0,0,0,0,1);

	list  =  glGenLists( 2 );
	
	
	circle();
	branch();

	glNewList(list,GL_COMPILE);
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(a,1.0,0.0,0.0);
		glTranslatef(-0.0, -0.0, -0.0);
    
		LEFT_UP_Triangle();
	
		LEFT_DOWN_Triangle();
	
		RIGHT_UP_Triangle();
		
		RIGHT_DOWN_Triangle();			
		
	glEndList();

	glPushMatrix();
		glRotatef(a, 1 , 0 , 0 ); 	 	
		glCallList(list); 
	glPopMatrix();
	
	
	glutSwapBuffers();

} 
void myinit()
{
   glClearColor(1.0, 1.0, 1.0, 1.0);
   glColor3f(1.0, 0.0, 0.0);

   p=gluNewQuadric();
   gluQuadricDrawStyle(p, GL_SMOOTH); 
}
void camera(unsigned char key, int x, int y)
{
   if(key == 'w') viewer[0]-= 1.0;
   if(key == 's') viewer[0]+= 1.0;
   if(key == 'a') viewer[1]-= 1.0;
   if(key == 'd') viewer[1]+= 1.0;
   if(key == 'q') viewer[2]-= 1.0;
   if(key == 'e') viewer[2]+= 1.0;
   mydisplay();
}
void main_menu(int index) {
    switch (index) {
    case(1):
        num+=1;
        mydisplay();
        break;
    case(2): 
        num-=1;
       	mydisplay();
        break;
    case(3):
        viewer[0]-= 1.0;
        mydisplay();
        break;
    case(4): 
        viewer[0]+= 1.0;
        mydisplay();
        break;
    case(5): 
       	viewer[1]-= 1.0;
        mydisplay();
        break;
    case(6): 
       	viewer[1]+= 1.0;
        mydisplay();
        break;
    case(7): 
        viewer[2]-= 1.0;
        mydisplay();
        break;
    case(8): 
        viewer[2]+= 1.0;
        mydisplay();
        break;
    case(9):
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		break;
	case(10):
    	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		break;
	case(11):
        exit(0);
        break;
    }
}

void drive(int t){	//timer
	glutTimerFunc(10, drive, t+1); 
	a=a+num;
	glutPostRedisplay();
	
}

int  main( int  argc, char   * argv[]){

    glutInit( & argc,argv);
    glutInitDisplayMode(GLUT_RGB |  GLUT_DOUBLE| GLUT_DEPTH);
	
    glutInitWindowPosition( 200 , 200 );
    glutInitWindowSize( 640 , 480 );
    glutCreateWindow( " Revolve Triangle " );
 	myinit();
    glutDisplayFunc(mydisplay);
	glutTimerFunc(10, drive, 0);
	

	GLubyte image[64][64][3];
	int i, j,  c;
	for(i=0;i<64;i++){
		for(j=0;j<64;j++){
		c = ((((i&0x4)==0)^((j&0x4))==0))*255;
			image[i][j][0]= (GLubyte) c-50;
			image[i][j][1]= (GLubyte) c-20;
			image[i][j][2]= (GLubyte) c-40;
	}
	}
	
	glutCreateMenu(main_menu); /* å»ºç«‹æ“ä½œé¸å–® */
    glutAddMenuEntry("faster", 1);
    glutAddMenuEntry("slower", 2);
    glutAddMenuEntry("camera x +", 3);
    glutAddMenuEntry("camera x -", 4);
    glutAddMenuEntry("camera y +", 5);
    glutAddMenuEntry("camera y -", 6);
    glutAddMenuEntry("camera z +", 7);
    glutAddMenuEntry("camera z -", 8);
    glutAddMenuEntry("change to mesh", 9);
    glutAddMenuEntry("change to fill", 10);
    glutAddMenuEntry("quit", 11);
    glutAttachMenu(GLUT_RIGHT_BUTTON); 
				
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
	


	
	glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);     
	glLightfv(GL_LIGHT0, GL_AMBIENT,   sun_light_ambient);  
	glLightfv(GL_LIGHT0, GL_DIFFUSE,   sun_light_diffuse);   
	glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);  
	
	glEnable(GL_LIGHT0);    
	glEnable(GL_LIGHTING);   
	
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	
    glEnable(GL_TEXTURE_2D);
    glTexImage2D(GL_TEXTURE_2D,0,3,64,64,0,GL_RGB,GL_UNSIGNED_BYTE, image);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glClearColor(1.0,1.0,1.0,1.0);

   
    glutMainLoop();

     return   0 ;
}

