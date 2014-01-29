// Mick Tarsel
// use Makefile to run


#include "initShaders.h"
using namespace std;
int counter=0;

//vertexIDs
GLuint vaoID, vboID;// the buffers that are going to be linked too
//vertices
GLfloat vertexarray[]={0.5f,-0.5f,0.0f,0.0f,0.5f,0.0f,-0.5f,-0.5f,0.0f};// vertices that are drawn x,y,z ...
//indices of triangle
GLubyte indices[3]={0,1,2};

//opengl 4
void triangle1(){
  glClear(GL_COLOR_BUFFER_BIT);//clears the screen
  
  glGenVertexArrays(1, &vaoID);//generates object name for Vertex Array Objects
  glBindVertexArray(vaoID);//bind the object to the array

  glGenBuffers(1, &vboID);//generates object name for the Vertex Buffer Object
  glBindBuffer(GL_ARRAY_BUFFER, vboID);//bind the object to the array
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertexarray), vertexarray, GL_STATIC_DRAW);//allocates the memory of the vertices

 ShaderInfo shaders[]={//create the shader specified by my initshaders 
  { GL_VERTEX_SHADER , "vertexshader1.glsl"} ,
  { GL_FRAGMENT_SHADER , "fragmentshader1.glsl"},
  { GL_NONE , NULL} 
  };

  initShaders(shaders);//creates shaders
  
  glEnableVertexAttribArray(0);//enables the vertex attribute index 
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);//specified the start the vertice array used to the draw

  glDrawArrays(GL_TRIANGLES, 0, 3);//draws array
  glFlush();//makes sure the prcesses finish
}

void triangle2(){
/*  glClear(GL_COLOR_BUFFER_BIT);//clear screen

  glGenVertexArrays(1, &vaoID);//generates object name for Vertex Array Objects
  glBindVertexArray(vaoID);//bind the object to the array

  glGenBuffers(1, &vboID);//generates object name for the Vertex Buffer Object
  glBindBuffer(GL_ARRAY_BUFFER, vboID);//bind the object to the array
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertexarray), vertexarray, GL_STATIC_DRAW);//allocates the memory of the vertices

 ShaderInfo shaders[]={//create the shader specified by my initshaders input
  { GL_VERTEX_SHADER , "vertexshader2.glsl"} ,
  { GL_FRAGMENT_SHADER , "fragmentshader2.glsl"},
  { GL_NONE , NULL} 
  };

  initShaders(shaders);//creates shaders
  	  	
  glEnableVertexAttribArray(0);//enables the vertex attribute index 
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);//specified the start the vertice array used to the draw
  
  glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, indices);//draws object based on indices of the polygon
  glDisableVertexAttribArray(0);
  glFlush();//make sure the processes finish*/

static GLfloat currentAngleOfRotation = 0.0;

static bool spinning = true;

glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glRotatef(currentAngleOfRotation, 0.0, 0.0, 1.0);
  glRectf(-.5, -.5, .5, .5);
  glFlush();
  glutSwapBuffers();


}

void myWireSphere(GLfloat radius, int slices, int stacks) {
  glPushMatrix();
  glRotatef(-90.0, 1.0, 0.0, 0.0);
  glutWireSphere(radius, slices, stacks);
  glPopMatrix();
}



void triangle3(){
/*  glClear(GL_COLOR_BUFFER_BIT);//clear screen

  glGenVertexArrays(1, &vaoID);//generates object name for Vertex Array Objects
  glBindVertexArray(vaoID);//bind the object to the array

  glGenBuffers(1, &vboID);//generates object name for the Vertex Buffer Object
  glBindBuffer(GL_ARRAY_BUFFER, vboID);//bind the object to the array
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertexarray), vertexarray,
GL_STATIC_DRAW);//allocates the memory of the vertices

 ShaderInfo shaders[]={//create the shader specified by my initshaders input
  { GL_VERTEX_SHADER , "vertexshader3.glsl"} ,
  { GL_FRAGMENT_SHADER , "fragmentshader3.glsl"},
  { GL_NONE , NULL}
  };

  initShaders(shaders);//creates shaders

  glEnableVertexAttribArray(0);//enables the vertex attribute index 
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);//specified the startthe vertice array used to the draw

  glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, indices);//draws object based on indices of the polygon
  glDisableVertexAttribArray(0);
  glFlush();//make sure the processes finish*/

/*

 // Set every pixel in the frame buffer to the current clear color.
  glClear(GL_COLOR_BUFFER_BIT);

  // Drawing is done by specifying a sequence of vertices.  The way these
  // vertices are connected (or not connected) depends on the argument to
  // glBegin.  GL_POLYGON constructs a filled polygon.
  glBegin(GL_POLYGON);
    glColor3f(1, 0, 0); glVertex3f(-0.6, -0.75, 0.5);
    glColor3f(0, 1, 0); glVertex3f(0.6, -0.75, 0);
    glColor3f(0, 0, 1); glVertex3f(0, 0.75, 0);
  glEnd();
  glBegin(GL_POLYGON);
    glColor3f(1, 0, 0); glVertex3f(0.6, -0.75, 0.5);
    glColor3f(0, 1, 0); glVertex3f(-0.6, 0.75, 0);
    glColor3f(0, 0, 1); glVertex3f(0, -0.75, 0);
  glEnd();

  // Flush drawing command buffer to make drawing happen as soon as possible.
  glFlush();*/


static int year = 0, day = 0;

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPushMatrix();

  // Draw sun: a yellow sphere of radius 1 centered at the origin.
  glColor3f(1.0, 1.0, 0.0);
  myWireSphere(1.0, 15, 15);

  // Draw planet: a blue sphere of radius 0.2, 2 units away from sun, with
  // a white "pole" for its axis.
  glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
  glTranslatef (2.0, 0.0, 0.0);
  glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
  glColor3f(0.0, 0.0, 1.0);
  myWireSphere(0.2, 15, 15);
  glColor3f(1, 1, 1);
  glBegin(GL_LINES);
    glVertex3f(0, -0.3, 0);
    glVertex3f(0, 0.3, 0);
  glEnd();

  glPopMatrix();
  glFlush();
  glutSwapBuffers();


}




void drawscene(){
  switch(counter%3){//easy way to switch throw functions
    case 0:
      glutDisplayFunc(triangle1);
      glutPostRedisplay();//sets flags for opengl to redraw the display
      break;
    case 1:
      glutDisplayFunc(triangle2);
      glutPostRedisplay();
      break;
    case 2:
      glutDisplayFunc(triangle3);
      glutPostRedisplay();
      break;
  }
}
//this function create the interaction with the mouse
void mousepress(int button, int state, int x, int y){
  if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)//right click closes the screen
    exit(0);
  else if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){//left click changes the shape color
    counter++;
    drawscene();
  }
}

void idle(void){
  glutPostRedisplay();
}

int main(int argc, char **argv){
	//Freeglut window and context management	
  glutInit(&argc, argv);
  glutCreateWindow("Shapes");//creates the window with the specified name
  
  //initializes glew
  glewExperimental=GL_TRUE;
  if(glewInit()){
    fprintf(stderr, "Unable to initalize GLEW");
    exit(EXIT_FAILURE);
  }
  
  glutInitContextVersion(4, 3);//specifies the version of opengl
  glutInitContextProfile(GLUT_CORE_PROFILE|GLUT_COMPATIBILITY_PROFILE);//specifies what profile your using


  //retruns what version of opengl and glsl your computer can use
  const GLubyte* version=glGetString(GL_SHADING_LANGUAGE_VERSION);
  fprintf(stderr,"Opengl glsl version %s\n", version);

  version=glGetString(GL_VERSION);
  fprintf(stderr,"Opengl version %s\n", version);

  glutDisplayFunc(drawscene);//displays callback draws the shapes
  glutMouseFunc(mousepress);//control callback specifies the mouse controls
  glutMainLoop();//sets opengl state in a neverending loop
  return 0;
}

