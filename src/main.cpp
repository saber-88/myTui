#include <cstddef>
#include <cstdio>
#include <unistd.h>

#include "../include/colors.hpp"
#include "../include/component.hpp"
#include "../include/screen.hpp"

using namespace Tui;

int main() {

  Screen frame;     // making a frame to draw on
  frame.init(true); // initializing the frame
  frame.hideCursor();

  size_t maxRows = frame.getRows();

  Component::Box box(5,11,30,10,FG::Red,BG::Red);
  Component::Box box1(5,40,30,10,FG::Red,BG::Red);

  Component::Box kbox(5,60,30,10,FG::Red,BG::Red);

  kbox.drawBox(frame);
  box.drawBox(frame);
  box1.drawBox(frame);

  int j = 11;
  for (int i = 5; i < 35; i++) {
    Component::Box tbox(i,j,1,10,FG::Red,BG::Red);
    j++;
    tbox.drawBox(frame);
  }
  frame.render();
  getchar();

  frame.showCursor();
}
