//
//  main.cpp
//  Assignment1 pro2
//
//  Created by 王泽远 on 15/10/13.
//  Copyright © 2015年 王泽远. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
//#include "random.h"

using namespace std;

double RandomReal(double low, double high);
bool RandomChance(double p);
double ratio1(int voters,double PerSprd,double ErrorPer);

int main()
{
    int voter0;
    double PercentageSpread,ErrorPercentage,result;
    cout<<"Enter number of voters:";
    cin>>voter0;
    cout<<"Enter percentage spread between candidates:";
    cin>>PercentageSpread;
    cout<<"Enter voting error percentage:";
    cin>>ErrorPercentage;
    cout<<"Chance of an invalid election result after 500_trials = ";
    result=ratio1(voter0,PercentageSpread,ErrorPercentage);
    cout<<result;
    return 0;
}

double ratio1(int voters,double PerSprd,double ErrorPer)
{
    int i,j,k,count=0;
    double chance;
    for(k=0;k<500;k++)
    {
        int voter1=(int)voters*(0.5+PerSprd);
        int voter2=(int)voters*(0.5-PerSprd);
        for(i=0;i<(int)voters*(0.5+PerSprd);i++)
            if(RandomChance(ErrorPer))
            {
                voter1--;
                voter2++;
            }
        for(j=0;j<(int)voters*(0.5-PerSprd);j++)
            if(RandomChance(ErrorPer))
            {
                voter1++;
                voter2--;
            }
        if(voter1<voter2)
            count++;
    }
    chance=(double)count/500;
    return chance;
}

double RandomReal(double low, double high) {
    double d = double(rand()) / (double(RAND_MAX) + 1);
    return low + d * (high - low);
}


bool RandomChance(double p) {
    return RandomReal(0, 1) < p;
}





