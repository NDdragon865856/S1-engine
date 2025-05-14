#include "game_loop.hpp"
#include "gl_renderer.hpp"
#include <windows.h>

void RunGameLoop() {
    MSG msg = {};
    while (msg.message != WM_QUIT) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        } else {
            RenderFrame();
        }
    }
}
