#include "colors.hpp"
#include "component.hpp"
#include "screen.hpp"
// #include "tui.hpp"
#include <cstdio>
#include <fmt/color.h>
#include <unistd.h>


int main() {
    
    
    Tui::Screen myScreen(true);
    myScreen.hideCursor();
    
    Tui::Component::Text text("Hello World" , Tui::FG::Yellow , Tui::BG::Red , Tui::Style::Bold);
    Tui::Component::Text text2("Hello Izumi" , Tui::FG::Cyan , Tui::BG::Default , Tui::Style::Bold);
    text.drawText(myScreen);
    myScreen.render();
    myScreen.clearScreen();
    getchar();
    myScreen.render();
    getchar();

}
