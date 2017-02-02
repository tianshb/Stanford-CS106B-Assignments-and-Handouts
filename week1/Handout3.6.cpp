#include <iostream>

using namespace std;

int GCD(int x, int y);

int main()
{
    int x,y,z;
    cout << "Please enter x:";
    cin>>x;
    cout<<"Please enter y:";
    cin>>y;
    if(x>=y)
    {
        z=GCD(x,y);
        cout<<"Their GCD is "<<z<<endl;
    }
    if(x<y)
    {
        z=GCD(y,x);
        cout<<"Their GCD is "<<z<<endl;
    }
    return 0;
}

int GCD(int x, int y)
{
    if(x%y==0)
        return y;
    else
        return GCD(y,x/y);
}
