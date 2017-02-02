/* pathfinder.cpp
 * ---------------
 * A starter file with some helpful #defines and handy utility routines.
 */

#include "genlib.h"
#include "extgraph.h"
#include <iostream>
#include "pqueue.h"
#include "vector.h"
#include "set.h"
#include <fstream>
#include "stdlib.h"
#include "stack.h"
#include <math.h>




#define CIRCLE_RADIUS .05     // the radius of a node
#define FONT_SIZE 9           // for node name labels
#define ARC_COLOR "Dark gray" // normal arc color
#define NODE_COLOR "Black"    // normal node color
#define HIGHLIGHT_COLOR "Red" // color of chosen path/nodes
#define PAUSE_TIME .02		  // time to pause when animating algorithm

using namespace std;
/* Type: coordT
 * ------------
 * Just a simple struct to handle a pair of x,y coordinate values.
 */
struct coordT {
	double x, y;
};

struct nodeT; // this is a forward reference

struct arcT {
       // arc fields (distance, cost, etc.)
     nodeT *start, *end1;
     int distance;
 };

 struct nodeT {
       // node fields (name, etc.)
     Vector<arcT *> outgoing;
     string name;
     coordT coordinate;
     Set<nodeT *> joints;
 };

/* Function: DrawFilledCircleWithLabel
 * Usage:  DrawFilledCircleWithLabel(center, .25, "Green", "You are here");
 * -----------------------------------------------------------------------
 * Uses facilities from extgraph to draw a circle filled with
 * color specified. The circle is centered at the given coord has the
 * specified radius.  A label is drawn to the right of the circle.
 * If you don't want a label, pass the empty string.
 */
void DrawFilledCircleWithLabel(coordT center, double radius, string color, string label)
{
	MovePen(center.x + radius, center.y);
	SetPenColor(color);
	StartFilledRegion(1.0);
	DrawArc(radius, 0, 360);
	EndFilledRegion();
	MovePen(center.x + radius, center.y);
	SetFont("Helvetica");
	SetPointSize(FONT_SIZE);
	DrawTextString(label);
}

/* Function: DrawLineBetween
 * Usage:  DrawLineBetween(coord1, coord2, "Black");
 * -------------------------------------------------
 * Uses facilities from extgraph to draw a line of the
 * specified color between the two given coordinates.
 */
void DrawLineBetween(coordT start, coordT end1, string color)
{
	SetPenColor(color);
	MovePen(start.x, start.y);
	DrawLine(end1.x - start.x, end1.y - start.y);
}


/* Function: GetMouseClick
 * Usage:  loc = GetMouseClick();
 * ------------------------------
 * Waits for the user to click somewhere on the graphics window
 * and returns the coordinate of where the click took place.
 */
coordT GetMouseClick()
{
	coordT where;
	WaitForMouseDown();
	WaitForMouseUp();
	where.x = GetMouseX();
	where.y = GetMouseY();
	return where;
}

int Cmpbydistance(Stack<arcT *> stack1 , Stack<arcT *> stack2)
{
    int dis1=0,dis2=0;
    while(!stack1.isEmpty())
    {
        arcT *arc1=stack1.pop();
        int dis=arc1->distance;
        dis1+=dis;
    }
    while(!stack2.isEmpty())
    {
        arcT *arc2=stack2.pop();
        int dis=arc2->distance;
        dis2+=dis;
    }
    if(dis1>dis2)
        return -1;
    else if(dis1<dis2)
        return 1;
    else
        return 0;
}

int Cmpbydis(arcT *arc1,arcT *arc2)
{
    if(arc1->distance<arc2->distance)
        return 1;
    else if(arc1->distance>arc2->distance)
        return -1;
    else
        return 0;
}

void StoreInfo(string filename,Set<nodeT *> &nodes);

void Dijkstra(Set<nodeT *> nodes);

void Kruskal(Set<nodeT *> nodes);

int main()
{
	InitGraphics();
	SetWindowTitle("CS106 Pathfinder");
    cout << "This masterful piece of work is a graph extravaganza!" << endl
        << "The main attractions include a lovely visual presentation of the graph" << endl
        << "along with an implementation of Dijkstra's shortest path algorithm and" << endl
        << "the computation of a minimal spanning tree.  Enjoy!" << endl;
    Set<nodeT *> nodes;
    StoreInfo("/Users/CrowHawk/Desktop/CodeblocksC++/Assignment7/USA.txt",nodes);
  //  Dijkstra(nodes);
    Kruskal(nodes);

    return (0);
}

void StoreInfo(string filename,Set<nodeT *> &nodes)
{
   // Set<nodeT *> nodes;
    ifstream fin;
    fin.open(filename.c_str());
    if(fin.fail())
        cout<<"error";
    string s;
    string a;
    string b;
    fin>>s;
    SetWindowSize(7,4.02);
    DrawNamedPicture(s);
    while(fin>>s)
    {
        if(s!="NODES")
        {
            if(s=="ARCS")
                break;
            nodeT *Node=new nodeT;
            Node->name=s;
            fin>>a;
            double x=atof(a.c_str());
            fin>>b;
            double y=atof(b.c_str());
            Node->coordinate={x,y};
            nodes.add(Node);
            DrawFilledCircleWithLabel(Node->coordinate,.02, "blue", Node->name);
      //      cout<<Node->name<<" "<<Node->coordinate.x<<","<<Node->coordinate.y<<endl;
        }
    }
  //  cout<<"size of set ="<<nodes.size()<<endl;
  /*  Set<nodeT *>::Iterator iter = nodes.iterator();
      while(iter.hasNext())
            {
                nodeT * node1=iter.next();
                cout<<node1->name<<endl;

            }*/
    Set<nodeT *>::Iterator iter2 = nodes.iterator();
    while(iter2.hasNext())
    {
        nodeT * node1=iter2.next();
        Vector<arcT *> outgoing1;
        node1->outgoing=outgoing1;
    }

    string s1;
    while(fin>>s1)
    {
            arcT *arc1=new arcT;
            arcT *arc2=new arcT;
            Set<nodeT *>::Iterator iter = nodes.iterator();
            while(iter.hasNext())
            {
                nodeT * node1=iter.next();
                if(node1->name==s1)
                {
                      arc1->start=node1;
                      arc2->end1=node1;
                      arc1->start->name=s1;
                      arc2->end1->name=s1;
                      break;
                }
            }
            fin>>s1;
            fin>>s1;
            Set<nodeT *>::Iterator iter1 = nodes.iterator();
            while(iter1.hasNext())
            {
                nodeT * node1=iter1.next();
                if(node1->name==s1)
                {
                      arc2->start=node1;
                      arc1->end1=node1;
                      arc2->start->name=s1;
                      arc1->end1->name=s1;
            /*          cout<<"arc1->start->name="<<arc1->start->name<<endl;
                      cout<<"arc2->end1->name="<<arc2->end1->name<<endl;
                      cout<<"arc2->start->name="<<arc2->start->name<<endl;
                      cout<<"arc1->end1->name="<<arc1->end1->name<<endl;*/
                      break;
                }
            }
            fin>>s1;
            arc1->distance=atoi(s1.c_str());
            arc2->distance=atoi(s1.c_str());

            Set<nodeT *>::Iterator iter3 = nodes.iterator();
            while(iter3.hasNext())
            {
                nodeT * node1=iter3.next();
                if(node1->name==arc1->start->name)
                {
                      node1->outgoing.add(arc1);
                }
                if(node1->name==arc2->start->name)
                {
                      node1->outgoing.add(arc2);
                }
                  //  cout<<"size="<<node1->outgoing.size()<<endl;
            }
          //  cout<<arc1->distance<<endl;
    }
    /*Set<nodeT *>::Iterator iter4 = nodes.iterator();
      while(iter4.hasNext())
            {
                nodeT * node1=iter4.next();
                cout<<node1->outgoing[0]->start->name<<endl;

            }*/
}

void Dijkstra(Set<nodeT *> nodes)
{
    PQueue<Stack<arcT *>> pqueue(Cmpbydistance);
    Stack<arcT *> stack1;
    coordT startcoord=GetMouseClick();
    DrawFilledCircleWithLabel(startcoord, .02, "red", "");
    coordT endcoord=GetMouseClick();
    DrawFilledCircleWithLabel(endcoord, .02, "red", "");
    nodeT *startnode=new nodeT;
    nodeT *endnode=new nodeT;

    Set<nodeT *>::Iterator iter = nodes.iterator();
    while(iter.hasNext())
    {
        nodeT *node1=iter.next();
        if(fabs(startcoord.x-node1->coordinate.x)<.02&&fabs(startcoord.y-node1->coordinate.y)<.02)
        {
            startnode=node1;
            break;
        }
    }
    Set<nodeT *>::Iterator iter1 = nodes.iterator();
    while(iter1.hasNext())
    {
        nodeT *node1=iter1.next();
        if(fabs(endcoord.x-node1->coordinate.x)<.02&&fabs(endcoord.y-node1->coordinate.y)<.02)
        {
            endnode=node1;
            break;
        }
    }
    for(int i=0;i<startnode->outgoing.size();i++)
    {
        stack1.push(startnode->outgoing[i]);
        pqueue.Enqueue(stack1);
        stack1.pop();
    }

    while(true)
    {
        if(pqueue.IsEmpty())
            break;
        Stack<arcT *> tempstack=pqueue.DequeueMax();
        arcT *topArc=tempstack.peek();
        if(topArc->end1->name==endnode->name)
        {
             while(!tempstack.isEmpty())
             {
                arcT *arcs=tempstack.pop();
                DrawLineBetween(arcs->start->coordinate, arcs->end1->coordinate, "green");
             }
             break;
        }
        else
        {
            for(int i=0;i<topArc->end1->outgoing.size();i++)
            {
                    tempstack.push(topArc->end1->outgoing[i]);
                    pqueue.Enqueue(tempstack);
                    tempstack.pop();


            }
        }
   }
}

void Kruskal(Set<nodeT *> nodes)
{
    PQueue<arcT *> pqueue(Cmpbydis);
    Set<nodeT *>::Iterator iter = nodes.iterator();
    Stack<arcT *>ArcStack;
    while(iter.hasNext())
    {
        nodeT *node1=iter.next();
        for(int i=0;i<node1->outgoing.size();i++)
        {
            pqueue.Enqueue(node1->outgoing[i]);
        }
        node1->joints.add(node1);
    }
    while(true)
    {
        if(pqueue.IsEmpty())
            break;
        arcT *Arc=pqueue.DequeueMax();
    /*    if(Arc->start->joints.contains(Arc->end1)&&Arc->end1->joints.contains(Arc->start))
        {
            continue;
        }*/
        if(!(Arc->start->joints.contains(Arc->end1))&&!(Arc->end1->joints.contains(Arc->start)))
        {
            Set<nodeT *>::Iterator iter1 = Arc->start->joints.iterator();
            while(iter1.hasNext())
            {
                nodeT *Node=iter1.next();
                if(Node!=Arc->start)
                {
                    Node->joints.unionWith(Arc->end1->joints);
                }
            }
            Arc->start->joints.unionWith(Arc->end1->joints);
            Set<nodeT *>::Iterator iter2 = Arc->end1->joints.iterator();
            while(iter2.hasNext())
            {
                nodeT *node=iter2.next();
                if(node!=Arc->end1)
                {
                    node->joints.unionWith(Arc->start->joints);
                }
            }
            Arc->end1->joints.unionWith(Arc->start->joints);
            ArcStack.push(Arc);
        }

    }
    while(!ArcStack.isEmpty())
    {
        arcT *arcs=ArcStack.pop();
        DrawLineBetween(arcs->start->coordinate, arcs->end1->coordinate, "red");
    }
}










