#include <iostream>
#include "vector.h"


using namespace std;

bool Solvable(int start, Vector<int> & squares);
bool Solvable111(int start,Vector<int> & squares,Vector<bool> &tag);

int main()
{
    Vector<int> square;
    cout<<"please enter the vector:"<<endl;
    int input;
    cin>>input;
    while(input!=0)
    {
        square.add(input);
        cin>>input;
    }
    square.add(0);
    cout<<"please enter start position:"<<endl;
    int i;
    cin>>i;
    if(Solvable(i, square))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;

}


bool Solvable(int start,Vector<int> & squares)
{
    Vector<bool> flag;
    for(int i=0;i<squares.size();i++)
        flag.add(true);
    return Solvable111(start, squares,flag);
}

bool Solvable111(int start, Vector<int> & squares,Vector<bool> &tag)
{
    int mark=start;
    tag[start]=false;
    if(mark==squares.size()-1)
        return true;

    mark=start+squares[start];
    if(mark>=0&&mark<squares.size()&&tag[mark])
    {
        if(Solvable111(mark,squares,tag))
        {
            return true;
        }
    }
    mark=start-squares[start];
    if(mark>=0&&mark<squares.size()&&tag[mark])
    {
        if(Solvable111(mark,squares,tag))
        {

            return true;
        }
    }
    return false;
}
