#include "gl_renderer.hpp"
#include "win_app.hpp"
#include <gl/GL.h>

HDC g_hDC;
HGLRC g_hRC;

bool InitOpenGL() {
    HWND hWnd = GetMainWindowHandle();
    g_hDC = GetDC(hWnd);

    PIXELFORMATDESCRIPTOR pfd = {
        sizeof(PIXELFORMATDESCRIPTOR), 1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA, 32, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,
        24, 8, 0,
        PFD_MAIN_PLANE, 0, 0, 0, 0
    };

    int pf = ChoosePixelFormat(g_hDC, &pfd);
    SetPixelFormat(g_hDC, pf, &pfd);

    g_hRC = wglCreateContext(g_hDC);
    wglMakeCurrent(g_hDC, g_hRC);

    glEnable(GL_DEPTH_TEST);
    return true;
}

void RenderFrame() {
    glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex3f(-0.5f, -0.5f, -1);
    glVertex3f(0.5f, -0.5f, -1);
    glVertex3f(0.5f, 0.5f, -1);
    glVertex3f(-0.5f, 0.5f, -1);
    glEnd();

    SwapBuffers(g_hDC);
}
