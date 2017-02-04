#include <iostream>

using namespace std;

int Cannonball(int height);

int main()
{
    cout<<"Please enter height:";
    int h;
    cin>>h;
    int num=Cannonball(h);
    cout<<"The number of cannoballs is "<<num<<endl;
    return 0;
}

int Cannonball(int height)
{
    if(height==1)
        return 1;
    if(height>1)
    {
        return (height*height+Cannonball(height-1));
    }
}
