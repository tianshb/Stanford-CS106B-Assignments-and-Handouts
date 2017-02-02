#include <iostream>
#include "lexicon.h"

using namespace std;

void ListCompletions(string digitSequence, Lexicon & lex);
void RecCompletions(string sofar, string rest,Lexicon & lex);
string exchange(char var);
void printwords(string prefix,Lexicon & lex);

int main()
{
    Lexicon lex("lexicon.dat");
    cout<<"please enter digits:";
    string digits;
    cin>>digits;
    ListCompletions(digits,lex);
    return 0;
}

void ListCompletions(string digitSequence, Lexicon & lex)
{
    RecCompletions("", digitSequence,lex);
}

void RecCompletions(string sofar, string rest,Lexicon & lex)
{
    if (rest=="")
    {
        printwords(sofar,lex);
    }
    else{
        string remaining=exchange(rest[0]);
        for (int i=0; i<remaining.size(); i++) {
            RecCompletions(sofar+remaining[i],rest.substr(1),lex);
        }
    }

}

string exchange(char var)
{
    switch (var) {
        case '0': return ("0");
        case '1': return ("1");
        case '2': return ("abc");
        case '3': return ("def");
        case '4': return ("ghi");
        case '5': return ("jkl");
        case '6': return ("mno");
        case '7': return ("pqrs");
        case '8': return ("tuv");
        case '9': return ("wzyz");
        default: return ("error");
    }
}


void printwords(string prefix,Lexicon & lex)
{
    string alphabet="abcdefghijklmnopqrstuvwxyz";
    if(lex.containsWord(prefix))
        cout<<prefix<<endl;

    if(lex.containsPrefix(prefix))
    {
        for(int i=0;i<alphabet.size();i++)
        {
            printwords(prefix+alphabet[i],lex);
        }
    }
    else
        return;
    }
}






