#include "colors.hpp"
#include "component.hpp"
#include "screen.hpp"
// #include "tui.hpp"
#include <cstddef>
#include <cstdio>


int main() {
    
    Tui::Screen login_frame;
    Tui::Screen second_frame;
    login_frame.init(true);
    login_frame.hideCursor();
    
    size_t n_half_cols = login_frame.getCols() / 2;
    std::string text  = "Name      : ";
    std::string text2 = "Age       : ";
    std::string text3 = "Email     : ";
    std::string text4 = "Password  : ";
    size_t horizontal_centre = n_half_cols - (text.size() / 2);
    
    Tui::Component::Square container(20 , Tui::FG::Black , Tui::BG::Black);
    Tui::Component::Text login(17 , n_half_cols - 3 ,"LOGIN", Tui::FG::Cyan , Tui::BG::Black , Tui::Style::Bold);
    
    Tui::Component::Text name(20 ,horizontal_centre - 10,text,Tui::FG::Cyan , Tui::BG::Black , Tui::Style::None);
    Tui::Component::Box name_input(19, n_half_cols - 3, 3 ,20 ,Tui::FG::Cyan , Tui::BG::Black);
    
    Tui::Component::Text age(23 ,horizontal_centre - 10,text2,Tui::FG::Cyan , Tui::BG::Black , Tui::Style::None);
    Tui::Component::Box age_input(22, n_half_cols - 3, 3 ,20 ,Tui::FG::Cyan , Tui::BG::Black);
    
    Tui::Component::Text email(26 ,horizontal_centre - 10,text3,Tui::FG::Cyan , Tui::BG::Black , Tui::Style::None);
    Tui::Component::Box email_input(25, n_half_cols - 3, 3 ,20 ,Tui::FG::Cyan , Tui::BG::Black);
    
    Tui::Component::Text password(29 ,horizontal_centre - 10,text4,Tui::FG::Cyan , Tui::BG::Black , Tui::Style::None);
    Tui::Component::Box password_input(28, n_half_cols - 3, 3 ,20 ,Tui::FG::Cyan , Tui::BG::Black);
    
    container.drawSquare(login_frame);
    login.drawText(login_frame);
    
    name.drawText(login_frame);
    name_input.drawBox(login_frame);
    
    age.drawText(login_frame);
    age_input.drawBox(login_frame);
    
    email.drawText(login_frame);
    email_input.drawBox(login_frame);
    
    password.drawText(login_frame);
    password_input.drawBox(login_frame);
    
    login_frame.render();
    getchar();
    login_frame.exit();
    
    second_frame.init(true);
    
    

}
