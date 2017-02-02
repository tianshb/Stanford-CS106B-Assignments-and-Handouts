#include <iostream>

using namespace std;

string ReverseString(string str);

int main()
{
    string str1,str2;
    cout << "Please enter string:";
    cin>>str1;
    str2=ReverseString(str1);
    cout<<"The reverse string is "<<str2<<endl;
    return 0;
}

string ReverseString(string str)
{
    if(str.length()==1)
        return str;
    if(str.length()>1)
        return(ReverseString(str.substr(1))+str[0]);
}
