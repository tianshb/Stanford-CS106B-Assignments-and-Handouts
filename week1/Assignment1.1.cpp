//
//  main.cpp
//  Assignment1 prob1
//
//  Created by 王泽远 on 15/10/13.
//  Copyright © 2015年 王泽远. All rights reserved.
//

#include <iostream>

using namespace std;

bool Isperfect(int n);

int main()
{
    int num;
    cout<<"请输入一个不超过10000的自然数n："<<endl;
    cin>>num;
    if(Isperfect(num))
        cout<<"n是完美数";
    else
        cout<<"n不是完美数";
    return 0;
}


bool Isperfect(int n)
{
    int i,num=0;
    for(i=1;i<n/2+1;i++)
    {
        if(n%i==0)
            num+=i;
    }
    if(num==n)
        return true;
    else
        return false;
}