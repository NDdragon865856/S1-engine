#include "engine/win_app.hpp"
#include "engine/game_loop.hpp"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    if (!CreateMainWindow(hInstance, nCmdShow)) return 0;
    if (!InitOpenGL()) return 0;

    RunGameLoop();

    return 0;
}
