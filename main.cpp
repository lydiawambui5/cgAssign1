#include <windows.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535897932384626433832795
#define CIRCLE_RADIUS = 0.15f

int circle_points = 100;
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set display window colour to white

    glMatrixMode(GL_PROJECTION); // Set projection parameters
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

void drawHouse(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear display window

    //Set colour to black
    glColor3f(0.0, 0.0, 0.0);
    //Adjust the point size
    glPointSize(5.0);

    // Draw an outlined triangle
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2i(100, 200);
    glVertex2i(100, 50);

    glVertex2i(100, 50);
    glVertex2i(300, 50);

    glVertex2i(300, 50);
    glVertex2i(300, 200);

    glVertex2i(100, 200);
    glVertex2i(50, 200);

    glVertex2i(300, 200);
    glVertex2i(350, 200);

    glVertex2i(50, 200);
    glVertex2i(50, 250);

    glVertex2i(350, 200);
    glVertex2i(350, 250);

    glVertex2i(50, 250);
    glVertex2i(350, 250);

    glEnd();
    //Semicircle roof
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0);
    double radius = 80.0;
    double ori_x = 200.0; // the origin or center of circle
    double ori_y = 250.0;
    for (int i = 0; i <= 300; i++)
    {
        double angle = PI * i / 300;
        double x = cos(angle) * radius;
        double y = sin(angle) * radius;
        glVertex2d(ori_x + x, ori_y + y);
    }
    glEnd();
    //door
    glColor3f(0.5f, 1.0f, 0.0f);
    glBegin(GL_LINES);
    //left

    glVertex2i(170, 150);
    glVertex2i(170, 50);

    //top
    glVertex2i(170, 150);
    glVertex2i(230, 150);

    //right
    glVertex2i(230, 150);
    glVertex2i(230, 50);

    glEnd();

   
    float x, y;
    glColor3f(0.5f, 1.0f, 0.0f);

    glBegin(GL_POINTS);

    for (float angle = 0; angle <= 2 * PI; angle += 0.1)
    {
        x = (.3) * cos(angle);
        y = (.3) * sin(angle);

        glVertex2f(x, y);

    }
    glVertex2f(225, 100);

    glEnd();

    glBegin(GL_LINES); //Left window
    glColor3f(0.5f, 1.0f, 0.0f);
    glVertex2i(115, 200);
    glVertex2i(155, 200);

    glVertex2i(155, 200);
    glVertex2i(155, 170);

    glVertex2i(155, 170);
    glVertex2i(115, 170);

    glVertex2i(115, 170);
    glVertex2i(115, 200);
    glEnd();

    glBegin(GL_LINES); //LW lines
    glColor3f(0.0, 0.0, 1.0);
    glVertex2i(135, 200);
    glVertex2i(135, 170);
    glVertex2i(115, 185);
    glVertex2i(155, 185);
    glEnd();

    glBegin(GL_LINES); //Right window
    glColor3f(0.5f, 1.0f, 0.0f);
    glVertex2i(245, 200);
    glVertex2i(285, 200);

    glVertex2i(285, 200);
    glVertex2i(285, 170);

    glVertex2i(285, 170);
    glVertex2i(245, 170);

    glVertex2i(245, 170);
    glVertex2i(245, 200);
    glEnd();

    glBegin(GL_LINES); //RW lines
    glColor3f(0.0, 0.0, 1.0);
    glVertex2i(265, 200);
    glVertex2i(265, 170);
    glVertex2i(245, 185);
    glVertex2i(285, 185);
    glEnd();

    //moon
   
      

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);                       
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(200, 70);               
    glutInitWindowSize(800, 600);                  
    glutCreateWindow("Assignment1"); 

    init();                      
    glutDisplayFunc(drawHouse); 
    glutMainLoop();             

    return 0;
}
