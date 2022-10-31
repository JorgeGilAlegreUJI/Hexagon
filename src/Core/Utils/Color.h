//
// Created by jorge on 27/10/2022.
//

#ifndef HEXAGON_COLOR_H
#define HEXAGON_COLOR_H
namespace Core {

    struct Color {
        Color(int r,int g,int b,int a);
        Color(int r,int g,int b);
        Color(float r, float g, float b, float a);

        Color(float r, float g, float b);

        int r,g,b,a;
    };

} // Core

#endif //HEXAGON_COLOR_H
