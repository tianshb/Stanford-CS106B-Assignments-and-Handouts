//
//  main.cpp
//  handout1 problem1
//
//  Created by 王泽远 on 15/10/12.
//  Copyright © 2015年 王泽远. All rights reserved.
//

#include <iostream>


using namespace std;

string CensorString1(string text,string remove);

void   CensorString2(string &text,string remove);

string CensorString3(string text,string remove);

int main()
{
    string s1,s2,s3;
    cout<<"请输入text：";
    cin>>s1;
    cout<<"请输入remove：";
    cin>>s2;
    CensorString2(s1,s2);
    cout<<"text－remove＝"<<s1;
    //s3=CensorString3(s1, s2);
    return 0;
    
}

string CensorString1(string text,string remove)
{
    string str="";
    int i,j;
    for(i=0;i<text.length();i++)
    {
        bool flag=0;
        for(j=0;j<remove.length();j++)
        {
            if(text[i]==remove[j])
                flag=1;
        }
        if(!flag)
        {
            str+=text[i];
        }
    }
    return str;
}

void CensorString2(string &text,string remove)
{
    int i,j;
    for(i=0;i<text.length();i++)
    {
        bool flag=0;
        for(j=0;j<remove.length();j++)
        {
            if(text[i]==remove[j])
                flag=1;
        }
        if(flag)
            text.replace(i--, 1, "");
    }
}
/*void CensorString2(string &text,string remove)
{
    for(int i=0;i<remove.length();i++)
    {
        int tag=0;
        while((tag=int(text.find(remove[i])))!=string::npos)
        {
            text.replace(tag, 1, "");
        }
    }
}

string CensorString3(string text,string remove)
{
    string str=text;
    int i;
    int tag;
    for(i=0;i<remove.length();i++)
    {
        while(true)
        {
            tag=int(text.find(remove[i]));
            if(tag==string::npos)
                break;
            else
            {
                str=str.substr(0,tag)+str.substr(tag+1);
            }
        }
    }
    return str;
}
*/
