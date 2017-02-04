#include <iostream>
#include "vector.h"

using namespace std;

int CutStock(Vector<int> & requests, int stockLength);
void RecursiveFn(Vector<int> & requests, Vector<int> & stocks, int stockLength, int index, int & min);


int main()
{
    int stocklength;
    cout<<"please enter stocklength:";
    cin>>stocklength;
    cout<<"please enter request vector until you enter 0:"<<endl;
    Vector<int> request;
    int element;
    cin>>element;
    request.add(element);
    while(element!=0)
    {
        cin>>element;
        request.add(element);
    }
    int output=CutStock(request,stocklength);
    cout<<"It needs at least "<<output<<" stock pipes.";

    return 0;
}

int CutStock(Vector<int> & requests, int stockLength)
{
	Vector<int> stocks;
	int min = stockLength;
	RecursiveFn(requests, stocks, stockLength, 0, min);
	return min;
}

void RecursiveFn(Vector<int> & requests, Vector<int> & stocks, int stockLength, int index, int & min)
{
    if(index==requests.size()-1)
    {
        if(min>stocks.size())
            min=stocks.size();
        return;
    }
    for(int i=0;i<stocks.size();i++)
    {
        if(stocks[i]+requests[index]<=stockLength)
        {
            stocks[i]=stocks[i]+requests[index];
            RecursiveFn(requests,stocks,stockLength,index+1,min);
            stocks[i]=stocks[i]-requests[index];
        }
    }
    stocks.add(requests[index]);
    RecursiveFn(requests,stocks,stockLength,index+1,min);
    stocks.removeAt(stocks.size()-1);
}


