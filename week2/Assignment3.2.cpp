#include <iostream>
#include "graphics.h"

using namespace std;

void DrawRec(double x, double y, double w, double h);
void DrawRuler(double x, double y, double w, double h);

int main()
{
    DrawRec(0,0,4,1);
    DrawRuler(2,0,4,1);
    return 0;
}

void DrawRec(double x, double y, double w, double h)
{
    InitGraphics();
    MovePen(x,y);
    DrawLine(w,0);
    DrawLine(0,h);
    DrawLine(-w,0);
    DrawLine(0,-h);
}

void DrawRuler(double x, double y, double w, double h)
{
    MovePen(x,y);
    DrawLine(0,h);
    MovePen(x-w/4,y);
    DrawLine(0,h/2);
    MovePen(x+w/4,y);
    DrawLine(0,h/2);
    if(w<.2||h<.2)
        return;
    DrawRuler(x-w/4,y,w/2,h/2);
    DrawRuler(x+w/4,y,w/2,h/2);

}

