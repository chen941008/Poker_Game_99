#include <algorithm>
#include <iostream>
#include <limits>
#include <random>
#include <vector>

#include "game.hpp"  // 為了使用 Game::getInstance()
#include "poker.hpp"
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    // 取得標準輸出控制台的句柄
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    // 取得當前模式
    if (GetConsoleMode(hOut, &dwMode)) {
        // 啟用虛擬終端機處理
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);
    }
#endif
    Game &game = Game::getInstance();
    game.runGame();
    return 0;
}
