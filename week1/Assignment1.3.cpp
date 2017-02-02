#include <iostream>
#include "graphics.h"
#include "extgraph.h"
#include "random.h"
#include "vector.h"

using namespace std;

struct point{
    double x;
    double y;
};

void draw();

int main()
{
    draw();
    return 0;
}

void draw()
{
    InitGraphics();
    Vector<point> points;

    point A;
    point B;
    point C;

    WaitForMouseDown();
    if(MouseButtonIsDown())
    {
        A.x=GetMouseX();
        A.y=GetMouseY();
        points.add(A);
    }
    WaitForMouseUp();
    WaitForMouseDown();
    if(MouseButtonIsDown())
    {
        B.x=GetMouseX();
        B.y=GetMouseY();
        points.add(B);
    }
    WaitForMouseUp();
    WaitForMouseDown();
    if(MouseButtonIsDown())
    {
        C.x=GetMouseX();
        C.y=GetMouseY();
        points.add(C);
    }
    WaitForMouseUp();
    MovePen(points[0].x,points[0].y);
    DrawLine(points[1].x-points[0].x,points[1].y-points[0].y);
    DrawLine(points[2].x-points[1].x,points[2].y-points[1].y);
    DrawLine(points[0].x-points[2].x,points[0].y-points[2].y);


    int random1=RandomInteger(0,3);

    MovePen(points[random1].x,points[random1].y);
    StartFilledRegion();
    DrawArc(0.05,0,360);
    EndFilledRegion();
    while(!MouseButtonIsDown())
    {
        int random2=RandomInteger(0,3);
        double currentx=GetCurrentX();
        double currenty=GetCurrentY();

        MovePen((points[random2].x+currentx)/2,(points[random2].y+currenty)/2);
        StartFilledRegion();
        DrawArc(0.05,0,360);
        EndFilledRegion();
    }

}
