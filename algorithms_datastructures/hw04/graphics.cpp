#include <iostream>
#include <chrono>
#include "glut.h"
#include "graphics.h"

static int window_id, window_xsize, window_ysize;
static std::chrono::time_point<std::chrono::system_clock> timer_last;
static double window_scale = 1.0;
static void (*my_render)(void);
static void (*my_keyhandler)(int key);
static bool (*my_timerhandler)(int msec);

static void gr_set_orientation(void) {
  
  float x, y, z;
  
  glLoadIdentity();
  gluLookAt(x,y,z,   /* Camera location */
	    0,0,0,   /* Looking at the origin */
	    0,0,1);  /* Which direction is up */
  glutPostRedisplay();
}

static void gr_change_size(int w, int h)
{
  /* Avoid divide by zero */
  if(h == 0) h = 1;
  
  /* Reset the coordinate system before modifying */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
  /* Set the viewport to be the entire window */
  glViewport(0, 0, w, h);
  
  /* Set the clipping volume */
  gluPerspective( 45,				/* Angle of field of view */
		  (float)w / h,   /* Aspect ratio */
		  1,              /* Near clipping distance */
		  100000);        /* Far clipping distance */
  
  glMatrixMode(GL_MODELVIEW);
  gr_set_orientation();
  
  window_xsize = w;
  window_ysize = h;
}

void gr_set_orthographic_projection( void )
{
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0, window_xsize, 0, window_ysize);
  glScalef(1, -1, 1);
  glTranslatef(0, -window_ysize, 0);	
  glMatrixMode(GL_MODELVIEW);
}

void gr_reset_perspective_projection( void )
{
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
}

void gr_process_normal_keys(unsigned char key, int x, int y)
{
  my_keyhandler(key);
  glutPostRedisplay();
}

void gr_process_special_keys(int key, int x, int y)
{
  my_keyhandler(key | 0x100);
  glutPostRedisplay();		
}

/*
void gr_drawtext( float x, float y, void *font, char *string) {  

  glRasterPos2f(x, y);
  for (; *string; string++) {
    glutBitmapCharacter(font, *string);
  }
}
*/

void set_color(int r, int g, int b)
{
  glColor3f(r/256.0,g/256.0,b/256.0);
  
}

void draw_line (int x1, int y1, int x2, int y2)
{
  glBegin(GL_LINES);
  glVertex2f(x1*window_scale,y1*window_scale);
  glVertex2f(x2*window_scale,y2*window_scale);
  glEnd();
}

void draw_pixel (int x, int y)
{
  glBegin(GL_LINES);
  glVertex2f(x,y);
  glVertex2f(x+1,y);
  glEnd();
}

void gr_render( void )
{
  static char buff[1000];
  static int cursor_pos = 0;
  int i, j, screen_lines, lines;
  
  /* Clear depth buffer */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  gr_set_orthographic_projection();
  glPushMatrix();
  glLoadIdentity();

  /*
  glColor3f(0.2f, 0.2f, 0.4f);
  glBegin(GL_QUADS);
  glVertex3f(-100.0f, -100.0f, -50);
  glVertex3f(-100.0f, 100.0f, -50);
  glVertex3f( 100.0f, 100.0f, -50);
  glVertex3f( 100.0f, -100.0f, -50);
  glEnd();
  */

  my_render();
 
  glPopMatrix();
  gr_reset_perspective_projection();

  glFlush();
  glutSwapBuffers();
}

void gr_timerhandler(int v) {

  std::chrono::time_point<std::chrono::system_clock> timer_current;
  timer_current = std::chrono::system_clock::now();
  std::chrono::duration<double> time_elapsed = timer_current - timer_last;
  if (my_timerhandler((int)(time_elapsed.count() * 1000))) glutPostRedisplay();
  timer_last = timer_current;
  glutTimerFunc(30, gr_timerhandler, 0);
}

int init_graphics(int argc, char **argv,
		  int window_xsize, int window_ysize,
		  void (* render)(void),
		  void (* keyhandler)(int key),
		  bool (* timerhandler)(int msec))
{
  my_render = render;
  my_keyhandler = keyhandler;
  my_timerhandler = timerhandler;
  
  glutInit(&argc, argv);
  glEnable(GL_DEPTH_TEST);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(20,20);
  glutInitWindowSize(window_xsize, window_ysize);
  window_id = glutCreateWindow("Graphics");
	
  glutSetWindow( window_id );
  glutReshapeFunc( gr_change_size ); 
  glutDisplayFunc( gr_render ); 
  glutKeyboardFunc( gr_process_normal_keys );
  glutSpecialFunc( gr_process_special_keys );
  glutTimerFunc(500, gr_timerhandler, 0);

  timer_last = std::chrono::system_clock::now();
  
  glutMainLoop();
  return 0;
}

