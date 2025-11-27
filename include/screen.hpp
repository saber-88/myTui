#pragma once

#include "cell.hpp"
#include <cstddef>
#include <termios.h>
#include <vector>

namespace Tui {
    class Screen {
        
        public:
        
        Screen();
        ~Screen();
        
        void init(bool altBuffer);
        void exit();
        void clear();                                                   // clear screen
        size_t getRows();                                               // get number of rows of terminal screen
        size_t getCols();                                               // get number of columns of terminal screen
        void updateSize();
        void checkResize();
        std::vector<Cell>& getBackBuffer();
        void hideCursor();
        void showCursor();
        void clearScreen();
        void render();
        
        
        
        private:
        
        static size_t m_rows;
        static size_t m_cols;
        termios og_tio ,raw_tio;
        bool m_altBuffer , m_initScreen;
        std::vector<Cell> frontBuffer;
        std::vector<Cell> backBuffer;
        
    };
    
}