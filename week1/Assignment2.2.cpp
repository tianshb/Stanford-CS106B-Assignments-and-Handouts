#include <iostream>
#include "maze.h"
#include "vector.h"
#include "stack.h"
#include "random.h"
#include "grid.h"
#include "queue.h"

using namespace std;


Maze generate_maze(int row,int column);
void solve_maze(Maze maze);void solve_maze(Maze maze);

int main()
{
    Maze maze=generate_maze(10,10);
    solve_maze(maze);
    return 0;
}


Maze generate_maze(int row,int column)
{

    Maze maze(row,column,true);
    maze.draw();
    Grid<Vector<pointT>> direction(row,column);
    Grid<bool> grid(row,column);

    for(int i=0;i<row;i++)
    {
       for(int j=0;j<column;j++)
        {

            pointT P0={i+1,j};
            pointT P1={i,j+1};
            pointT P2={i-1,j};
            pointT P3={i,j-1};
            if(maze.pointInBounds(P0))
            {
                direction[i][j].add(P0);
            }
            if(maze.pointInBounds(P1))
            {
                direction[i][j].add(P1);
            }
            if(maze.pointInBounds(P2))
            {
                direction[i][j].add(P2);
            }
            if(maze.pointInBounds(P3))
            {
                direction[i][j].add(P3);
            }
            grid[i][j]=false;
        }
    }
    pointT current={0,0};
    grid[0][0]=true;
    int count=0;
    while(true)
    {
            pointT neighbor=direction[current.row][current.col].getAt(RandomInteger(0,direction[current.row][current.col].size()));
            if(!grid[neighbor.row][neighbor.col])
            {
                maze.setWall(current, neighbor, false);
                grid[neighbor.row][neighbor.col]=true;
                if(++count>=grid.numRows()*grid.numCols()-1)
                    break;
            }
            current=neighbor;
    }
    return maze;

}

void solve_maze(Maze maze)
{
    int row=maze.numRows();
    int column=maze.numCols();
    Queue<Stack<pointT>> stepsqueue;
    Grid<Vector<pointT>> direction(row,column);
    Grid<bool> grid(row,column);

    for(int i=0;i<row;i++)
    {
       for(int j=0;j<column;j++)
        {

            pointT P0={i+1,j};
            pointT P1={i,j+1};
            pointT P2={i-1,j};
            pointT P3={i,j-1};
            if(maze.pointInBounds(P0))
            {
                direction[i][j].add(P0);
            }
            if(maze.pointInBounds(P1))
            {
                direction[i][j].add(P1);
            }
            if(maze.pointInBounds(P2))
            {
                direction[i][j].add(P2);
            }
            if(maze.pointInBounds(P3))
            {
                direction[i][j].add(P3);
            }
            grid[i][j]=false;
        }
    }
    pointT start={0,0};
    pointT goal={row-1,column-1};
    Stack<pointT> line;
    line.push(start);
    stepsqueue.enqueue(line);
    while(true)
    {
        Stack<pointT> tempstack=stepsqueue.dequeue();
        pointT stacktop=tempstack.peek();
        if(stacktop.col==goal.col&&stacktop.row==goal.row)
        {
            while(!tempstack.isEmpty())
            {
                maze.drawMark(tempstack.pop(),"Red");
            }
            break;
        }
        else
        {
            for(int i=0;i<direction[stacktop.row][stacktop.col].size();i++)
            {
                pointT neighbor=direction[stacktop.row][stacktop.col].getAt(i);

                if ((!maze.isWall(stacktop,neighbor ))&&(!grid[neighbor.row][neighbor.col]))
                {
                    tempstack.push(neighbor);
                    stepsqueue.enqueue(tempstack);
                    grid[stacktop.row][stacktop.col]=true;
                    tempstack.pop();
                }
            }
        }
    }

}
