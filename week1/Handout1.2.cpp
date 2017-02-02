//
//  main.cpp
//  handout problem2
//
//  Created by 王泽远 on 15/10/13.
//  Copyright © 2015年 王泽远. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

struct stat{
    int max;
    int min;
    double ave;
};

stat calculate(string filename);

int main()
{
    stat Stat1;
    Stat1=calculate("/Users/CrowHawk/Desktop/C++工程/handout problem2/handout problem2/file1.txt");
    cout<<"最高分为："<<Stat1.max<<endl;
    cout<<"最低分为："<<Stat1.min<<endl;
    cout<<"均分为："<<Stat1.ave;
    return 0;
}

stat calculate(string filename)
{
    ifstream in;
    in.open(filename.c_str());
    if(in.fail())
    {
        in.clear();
        cout<<"error";
    }
    stat Stats;
    Stats.max=0;
    Stats.min=100;
    
    int value,sum=0,num=0;
    
    
    while(true)
    {
        in>>value;
        if(in.fail())
            break;
        else
        {
            sum+=value;
            num++;
            if(value>=Stats.max)
                Stats.max=value;
            if(value<=Stats.min)
                Stats.min=value;
        }
    }
   //if(!in.eof())
     //   error("Data error in file");
    Stats.ave=(double)sum/num;
    in.close();
    return Stats;
}




