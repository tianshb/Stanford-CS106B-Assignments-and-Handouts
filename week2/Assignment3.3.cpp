#include <iostream>
#include "vector.h"
#include <math.h>

using namespace std;

int CountCriticalVotes(Vector<int> & blocks, int blockIndex);
void CountCriticalVotes111(Vector<int> & Alice, Vector<int> &rest,int blockIndex,int sumblk,int &countx);

int main()
{
    Vector<int> block;
    block.add(4);
    block.add(2);
    block.add(7);
    block.add(4);

    int blockindex;
    cout<<"enter blockIndex:";
    cin>>blockindex;
    int count1=CountCriticalVotes(block,blockindex);
    cout<<"count="<<count1;
    return 0;

}

int CountCriticalVotes(Vector<int> & blocks, int blockIndex)
{
    int value=blocks[blockIndex];
    blocks.removeAt(blockIndex);
    int sum=0;
    for(int i=0;i<blocks.size();i++)
    {
        sum+=blocks[i];
    }
    Vector<int> blk1;
    int countx=0;
    if(blk1.isEmpty())
        CountCriticalVotes111(blk1,blocks,value,sum,countx);
    return countx;

}

void CountCriticalVotes111(Vector<int> & Alice, Vector<int> &rest,int value,int sumblk,int &county)
{
    if(rest.isEmpty())
    {
        int sumAlice=0;
        for(int i=0;i<Alice.size();i++)
        {
            sumAlice+=Alice[i];
        }
        if(abs(sumblk-sumAlice-sumAlice)<=value)
            county++;
    }

    else
    {
        Vector<int> rest1;
        for(int i=1;i<rest.size();i++)
            rest1.add(rest[i]);
        rest.removeAt(0);
        CountCriticalVotes111(Alice, rest,value,sumblk,county);
        CountCriticalVotes111(rest1, rest,value,sumblk,county);
    }
}
