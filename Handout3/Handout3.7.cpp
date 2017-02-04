#include <iostream>
#include "vector.h"

using namespace std;

bool IsMeasurable(int target, Vector<int> & weights);
bool RecIsMeasurable(int target, Vector<int> & weights,int index);


int main()
{
    Vector<int> sampleWeights;
    sampleWeights.add(1);
    sampleWeights.add(3);
    cout<<"Please enter target weight:";
    int weight;
    cin>>weight;
    if(IsMeasurable(weight, sampleWeights))
        cout<<"true";
    else
        cout<<"false";
    return 0;
}

bool IsMeasurable(int target, Vector<int> & weights)
{
    return RecIsMeasurable(target, weights,0);
}

bool RecIsMeasurable(int target, Vector<int> & weights,int index)
{
    if(target==0)
        return true;
    if(index>=weights.size())
        return false;
    if(RecIsMeasurable(target,weights,index+1)||RecIsMeasurable(target+weights[index], weights,index+1)||RecIsMeasurable(target-weights[index],weights,index+1))
        return true;
    return false;
}

