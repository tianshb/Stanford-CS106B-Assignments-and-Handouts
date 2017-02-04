/* File: boggle.cpp

 * ----------------

 * Your name here!

 */



#include "genlib.h"
#include "simpio.h"
#include <iostream>
#include "extgraph.h"
#include "gboggle.h"
#include "random.h"
#include "grid.h"
#include "vector.h"
#include "lexicon.h"
#include <cctype>
#include "set.h"


using namespace std;

const int numRows=4;
const int numCols=4;



string StandardCubes[16]  =
{"AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS", "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
 "DISTTY", "EEGHNW", "EEINSU", "EHRTVW", "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"};

string BigBoggleCubes[25]  =
{"AAAFRS", "AAEEEE", "AAFIRS", "ADENNN", "AEEEEM", "AEEGMU", "AEGMNN", "AFIRSY",
"BJKQXZ", "CCNSTW", "CEIILT", "CEILPT", "CEIPST", "DDLNOR", "DDHNOT", "DHHLOR",
"DHLNOR", "EIIITT", "EMOTTT", "ENSSSU", "FIPRSY", "GORRVW", "HIPRRY", "NOOTUW", "OOOTTU"};


void GiveInstructions()
{
    cout << endl << "The boggle board is a grid onto which I will randomly distribute "
	 << "cubes. These 6-sided cubes have letters rather than numbers on the faces, "
	 << "creating a grid of letters on which you try to form words. You go first, "
	 << "entering all the words you can find that are formed by tracing adjoining "
	 << "letters. Two letters adjoin if they are next to each other horizontally, "
	 << "vertically, or diagonally. A letter can only be used once in the word. Words "
	 << "must be at least 4 letters long and can only be counted once. You score points "
	 << "based on word length: a 4-letter word is worth 1 point, 5-letters earn 2 "
	 << "points, and so on. After your puny brain is exhausted, I, the super computer, "
	 << "will find all the remaining words and double or triple your paltry score." << endl;

    cout << "\nHit return when you're ready...";
    GetLine();
}



static void Welcome()
{
    cout << "Welcome!  You're about to play an intense game of mind-numbing Boggle. "
	 << "The good news is that you might improve your vocabulary a bit.  The "
	 << "bad news is that you're probably going to lose miserably to this little "
	 << "dictionary-toting hunk of silicon.  If only YOU had a gig of RAM..." << endl << endl;
}


void InitialBoard(Grid<char> &gridboard);
void HumanTurn(Grid<char> &gridboard,Grid<bool> &whether,Set<string> &HumanList,Lexicon lex);
bool Judge(Grid<char> &gridboard,Grid<bool> &whether,int row,int col,string word);
void PCTurn(Grid<char> gridboard,Set<string> List);
void PCJudge(Grid<char> &gridboard,Grid<bool> &whether,int row,int col,Set<string> &ComputerList,string word,Lexicon &lex);

int main()
{

	InitGraphics();
	SetWindowSize(9, 5);
	Welcome();
	GiveInstructions();
	Grid<char> gridboard(4,4);
	Grid<bool> whether(4,4);
	Lexicon lex("lexicon.dat");
	Set<string> List;
	InitialBoard(gridboard);
	HumanTurn(gridboard,whether,List,lex);
	PCTurn(gridboard,List);
	return 0;
}



void InitialBoard(Grid<char> &gridboard)
{
    Randomize();
    DrawBoard(numRows, numCols);
    int i=0;
    for(int row=0;row<numRows;row++)
    {
        for(int col=0;col<numCols;col++)
        {
            string Initstandard=StandardCubes[i];
            char letter=Initstandard[RandomInteger(0, 6)];
            gridboard.setAt(row,col,letter);
            i++;
        }
    }
    for (int row=0;row<numRows;row++)
    {
        for (int col=0;col<numCols;col++)
        {
            int randomRow=RandomInteger(row,numRows);
            int randomCol=RandomInteger(col,numCols);
            int temp=gridboard.getAt(row,col);
            gridboard.setAt(row,col,gridboard.getAt(randomRow,randomCol));
            gridboard.setAt(randomRow,randomCol,temp);
            LabelCube(row,col,gridboard.getAt(row,col));
        }
    }
}



void HumanTurn(Grid<char> &gridboard,Grid<bool> &whether,Set<string> &HumanList,Lexicon lex)
{
    Vector<int> RowSign;
    Vector<int> ColSign;
    cout<<"please enter words:"<<endl;
    string word;
    while(word!="EndMyTurn")
    {
        cin>>word;
        for(int row=0;row<numRows;row++)
        {
            for(int col=0;col<numCols;col++)
            {
                whether.setAt(row,col,true);
                if(gridboard.getAt(row,col)==word[0])
                {
                    RowSign.add(row);
                    ColSign.add(col);
                }
            }
        }
        if(RowSign.size()>0)
        {
            for(int i=0;i<RowSign.size();i++)
            {
                if(Judge(gridboard,whether,RowSign[i],ColSign[i],word))
                {
                    if(word.size()>=4&&lex.containsWord(word))
                    {
                        HumanList.add(word);
                        RecordWordForPlayer(word,Human);
                    }
                }
            }
        }
    }
}


bool Judge(Grid<char> &gridboard,Grid<bool> &whether,int row,int col,string word)
{
    if(word.size()==0)
        return true;
    for(int i=-1;i<2;i++)
    {
        for(int j=-1;j<2;j++)
        {
             if(gridboard.inBounds(row+i,col+j)&&whether.getAt(row+i,col+j)==true)
             {
                whether.setAt(row,col,false);
                if(Judge(gridboard,whether,row+i,col+j,word.substr(1)))
                {
                    return true;
                }
             }
        }
    }

    return false;

}



void PCTurn(Grid<char> gridboard,Set<string> List)
{
    cout<<"The computer killer is working."<<endl;
    Lexicon lex("lexicon.dat");
    Grid<bool> whether(4,4);

    Set<string> ComputerList;

    for(int row=0;row<4;row++)
    {
        for(int col=0;col<4;col++)
        {
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    whether.setAt(i,j,true);
                }
            }
            string word="";
            word+=gridboard.getAt(row,col);
            whether.setAt(row,col,false);
            PCJudge(gridboard,whether,row,col,ComputerList,word,lex);
        }
    }
    ComputerList.subtract(List);

    Set<string>::Iterator itr=ComputerList.iterator();
    while(itr.hasNext())
    {
        RecordWordForPlayer(itr.next(),Computer);
    }
}


void PCJudge(Grid<char> &gridboard,Grid<bool> &whether,int row,int col,Set<string> &ComputerList,string word,Lexicon &lex)
{
    if(word.size()>=4&&lex.containsWord(word))
    {
            ComputerList.add(word);

    }
    if(lex.containsPrefix(word))
    {
        for(int i=-1;i<2;i++)
        {
            for(int j=-1;j<2;j++)
            {
                if(gridboard.inBounds(row+i,col+j)&&whether.getAt(row+i,col+j)==true)
                {
                    whether.setAt(row+i,col+j,false);
                    PCJudge(gridboard,whether,row+i,col+j,ComputerList,word+gridboard.getAt(row+i,col+j),lex);
                    whether.setAt(row+i,col+j,true);
                }
            }
        }
    }

}
