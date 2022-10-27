//
// Created by jorge on 27/10/2022.
//

#include "Color.h"
#include <cmath>

namespace Core {
    Color::Color(int r, int g, int b, int a) : r(r),g(g),b(b),a(a){}
    Color::Color(int r, int g, int b) : Color(r,g,b,255){}
    Color::Color(float r, float g, float b,float  a) : Color((int)std::round(r*255),
                                                             (int)std::round(g*255),
                                                             (int)std::round(b*255),
                                                             (int)std::round(a*255)){}

    Color::Color(float r, float g, float b) : Color((int)std::round(r*255),
                                                             (int)std::round(g*255),
                                                             (int)std::round(b*255),
                                                             255){}
} // Core