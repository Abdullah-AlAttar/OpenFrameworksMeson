#pragma once
#include <ofxGui.h>

namespace sq {

class GuiManager {
public:
  ofxPanel gui;

  ofxFloatSlider radius;
  ofxButton button;
  ofxIntSlider countX;
  ofxFloatSlider stepX;
  ofxFloatSlider twistX;
};
} // namespace sq