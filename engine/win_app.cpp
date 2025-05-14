#include "win_app.hpp"

HWND g_hWnd;

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (msg == WM_DESTROY) {
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

bool CreateMainWindow(HINSTANCE hInstance, int nCmdShow) {
    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "Simple3DEngineClass";
    RegisterClass(&wc);

    g_hWnd = CreateWindow("Simple3DEngineClass", "Simple 3D Engine",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        nullptr, nullptr, hInstance, nullptr);

    if (!g_hWnd) return false;

    ShowWindow(g_hWnd, nCmdShow);
    return true;
}

HWND GetMainWindowHandle() {
    return g_hWnd;
}
