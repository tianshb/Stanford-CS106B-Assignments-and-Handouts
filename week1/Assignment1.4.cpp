//
//  main.cpp
//  Assignment1 prob4.2
//
//  Created by 王泽远 on 15/10/17.
//  Copyright © 2015年 王泽远. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string Soundex(string surname);

int main()
{
    string surname1,surname2;
    cout<<"Enter surname (RETURN to quit):";
    cin>>surname1;
    cout<<"Soundex code for Vaska is ";
    surname2=Soundex(surname1);
    cout<<surname2;
    return 0;
}

string Soundex(string surname)
{
    string soundex="";
    int i;
    
    string code0="aeiouhwy";
    string code1="bfpa";
    string code2="cgjkqsxz";
    string code3="dt";
    string code4="mn";
    string code5="l";
    string code6="r";
    
    if(surname[0]>='a')
        surname[0]-=32;
    for(i=0;i<code0.size();i++)
    {
        while(surname.find(code0[i])!=string::npos)
        surname[surname.find(code0[i])]='0';
    }
    for(i=0;i<code1.size();i++)
    {
        while(surname.find(code1[i])!=string::npos)
            surname[surname.find(code1[i])]='1';
    }
    for(i=0;i<code2.size();i++)
    {
        while(surname.find(code2[i])!=string::npos)
            surname[surname.find(code2[i])]='2';
    }
    for(i=0;i<code3.size();i++)
    {
        while(surname.find(code3[3])!=string::npos)
            surname[surname.find(code3[i])]='3';
    }
    for(i=0;i<code4.size();i++)
    {
        while(surname.find(code4[i])!=string::npos)
            surname[surname.find(code4[i])]='4';
    }
    for(i=0;i<code5.size();i++)
    {
        while(surname.find(code5[i])!=string::npos)
            surname[surname.find(code5[i])]='5';
    }
    for(i=0;i<code6.size();i++)
    {
        while(surname.find(code6[i])!=string::npos)
            surname[surname.find(code6[i])]='6';
    }

    
    for(i=1;i<surname.length();i++)
    {
        if((surname[i]==surname[i+1])||(surname[i]=='0'))
        {
            surname.erase(i, 1);
            i--;
        }
        
    }
    if(surname.length()>4)
        surname.substr(0,4);
    if(surname.length()<4)
    {
        while(surname.length()<4)
            surname+='0';
    }
    return surname;
}

