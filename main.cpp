#include "glut.h"
#include "geometry.h"
#include <stdio.h>
#include <stdlib.h>
/* Definições da câmera */
#define y_min 60
#define ro_min 120
float eyex = 0, eyey = y_min, eyez = ro_min;
float angleOlho=0,angleBoca,movimentoz=0,movimentox=0,movimentoy=0,olhoH=-3,olhoV=-1,angleMX=-60,angleMY=-30,angleMz=0;;
int aux=0;

/* Angulos de rotação de cada corpo celeste*/

void drawTeste() {
	//glColor3f(1, 0, 0);
	glutSolidCube(10);
}
void drawFantasma(){
	glPushMatrix();//primeiro
      	color(1, 0, 0);
      	glScalef(1,3,0.5);
      	drawTeste();
      glPopMatrix();
      
      glTranslatef(0,5,5);
      
      glPushMatrix(); //segundo
      	color(1, 0, 0);
      	glScalef(1,3.2,0.5);
      	drawTeste();
      glPopMatrix();
      
      glTranslatef(0,2,5);
      
      glPushMatrix(); // terceiro
      	color(1, 0, 0);
      	glScalef(1,3.1,0.5);
      	drawTeste();
      	glTranslatef(1,2,15);
      	glPushMatrix(); //Olho horizontal
	      	color(1,1,1);
	      	glScalef(1,0.2,2.6);
	      	drawTeste();
	      	glTranslatef(3,olhoV,olhoH); //bola do olho E
	      	glPushMatrix();
	      		color(0,0,1);
	      		glScalef(0.6,0.8,0.5);
	      		drawTeste();
	      		
	      	glPopMatrix();	
      	glPopMatrix();	
      	glTranslatef(3.5,0,0);
      	glPushMatrix(); //Olho veritical
      	//	glRotatef(90,0,0,1);
	      	color(1,1,1);
	      	glScalef(0.4,0.3,1.6);
	      	drawTeste();
      	glPopMatrix();
      glPopMatrix();
      
      glTranslatef(0,0,5);
      
      glPushMatrix(); //quarto
      	color(1, 0, 0);
      	glScalef(1,3.5,0.5);
      	drawTeste();
      glPopMatrix();
      
      glTranslatef(0,-2,5);
      
      glPushMatrix(); //quinto
      	color(1, 0, 0);
      	glScalef(1.0,3.9,0.5);
      	drawTeste();
      	
      glPopMatrix();
      
      glTranslatef(0,3.3,5);
      
      glPushMatrix(); //sexto
      	color(1, 0, 0);
      	glScalef(1.0,3.6,0.5);
      	drawTeste();
      glPopMatrix();
      
      glTranslatef(0,0,5);
      
      glPushMatrix(); //setimo
      	color(1, 0, 0);
      	glScalef(1.0,3.6,0.5);
      	drawTeste();
      glPopMatrix();
      
      glTranslatef(0,0,5);
      
      glPushMatrix(); //oitavo
      	color(1, 0, 0);
      	glScalef(1.0,3.6,0.5);
      	drawTeste();
      	glTranslatef(1,1.2,24);
      	glPushMatrix(); //Olho horizontal
	      	color(1,1,1);
	      	glScalef(1,0.16,2.4);
	      	drawTeste();
	      	glTranslatef(3,olhoV,olhoH); //bola do olho D
	      	glPushMatrix();
	      		color(0,0,1);
	      		glScalef(0.6,0.8,0.5);
	      		drawTeste();
	      	glPopMatrix();	
      	glPopMatrix();	
      	glTranslatef(3.5,0,0);
      	glPushMatrix(); //Olho veritical
      	//	glRotatef(90,0,0,1);
	      	color(1,1,1);
	      	glScalef(0.4,0.24,1.6);
	      	drawTeste();
      	glPopMatrix();
      glPopMatrix();
      
      glTranslatef(0,0,5);
      
      glPushMatrix(); //nono
      	color(1, 0, 0);
      	glScalef(1.0,3.6,0.5);
      	drawTeste();
      glPopMatrix();
      
      glTranslatef(0,-3.3,5);
      
      glPushMatrix(); //decimo
      	color(1, 0, 0);
      	glScalef(1,3.9,0.5);
      	drawTeste();
      glPopMatrix();
      
      glTranslatef(0,2,5);
      
      glPushMatrix(); //11
      	color(1, 0, 0);
      	glScalef(1,3.5,0.5);
      	drawTeste();
      glPopMatrix();
      
      glTranslatef(0,0,5);
      
      glPushMatrix(); //quarto
      	color(1, 0, 0);
      	glScalef(1,3.1,0.5);
      	drawTeste();
      glPopMatrix();
      
      glTranslatef(0,-2.9,5);
      
      glPushMatrix(); //segundo
      	color(1, 0, 0);
      	glScalef(1,3.2,0.5);
      	drawTeste();
      glPopMatrix();
      
     glTranslatef(0,-5,5);   
	    
      glPushMatrix();//primeiro
      	color(1, 0, 0);
      	glScalef(1,3,0.5);
      	drawTeste();
      glPopMatrix();
}

void display(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    /* Limpa o Buffer de Pixels */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    /* Estabelece a cor da primitiva como preta */
    glColor3f (1.0, 1.0, 1.0);
    
    /* Define a posição do observador */
	gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
	
	
	glTranslatef(angleMX,angleMY,0);
    /* Desenha os planetas com hierarquia*/
    glPushMatrix();
    
      glScalef(0.25,0.25,0.25);
      
      glPushMatrix();
      	glRotatef(-95,0,1,0);
      	drawFantasma();
      glPopMatrix();
      
    glPopMatrix();
    
    	
    /* 
	Inicia o processo de desenho atraves dos
    dados bufferizados
    */
    glutSwapBuffers();
}

void TimerFunc(int value) {
		if((angleMX>=-60 && angleMX <0) && (angleMY>=-30 && angleMY<30)){
			angleMX = angleMX +1;
			angleMY = angleMY +1;
			if(olhoV<=4){
		 	aux= (int) (olhoV + 1);
		 	olhoV = aux % 360;
		 }
		 	if(olhoH<=3){
		 	aux= (int) (olhoH + 1);
		    olhoH = aux % 360;
		 }
		}
		if((angleMX>=0 && angleMX <60) && (angleMY<=30 && angleMY>0)){
			angleMX = angleMX +2;
			angleMY = angleMY -1;
			if(olhoV<=4){
		 	aux= (int) (olhoV + 1);
		 	olhoV = aux % 360;
		 }
		 	if(olhoH>=-3){
		 	aux= (int) (olhoH - 1);
		    olhoH = aux % 360;
		 }
		 
		}
		if((angleMX<=60 && angleMX >0) && (angleMY<=0 && angleMY>-60)){
			angleMX = angleMX -1;
			angleMY = angleMY -1;		
			if(olhoV>=-4){
		 	aux= (int) (olhoV - 1);
		    olhoV = aux % 360;
		 }
		 	if(olhoH>=-3){
		 	aux= (int) (olhoH - 1);
		    olhoH = aux % 360;
		 }
		}
		if((angleMX<=0 && angleMX >-60) && (angleMY>=-60 && angleMY<-30)){
			angleMX = angleMX -2;
			angleMY = angleMY +1;
			if(olhoH<=3){
		 	aux= (int) (olhoH + 1);
		    olhoH = aux % 360;
		 }
		 	if(olhoV>=-4){
		 	aux= (int) (olhoV - 1);
		    olhoV = aux % 360;
		 }
		}

		//angle++;
	    glutPostRedisplay();
	    glutTimerFunc( 33, TimerFunc, 1);
}

void reshape(int width, int height) {
	glViewport(0,0,width,height); // Reset The Current Viewport
	
	glMatrixMode(GL_PROJECTION); // Select The Projection Matrix
	glLoadIdentity(); // Reset The Projection Matrix
	
	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(float)640/(float)480,0.1f,1000.0f);
	// Always keeps the same aspect as a 640 wide and 480 high window
	
	glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
	glLoadIdentity(); // Reset The Modelview Matrix
}

void key(unsigned char key, int x, int y) {
	switch(key) {
		case 27:
			exit(0);
			break;
		case 'Q': /* e key rotates at elbow */
	 	 aux = (int) (movimentox + 5);
		 movimentox = aux % 360;
		 glutPostRedisplay();
		 break;
		case 'q': /* e key rotates at elbow */
	 	 aux = (int) (movimentox - 5);
		 movimentox = aux % 360;
		 glutPostRedisplay();
		 break;
		case 'w': /* e key rotates at elbow */
	 	 aux = (int) (movimentoy + 5);
		 movimentoy = aux % 360;
		 
		 glutPostRedisplay();
		 break;
		case 's': /* e key rotates at elbow */
	 	 aux = (int) (movimentoy - 5);
		 movimentoy = aux % 360;


		 glutPostRedisplay();
		 break;
		case 'a': /* e key rotates at elbow */
	 	 aux = (int) (movimentoz + 5);
		 movimentoz = aux % 360;

		 glutPostRedisplay();
		 break;
		case 'd': /* e key rotates at elbow */
	 	 aux = (int) (movimentoz - 5);
		 movimentoz = aux % 360;
		 glutPostRedisplay();
		 break;
//		case 'm': /* e key rotates at elbow */
//	 	 aux = (int) (angle + 5);
//		 angle = aux % 360;
//		 glutPostRedisplay();
//		 break;
//		case 'M': /* e key rotates at elbow */
//	 	 aux = (int) (angle - 5);
//		 angle = aux % 360;
//		 glutPostRedisplay();
//		 break;
	}
}

void init() {
	glClearColor(1,1,1,0);
	glClearDepth(1.0); // Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS); // The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST); // Enables Depth Testing
	glShadeModel(GL_SMOOTH); // Enables Smooth Color Shading
}

/*
Funcao principal do programa.
*/
int main(int argc, char** argv)
{
	//Inicia a Telinha
	glutInit(&argc,argv);
	
    /*
    Estabelece o modo de exibicao a ser utilizado pela janela a ser
    neste caso utiliza-se de um buffer duplo, ou seja, a apresentacao
    execucao
    Define o modo de cores como RGBA
    */
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    
    /*
    Determina o tamanho em pixels da
    janela a ser criada
    */
    glutInitWindowSize (1340, 900);
    
    /*
    Estabelece a posicao inicial para criacao da
    janela
    */
    glutInitWindowPosition (100, 100);
    
    /*
    Cria uma janela com base nos parametros especificados
    nas funcoes glutInitWindowSize e glutInitWindowPosition
    com o nome de titulo especificado em seu argumento
    */
    glutCreateWindow ("Projeto Base");
    
    /*
    Especifica os parametros inicias para as variaveis
    de estado do OpenGL
    */
    init ();

    // Associa a funcao display como uma funcao de callback
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    TimerFunc(1);
    
    /*
    Inicia a execucao do programa OpenGL.
    O programa ira executar num loop infinito devendo
    o desenvolvedor especificar as condicoes de saida do mesmo
    atraves de interrupcoes no proprio programa ou atraves
    de comandos de mouse ou teclado como funcoes de callback
    */
    glutMainLoop();
    return 0;
}
