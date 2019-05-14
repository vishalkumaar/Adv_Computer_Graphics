#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>

const int screenHeight = 480;
const int screenWidth = 640;

void exit(int);

void Init(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(4.0);
    glLineWidth(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
}


//Refreshes the screen whenever this function gets called.
//This makes sure that we get all the objects on the same screen instead of just one!

void Refresh(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void P(void) //Function to draw a POINT !
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,0.0f,1.0f);
    glBegin(GL_POINTS);
    glVertex2f(0,0);
    glEnd();
    glFlush();
    glPointSize(5.0);
}

void L(void) //Function to draw a Line!
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    float x1 = 0.0, x2 = 0;
    float y1 =0.0,y2= 0.5;
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
    glFlush();
}

void T(void) //Function to draw a Triangle!
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f,1.0f,1.0f);
    glBegin(GL_TRIANGLES);
    float x1 = -0.5 , x2 =0.5 ,x3 = -0.1;
    float y1 =-0.5 , y2 =-0.5 ,y3 = 0.15;
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);

/*glBegin(GL_TRIANGLES);
glColor3f(0.1, 0.2, 0.3);
glVertex3f(0, 0, 0);
glVertex3f(1, 1, 0);
glVertex3f(0, 1, 0);
glEnd();
*/
    glEnd();
    glFlush();
}

void S(void) //Function to draw a square!
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.25f,0.5f,1.0f);
    glBegin(GL_POLYGON);
    float x[] = {-0.25, -0.25,0.25,0.25};
    float y[]={-0.25,0.25,0.25,-0.25};
    for(int i=0;i<4 ;i++)
    {
      glVertex2f(x[i],y[i]);
    }
    glEnd();
    glFlush();
}

void H(void) //Function to draw a Hexagon!
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f,0.0f,1.0f);
    glBegin(GL_POLYGON);

//  float  y[6] = {-0.5, -0.25, 0.25 , 0.5, 0.25,-0.25};
//  float x[6] = {0.0,0.5,0.5,0.0 ,-0.5,-0.5};

    float y[6] = {-0.5,-0.25,0.25,0.5,0.25,-0.25};
    float x[6] = {0.0,0.25,0.25,0.0,-0.25,-0.25};

//float y[6] = {-0.5,-0.5,0.50,0.5,0.50,-0.5};
//float x[6] = {0.0,0.5,0.5,0.0,-0.5,-0.5};

//float y[6] = {-0.25,-0.5,0.50,0.25,0.50,-0.5};
//float x[6] = {0.0,0.25,0.25,0.0,-0.25,-0.25};



    for(int i=0;i<6;i++)
    {
      glVertex2f(x[i],y[i]);
    }
    glEnd();
    glFlush();
}


void C(void) //Function to draw a Circle!
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0f,1.0f,0.0f);
  glBegin(GL_POLYGON);
  float a = 0.0;
  float b = 0.0;
  float r = 1.0;

  float segments = 100.0;

  for(int i=0;i<segments;i++)
  {
    float theta = 2.0f*3.14*float(i)/segments;
    float x = r*cosf(theta);
    float y = r*sinf(theta);
    glVertex2f(x+a,y+b);
  }

  glEnd();
  glFlush();
}


void U(void) //Function to draw a Cube!
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINES);  //Used GL_LINES to draw the cube!!
  glColor3f(0.0f,1.0f,0.0f);
  glVertex2f(-0.5,-0.25);
  glVertex2f(0.0,0.25);
  glVertex2f(0.5,-0.25);
  glVertex2f(0.0,-0.75);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(0.0f,0.0f,0.0f);
  glVertex2f(0.0,0.25);
  glVertex2f(0.0,0.75);
  glVertex2f(-0.5,0.25);
  glVertex2f(-0.5,-0.25);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(1.0f,0.0f,0.0f);
  glVertex2f(0.0,0.75);
  glVertex2f(-0.5,0.25);
  glVertex2f(0.0,-0.25);
  glVertex2f(0.5,0.25);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(1.0f,0.0f,1.0f);
  glVertex2f(0.0,0.75);
  glVertex2f(0.5,0.25);
  glVertex2f(0.0,-0.75);
  glVertex2f(-0.5,-0.25);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(0.0f,1.0f,1.0f);
  glVertex2f(0.0,-0.25);
  glVertex2f(-0.5,0.25);
  glVertex2f(0.5,-0.25);
  glVertex2f(0.0,0.25);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(0.0f,1.0f,0.0f);
  glVertex2f(0.50,-0.25);
  glVertex2f(0.50,0.25);
  glVertex2f(0.0,-0.25);
  glVertex2f(0.0,-0.75);
  glEnd();

  glFlush();

}




void Keyboard(unsigned char Key,int mouseX,int mouseY)
{
  switch (Key)
  {
    case 'P':
      P();  //Displays a Point.
      break;
    case 'L':
      L();  //Displays a Line.
      break;
    case 'T':
      T();  //Displays a Triangle.
      break;
    case 'S':
      S();  //Displays a Square.
      break;
    case 'H':
      H();  //Displays a Hexagon.
      break;
    case 'C':
      C();  //Displays a Circle.
      break;
    case 'U':
      U();  //Displays a Cube.
      break;
    case 'Q':
    case 'q':
          exit(-1);
    default:
      break;
  }
}


int main(int argc,char** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(screenWidth,screenHeight);
  glutInitWindowPosition(300,30);
  glutCreateWindow("01 -- Vishal -- ACG -- Please type Q or q to quit");
  glutDisplayFunc(Refresh);
  glutKeyboardFunc(Keyboard);
  Init();
  glutMainLoop();
}
