//
//  main.cpp
//  Assignment1 problem5
//
//  Created by 王泽远 on 15/10/14.
//  Copyright © 2015年 王泽远. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void Histogram(string filename);

int main()
{
    Histogram("/Users/CrowHawk/Desktop/C++工程/handout problem2/handout problem2/file1.txt");
    return 0;
}


void Histogram(string filename)
{
    ifstream in;
    in.open(filename.c_str());
    if(in.fail())
    {
        in.clear();
        cout<<"error";
    }
    vector<string> gram;
    int i,value;
    for(i=0;i<10;i++)
    {
        gram.push_back("");
    }
    while (true)
    {
        in>>value;
        if(in.fail())
            break;
        else
        {
            if (value<100&&value>=0)
            {
                int ten=value/10;
                string tempstr;
                tempstr=gram[ten];
                gram[ten]=tempstr+"X";
            }
        }
    }
    for (i=0; i<10; i++) {
        int k=10*i;
        int l=k+9;
        cout<<k<<"~"<<l<<":"<<gram[i]<<endl;
    }
}
    
