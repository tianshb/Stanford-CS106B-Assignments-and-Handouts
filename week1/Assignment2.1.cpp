//
//  main.cpp
//  Assignment2 prob1
//
//  Created by 王泽远 on 15/10/15.
//  Copyright © 2015年 王泽远. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef vector<char> chars;
typedef map<string,chars> ::iterator map_itr;

int RandomInteger(int low, int high);
void generate(string filename,int seed_size);

int main()
{
    int n;
    cout<<"请输入马尔可夫链阶数:";
    cin>>n;
    generate("/Users/CrowHawk/Desktop/C++工程/Assignment2 prob1/Assignment2 prob1/assignment2.txt",n);
    return 0;
}

int RandomInteger(int low, int high) {
    double d = double(rand()) / (double(RAND_MAX) + 1);
    int k = int(d * (high - low));
    return low + k;
}

void generate(string filename,int seed_size)
{
    ifstream in;
    map<string,chars> storage;
    in.open(filename.c_str());
    if (in.fail()) {
        cout<<"error";
        in.clear();
    }
    char var;
   
    string article="";
    while(in.get())
    {
        var=in.get();
        if (in.fail()) {
            break;
        }
        article+=var;
    }
    string seed;
    for(int i=0;i+seed_size<=article.length();i++)
    {
        seed=article.substr(i,seed_size);
        storage[seed].push_back(article[i+seed_size]);
    }
    map_itr itr;
    chars max_vector;
    string max="";

    for(itr=storage.begin();itr!=storage.end();itr++)
    {
        if(itr->second.size()>max_vector.size())
        {
            max_vector=itr->second;
            max=itr->first;
        }
    }
    cout<<max;
    for(int j=0;j<2000-seed_size;j++)
    {
        char seedchar=max_vector[RandomInteger(0, int(max_vector.size()))];
        cout<<seedchar;
        max=max.substr(1,seed_size-1)+seedchar;
        max_vector=storage[max];
    }
}













