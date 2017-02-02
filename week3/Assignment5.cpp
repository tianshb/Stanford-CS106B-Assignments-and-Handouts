#include <iostream>
#include "vector.h"
#include "random.h"
#include "set.h"

using namespace std;

template <typename Type>
int OperatorCmp(Type one, Type two);

template <typename Type>
void Swap(Type &one,Type &two);

template <typename Type>
void Sort(Vector<Type> &v, int (cmpFn)(Type, Type));

void ShellSort(Vector<int> &v);

int StringCmp(string one, string two);

int SetCmp(Set<int> one,Set<int> two)£»

int main()
{
    Vector<int> sorts;
    int value;
    for(int i=0;i<10;i++)
    {
        value=RandomInteger(0,100);
        sorts.add(value);
        if(i==9)
            cout<<sorts[i]<<endl;
        else
            cout<<sorts[i]<<",";
    }
    ShellSort(sorts);
    cout<<"The sorted sequence is:";
    for(int i=0;i<sorts.size();i++)
    {
        if(i==sorts.size()-1)
            cout<<sorts[i];
        else
            cout<<sorts[i]<<",";
    }
    return 0;
}

template <typename Type>
void Swap(Type &one,Type &two)
{
    Type temp=one;
    one=two;
    two=temp;
}

template <typename Type>
int OperatorCmp(Type one, Type two) {
	if (one == two) return 0;
	if (one < two) return -1;
	return 1;
}

template <typename Type>
void Sort(Vector<Type> &v, int (cmpFn)(Type, Type)){
    for(int gap=v.size()/2;gap>0;gap/=2)
    {
        for(int i=gap;i<v.size();i++)
            for(int j=i-gap;j>=0&&cmpFn(v[j],v[j+gap])<0;j-=gap)
                Swap(v[j],v[j+gap]);
    }

}

void ShellSort(Vector<int> &v)
{
    for(int gap=v.size()/2;gap>0;gap/=2)
    {
        for(int i=gap;i<v.size();i++)
            for(int j=i-gap;j>=0&&v[j]>v[j+gap];j-=gap)
                Swap(v[j],v[j+gap]);
    }
}


int StringCmp(string one,string two) {
	if (one.length()>two.length())
        return 1;
	if (one.length()<two.length())
        return -1;
	else
        return OperatorCmp(one,two);
}

int SetCmp(Set<int> one,Set<int> two){
    Set<int>::Iterator itr1=one.iterator();
    Set<int>::Iterator itr2=two.iterator();
    int sum1=0,sum2=0;
    while(iter1.hasNext()){
        sum1+=iter1.next();
    }
    while(iter2.hasNext()){
        sum2+=iter2.next();
    }
    return OperatorCmp(sum1,sum2);
}


//希尔排序是不稳定的排序，时间复杂度和增量序列有关，最坏情况下时间复杂度为O(n^2),在最好情况下可为O(1.3)，其推导过程中仍包含未解的数学难题
