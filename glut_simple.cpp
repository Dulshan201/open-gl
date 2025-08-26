#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

extern "C" {

static HWND hWnd;
static HDC hDC;
static HGLRC hRC;
static bool running = true;
static void (*displayFunc)(void) = NULL;

void glutInit(int *argcp, char **argv) {
    // Minimal initialization
}

void glutInitDisplayMode(unsigned int mode) {
    // Store display mode (not implemented)
}

void glutInitWindowPosition(int x, int y) {
    // Store window position (not implemented)
}

void glutInitWindowSize(int width, int height) {
    // Store window size (not implemented)
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CLOSE:
            running = false;
            PostQuitMessage(0);
            return 0;
        case WM_PAINT:
            if (displayFunc) {
                displayFunc();
                SwapBuffers(hDC);
            }
            break;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int glutCreateWindow(const char *title) {
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "OpenGLWindow";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    
    RegisterClass(&wc);
    
    hWnd = CreateWindowEx(0, "OpenGLWindow", title,
                         WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                         100, 100, 500, 500,
                         NULL, NULL, GetModuleHandle(NULL), NULL);
    
    if (!hWnd) return 0;
    
    hDC = GetDC(hWnd);
    
    PIXELFORMATDESCRIPTOR pfd = {};
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    
    int pixelFormat = ChoosePixelFormat(hDC, &pfd);
    SetPixelFormat(hDC, pixelFormat, &pfd);
    
    hRC = wglCreateContext(hDC);
    wglMakeCurrent(hDC, hRC);
    
    return 1;
}

void glutDisplayFunc(void (*func)(void)) {
    displayFunc = func;
}

void glutMainLoop(void) {
    MSG msg;
    while (running) {
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        
        if (displayFunc) {
            displayFunc();
            SwapBuffers(hDC);
        }
        
        Sleep(16); // ~60 FPS
    }
    
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hWnd, hDC);
    DestroyWindow(hWnd);
}

void glutSwapBuffers(void) {
    SwapBuffers(hDC);
}

void glutPostRedisplay(void) {
    InvalidateRect(hWnd, NULL, FALSE);
}

void glutTimerFunc(unsigned int millis, void (*func)(int value), int value) {
    // Simple timer implementation - just call the function immediately for now
    if (func) {
        func(value);
    }
}

void glutReshapeFunc(void (*func)(int width, int height)) {
    // Store reshape function (not fully implemented)
}

void glutKeyboardFunc(void (*func)(unsigned char key, int x, int y)) {
    // Store keyboard function (not fully implemented)
}

void glutSpecialFunc(void (*func)(int key, int x, int y)) {
    // Store special keys function (not fully implemented)
}

} // extern "C"
