//
//  main.cpp
//  Handout3.8
//
//  Created by 王泽远 on 15/10/20.
//  Copyright © 2015年 王泽远. All rights reserved.
//

#include <iostream>

using namespace std;

void ListMnemonics(string str);

void RecMnemonics(string sofar,string rest);

string exchange(char var);

int main()
{
    string var1;
    cout<<"please enter digits:";
    cin>>var1;
    ListMnemonics(var1);
}

void ListMnemonics(string str)
{
    RecMnemonics("",str);
}

void RecMnemonics(string sofar,string rest)
{
    if (rest=="") {
        cout<<sofar<<endl;
    }
    else{
        string remaining=exchange(rest[0]);
        for (int i=0; i<remaining.size(); i++) {
            RecMnemonics(sofar+remaining[i],rest.substr(1));
        }
    }
}

string exchange(char var)
{
    switch (var) {
        case '0': return ("0");
        case '1': return ("1");
        case '2': return ("ABC");
        case '3': return ("DEF");
        case '4': return ("GHI");
        case '5': return ("JKL");
        case '6': return ("MNO");
        case '7': return ("PRS");
        case '8': return ("TUV");
        case '9': return ("WXY");
        default: return ("error");
    }
}

