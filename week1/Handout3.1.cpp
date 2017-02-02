#include <iostream>
#include "set.h"

using namespace std;

struct entryT {
    string firstName;
    string lastName;
    string phoneNumber;
};

int nameComp(entryT stu1,entryT stu2);
int caseInsensitive(string str1,string str2);

int main()
{
    Set<entryT> addressbook(nameComp);
    Set<string> CaseInsensitive(caseInsensitive);
    Set<entryT>:Iterator iter1=addressbook.iterator();

    return 0;
}

int nameComp(entryT stu1,entryT stu2)
{
    if(stu1.lastName>stu2.lastName)
        return 1;
    else if(stu1.lastName<stu2.lastName)
        return -1;
    else if(stu1.firstName>stu2.firstName)
        return 1;
    else if(stu1.firstName<stu2.firstName)
        return -1;
    else
        return 0;
}

int caseInsensitive(string str1,string str2)
{
    string lower1=ConvertToLowerCase(str1);
    string lower2=ConvertToLowerCase(str1);
    if(lower1>lower2)
        return 1;
    else if(lower1<lower2)
        return -1;
    else
        return 0;
}
