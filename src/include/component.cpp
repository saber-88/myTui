#include "component.hpp"
#include "colors.hpp"
#include <cstddef>
#include <fmt/base.h>
#include <termios.h>
#include <vector>


// --------------------------------------------
// CONSTRUCTORS
// --------------------------------------------

Tui::Component::Component(){};

Tui::Component::Text::Text(size_t row , size_t col , const std::string& text , FG f , BG b , Style s)
    :t_row(row),t_col(col),t_text(text) , t_fg(f) , t_bg(b) , t_style(s) {};
Tui::Component::Text::Text(const std::string& text , FG f , BG b , Style s) 
    :t_text(text) , t_fg(f) , t_bg(b) , t_style(s) {
        t_row = 99999;
        t_col = 99999;
    };


Tui::Component::Box::Box(size_t row , size_t col , size_t height , size_t width) 
: b_row(row) , b_col(col) , b_height(height) , b_width(width){}


Tui::Component::Box::Box(size_t height , size_t width ): b_height(height) , b_width(width){
    b_row = 99999;
    b_col = 99999;
}

Tui::Component::Square::Square(size_t row , size_t col , size_t side ) 
: s_row(row) , s_col(col) , s_side(side){}


Tui::Component::Square::Square( size_t side ): s_side(side){
    s_row = 99999;
    s_col = 99999;
}


// --------------------------------------------
// DRAW TEXT
// --------------------------------------------


void Tui::Component::Text::drawText(Screen& s) {

    size_t m_cols = s.getCols();
    size_t m_rows = s.getRows();

    if (t_row == 99999 && t_col == 99999) {
        t_row = m_rows / 2;
        t_col = (m_cols - t_text.size()) / 2;
    }
    
    std::vector<Cell>& buff = s.getBackBuffer();
    
    auto putChar = [&](size_t idx, const std::string& str , size_t i , FG f , BG b ) {
        
        buff[idx].cellItem = str[i];
        buff[idx].fg = f;
        buff[idx].bg = b;
    };
    
    for (size_t i {0}; i < t_text.size() && t_col + i < m_cols; ++i) {
        size_t idx = t_row * m_cols + t_col + i;
            putChar(idx, t_text , i ,this->t_fg , this->t_bg);
    }
}

// --------------------------------------------
// DRAW BOX
// --------------------------------------------


void Tui::Component::Box::drawBox(Screen& s) {
    size_t m_cols = s.getCols();
    size_t m_rows = s.getRows();

    if (b_row == 99999 && b_col == 99999) {
        b_row = (m_rows - b_height) / 2;
        b_col = (m_cols - b_width) / 2;
    }

    auto& buff = s.getBackBuffer();

    auto putChar = [&](size_t r, size_t c, const std::string& ch) {
        size_t idx = r * m_cols + c;
        buff[idx].cellItem = ch;
    };

    for (size_t r = 0; r < b_height; ++r) {
        for (size_t c = 0; c < b_width; ++c) {

            if (r == 0 && c == 0)
                putChar(b_row + r, b_col + c, "┌");

            else if (r == 0 && c == b_width - 1)
                putChar(b_row + r, b_col + c, "┐");

            else if (r == b_height - 1 && c == 0)
                putChar(b_row + r, b_col + c, "└");
            
            else if (r == b_height - 1 && c == b_width - 1)
                putChar(b_row + r, b_col + c, "┘");
            
            else if (r == 0 || r == b_height - 1)
                putChar(b_row + r, b_col + c, "─");

            else if (c == 0 || c == b_width - 1)
                putChar(b_row + r, b_col + c, "│");

            else
                putChar(b_row + r, b_col + c, " ");
        }
    }
}


// --------------------------------------------
// DRAW SQUARE
// --------------------------------------------

void Tui::Component::Square::drawSquare(Screen& s) {
    size_t m_cols = s.getCols();
    size_t m_rows = s.getRows();

    if (s_row == 99999 && s_col == 99999) {
        s_row = (m_rows - s_side) / 2;
        s_col = (m_cols - s_side * 2) / 2;
    }

    auto& buff = s.getBackBuffer();

    auto putChar = [&](size_t r, size_t c, const std::string& ch) {
        size_t idx = r * m_cols + c;
        buff[idx].cellItem = ch;
    };
    size_t s_height = s_side;
    size_t s_width = s_side * 2;
    for (size_t r = 0; r < s_height; ++r) {
        for (size_t c = 0; c < s_width; ++c) {

            if (r == 0 && c == 0)
                putChar(s_row + r, s_col + c, "┌");

            else if (r == 0 && c == s_width - 1)
                putChar(s_row + r, s_col + c, "┐");

            else if (r == s_height - 1 && c == 0)
                putChar(s_row + r, s_col + c, "└");
            
            else if (r == s_height - 1 && c == s_width - 1)
                putChar(s_row + r, s_col + c, "┘");
            
            else if (r == 0 || r == s_height - 1)
                putChar(s_row + r, s_col + c, "─");

            else if (c == 0 || c == s_width - 1)
                putChar(s_row + r, s_col + c, "│");

            else
                putChar(s_row + r, s_col + c, " ");
        }
    }
}
