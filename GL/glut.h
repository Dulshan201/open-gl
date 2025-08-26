#ifndef __GLUT_H__
#define __GLUT_H__

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Display modes */
#define GLUT_RGB                        0
#define GLUT_RGBA                       GLUT_RGB
#define GLUT_INDEX                      1
#define GLUT_SINGLE                     0
#define GLUT_DOUBLE                     2
#define GLUT_ACCUM                      4
#define GLUT_ALPHA                      8
#define GLUT_DEPTH                      16
#define GLUT_STENCIL                    32

/* Mouse buttons */
#define GLUT_LEFT_BUTTON                0
#define GLUT_MIDDLE_BUTTON              1
#define GLUT_RIGHT_BUTTON               2

/* Mouse button state */
#define GLUT_DOWN                       0
#define GLUT_UP                         1

/* Keyboard keys */
#define GLUT_KEY_F1                     1
#define GLUT_KEY_F2                     2
#define GLUT_KEY_F3                     3
#define GLUT_KEY_F4                     4
#define GLUT_KEY_F5                     5
#define GLUT_KEY_F6                     6
#define GLUT_KEY_F7                     7
#define GLUT_KEY_F8                     8
#define GLUT_KEY_F9                     9
#define GLUT_KEY_F10                    10
#define GLUT_KEY_F11                    11
#define GLUT_KEY_F12                    12
#define GLUT_KEY_LEFT                   100
#define GLUT_KEY_UP                     101
#define GLUT_KEY_RIGHT                  102
#define GLUT_KEY_DOWN                   103
#define GLUT_KEY_PAGE_UP                104
#define GLUT_KEY_PAGE_DOWN              105
#define GLUT_KEY_HOME                   106
#define GLUT_KEY_END                    107
#define GLUT_KEY_INSERT                 108

/* Function prototypes */
void glutInit(int *argcp, char **argv);
void glutInitDisplayMode(unsigned int mode);
void glutInitWindowPosition(int x, int y);
void glutInitWindowSize(int width, int height);
int glutCreateWindow(const char *title);
void glutDestroyWindow(int win);
void glutPostRedisplay(void);
void glutSwapBuffers(void);
int glutGetWindow(void);
void glutSetWindow(int win);
void glutSetWindowTitle(const char *title);
void glutSetIconTitle(const char *title);
void glutPositionWindow(int x, int y);
void glutReshapeWindow(int width, int height);
void glutPopWindow(void);
void glutPushWindow(void);
void glutIconifyWindow(void);
void glutShowWindow(void);
void glutHideWindow(void);
void glutFullScreen(void);
void glutSetCursor(int cursor);
void glutWarpPointer(int x, int y);
void glutEstablishOverlay(void);
void glutRemoveOverlay(void);
void glutUseLayer(GLenum layer);
void glutPostOverlayRedisplay(void);
void glutPostWindowOverlayRedisplay(int win);
void glutShowOverlay(void);
void glutHideOverlay(void);
int glutCreateMenu(void (*)(int));
void glutDestroyMenu(int menu);
int glutGetMenu(void);
void glutSetMenu(int menu);
void glutAddMenuEntry(const char *label, int value);
void glutAddSubMenu(const char *label, int submenu);
void glutChangeToMenuEntry(int item, const char *label, int value);
void glutChangeToSubMenu(int item, const char *label, int submenu);
void glutRemoveMenuItem(int item);
void glutAttachMenu(int button);
void glutDetachMenu(int button);
void glutDisplayFunc(void (*func)(void));
void glutReshapeFunc(void (*func)(int width, int height));
void glutKeyboardFunc(void (*func)(unsigned char key, int x, int y));
void glutMouseFunc(void (*func)(int button, int state, int x, int y));
void glutMotionFunc(void (*func)(int x, int y));
void glutPassiveMotionFunc(void (*func)(int x, int y));
void glutEntryFunc(void (*func)(int state));
void glutVisibilityFunc(void (*func)(int state));
void glutIdleFunc(void (*func)(void));
void glutTimerFunc(unsigned int millis, void (*func)(int value), int value);
void glutMenuStateFunc(void (*func)(int state));
void glutSpecialFunc(void (*func)(int key, int x, int y));
void glutSpaceballMotionFunc(void (*func)(int x, int y, int z));
void glutSpaceballRotateFunc(void (*func)(int x, int y, int z));
void glutSpaceballButtonFunc(void (*func)(int button, int state));
void glutButtonBoxFunc(void (*func)(int button, int state));
void glutDialsFunc(void (*func)(int dial, int value));
void glutTabletMotionFunc(void (*func)(int x, int y));
void glutTabletButtonFunc(void (*func)(int button, int state, int x, int y));
void glutMenuStatusFunc(void (*func)(int status, int x, int y));
void glutOverlayDisplayFunc(void (*func)(void));
void glutWindowStatusFunc(void (*func)(int state));
void glutKeyboardUpFunc(void (*func)(unsigned char key, int x, int y));
void glutSpecialUpFunc(void (*func)(int key, int x, int y));
void glutJoystickFunc(void (*func)(unsigned int buttonMask, int x, int y, int z), int pollInterval);
void glutSetColor(int, GLfloat red, GLfloat green, GLfloat blue);
GLfloat glutGetColor(int ndx, int component);
void glutCopyColormap(int win);
int glutGet(GLenum type);
int glutDeviceGet(GLenum type);
int glutExtensionSupported(const char *name);
int glutGetModifiers(void);
int glutLayerGet(GLenum type);
void glutBitmapCharacter(void *font, int character);
int glutBitmapWidth(void *font, int character);
void glutStrokeCharacter(void *font, int character);
int glutStrokeWidth(void *font, int character);
int glutBitmapLength(void *font, const unsigned char *string);
int glutStrokeLength(void *font, const unsigned char *string);
void glutWireSphere(GLdouble radius, GLint slices, GLint stacks);
void glutSolidSphere(GLdouble radius, GLint slices, GLint stacks);
void glutWireCone(GLdouble base, GLdouble height, GLint slices, GLint stacks);
void glutSolidCone(GLdouble base, GLdouble height, GLint slices, GLint stacks);
void glutWireCube(GLdouble size);
void glutSolidCube(GLdouble size);
void glutWireTorus(GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings);
void glutSolidTorus(GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings);
void glutWireDodecahedron(void);
void glutSolidDodecahedron(void);
void glutWireTeapot(GLdouble size);
void glutSolidTeapot(GLdouble size);
void glutWireOctahedron(void);
void glutSolidOctahedron(void);
void glutWireTetrahedron(void);
void glutSolidTetrahedron(void);
void glutWireIcosahedron(void);
void glutSolidIcosahedron(void);
int glutVideoResizeGet(GLenum param);
void glutSetupVideoResizing(void);
void glutStopVideoResizing(void);
void glutVideoResize(int x, int y, int width, int height);
void glutVideoPan(int x, int y, int width, int height);
void glutReportErrors(void);
void glutIgnoreKeyRepeat(int ignore);
void glutSetKeyRepeat(int repeatMode);
void glutForceJoystickFunc(void);
void glutGameModeString(const char *string);
int glutEnterGameMode(void);
void glutLeaveGameMode(void);
int glutGameModeGet(GLenum mode);

void glutMainLoop(void);

#ifdef __cplusplus
}
#endif

#endif /* __GLUT_H__ */
