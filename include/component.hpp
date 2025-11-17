#pragma once

#include "screen.hpp"
#include "colors.hpp"

#include <cstddef>
#include <string>

namespace Tui {
        class Component {
        
        public:
        
        Component();
        
        
        class Text{
            
            public:
            Text() = delete;
            Text(size_t row , size_t col , const std::string& text , FG f , BG b , Style s);
            Text(const std::string& text, FG f , BG b , Style s);
            void drawText( Screen& s);
            
            bool hasUnicode(const std::string& s);
            size_t utf8CharLen(unsigned char c);
            size_t countUtf8Chars(const std::string& s);

            private:
            size_t t_row , t_col;
            FG t_fg;
            BG t_bg;
            Style t_style;
            std::string t_text;
        };
        
        class Box{
            
            public:
            
            Box(size_t row , size_t col , size_t height , size_t width);
            Box( size_t height , size_t width);
            
            void drawBox( Screen& s);
            
            private:
            size_t b_row , b_col , b_height , b_width;
        };
        class Square{
            
            public:
            
            Square(size_t row , size_t col , size_t side );
            Square( size_t side);
            
            void drawSquare( Screen& s);
            
            private:
            size_t s_row , s_col , s_side ;
        };
        
    };
}