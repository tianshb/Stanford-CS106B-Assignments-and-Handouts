#include <iostream>
#include <vector>

using namespace std;

void swap(int &a,int &b);
int minindex(vector<int> vv,int i,int j);
int maxindex(vector<int> vv,int i,int j);
void ReConfigure(vector<int> &vec,int index);

class PQueue
{
public:
    PQueue();
    ~PQueue();
    int size();
    bool isEmpty();
    void enqueue(int newElem);
    int dequeueMax();
protected:
    vector<int> pqueue;
};

PQueue::PQueue()
{
    vector<int> pqueue;
}

PQueue::~PQueue()
{
    pqueue.clear();
    vector<int>().swap(pqueue);
}

int PQueue::size()
{
    int size=pqueue.size();
    return size;
}

bool PQueue::isEmpty()
{
    return pqueue.empty();
}

void PQueue::enqueue(int newElem)
{
    pqueue.push_back(newElem);
    int index=pqueue.size()-1;
    while(pqueue[index]>pqueue[(index-1)/2])
    {
        swap(pqueue[index],pqueue[(index-1)/2]);
        index=(index-1)/2;
    }
}

int PQueue::dequeueMax()
{
    int value=pqueue[0];
    pqueue[0]=pqueue[pqueue.size()-1];
    pqueue.pop_back();
    ReConfigure(pqueue,0);
    return value;
}


int main()
{
    PQueue PQ;
    PQ.enqueue(1);
    PQ.enqueue(2);
    PQ.enqueue(3);
    int a= 0;
    a=PQ.dequeueMax();
    cout<<a;
    return 0;
}

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

int minindex(vector<int> vv,int i,int j)
{
    if(i<vv.size()&&j<vv.size())
    {
        if(vv[i]<=vv[j])
            return i;
        else
            return j;
    }
    else
        return 0;
}

int maxindex(vector<int> vv,int i,int j)
{
    if(i<vv.size()&&j<vv.size())
    {
        if(vv[i]>=vv[j])
            return i;
        else
            return j;
    }
    else
        return 0;
}


void ReConfigure(vector<int> &vec,int index)
{
    if((vec[index]>=vec[2*index+1]&&vec[index]>=vec[2*index+2])||2*index+1>=vec.size())
        return;
    if(vec[index]<vec[minindex(vec,2*index+1,2*index+2)])
    {
         int i=maxindex(vec,2*index+1,2*index+2);
         swap(vec[index],vec[i]);
         ReConfigure(vec,i);
    }
    if(vec[index]>=vec[minindex(vec,2*index+1,2*index+2)]&&vec[index]<vec[maxindex(vec,2*index+1,2*index+2)])
    {
         int i=minindex(vec,2*index+1,2*index+2);
         swap(vec[index],vec[i]);
         ReConfigure(vec,i);
    }
}
