#include <iostream>
#include "grid.h"

using namespace std;

enum pixelStateT { White, Black };
struct pointT {
    int row, col;
};

void FillRegion(pointT pt, Grid<pixelStateT> &screen);

int main()
{
    Grid<pixelStateT> screen(30,30);
    pointT point={5,5};
    FillRegion(point,screen);
    return 0;
}

void FillRegion(pointT pt, Grid<pixelStateT> &screen)
{
    if(screen(pt.row,pt.col)==Black)
        return;
    if(!screen.inBounds(pt.row, pt.col))
        return;
    screen(pt.row,pt.col)=Black;
    pointT north = {pt.row, pt.col + 1};
    FillRegion(north, screen);
    pointT south = {pt.row, pt.col - 1};
    FillRegion(south, screen);
    pointT east = {pt.row + 1, pt.col};
    FillRegion(east, screen);
    pointT west = {pt.row - 1, pt.col};
    FillRegion(west, screen);
}
