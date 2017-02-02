//
//  main.cpp
//  Handout1 Prob3
//
//  Created by 王泽远 on 15/10/14.
//  Copyright © 2015年 王泽远. All rights reserved.
//

//
//  main.cpp
//  Handout1 pro3
//
//  Created by 王泽远 on 15/10/14.
//  Copyright © 2015年 王泽远. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <ctype.h>
#include "vector.h"
#include <genlib.h>

using namespace std;

const int LENGTH=26;

void CountLetters(string filename);

int main()
{
    CountLetters("aaa.txt");
    return 0;
}

void CountLetters(string filename)
{
    int i,j=0,k;
    string line;
    ifstream in;
    in.open(filename);
    if(in.fail())
    {
        in.clear();
        cout<<"error!";
    }
    Vector<int> num;
    for(i=0;i<LENGTH ;i++)
    {
        num.add(0);
    }
    while(true)
    {
        getline(in,line);
        if(in.fail())
        {
            break;
            cout<<"error2";
        }
        while (line[j])
        {
            tolower(line[j]);
            j++;
        }
        for(k=0;k<line.length();k++)
        {
            int art=line.[k]-'a';
            if(art<=LENGTH&&art>=0)
            {
                int temp=num[art];
                num[art]=temp+1;
            }
        }
    }
    for(i=0;i<LENGTH;i++)
    {
        char xx='a'+i;
        cout<<x<<":"<<num[art]<<endl;
    }
}

