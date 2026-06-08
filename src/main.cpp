#include <cstdio>
#include <unistd.h>

#include "../include/colors.hpp"
#include "../include/component.hpp"
#include "../include/screen.hpp"

using namespace Tui;

void drawStuff(Screen &frame) {
  Component::Box box(5, 11, 30, 10, FG::Green, BG::Green);
  Component::Box box1(5, 40, 30, 10, FG::Green, BG::Green);
  box.drawBox(frame);
  box1.drawBox(frame);

  int j = 11;
  for (int i = 5; i < 35; i++) {
    Component::Box tbox(i, j, 1, 10, FG::Green, BG::Green);
    j++;
    tbox.drawBox(frame);
  }
}

int main() {

  Screen frame;     // making a frame to draw on
  frame.init(true); // initializing the frame
  drawStuff(frame);
  frame.render();

}
