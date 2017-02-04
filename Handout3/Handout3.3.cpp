#include <iostream>
#include "set.h"

using namespace std;

struct pairT{
    string first;
    string second;
};

int PairCmpFn(pairT one, pairT two)£»
Set<pairT> CartesianProduct(Set<string> & one, Set<string> & two);


int main()
{
    string A;
    string B;
    Set<string>  setA;
    Set<string>  setB;
    cout<<"Please enter setA:"<<endl;
    while(A!="end")
    {
        cin>>A;
        setA.add(A);
    }
    cout<<"Please enter setB:"<<endl;
    while(B!="end")
    {
        cin>>B;
        setB.add(B);
    }
    CartesianProduct(setA, setB);


    return 0;
}

int PairCmpFn(pairT one, pairT two)
{
    if(one.first>two.first)
        return 1;
    else if(one.first==two.first&&one.second>two.second)
        return 1;
    else if(one.first==two.first&&one.second==two.second)
        return 0;
    else
        return -1;
}

Set<pairT> CartesianProduct(Set<string> & one, Set<string> & two)
{
    Set<pairT> output(PairCmpF);
    Set<string>::Iterator iter1=one.iterator();
    Set<string>::Iterator iter2=two.iterator();
    pairT pair;
    while(iter1.hasNext())
    {
        string first=iter1.next();
        while(iter2.hasNext())
        {
             string second=iter2.next();
             pair.first=first;
             pair.second=second;
             output.add(pair);
             cout<<"{"<<first<<","<<second<<"}"<<",";
        }
    }
    return output;
}

