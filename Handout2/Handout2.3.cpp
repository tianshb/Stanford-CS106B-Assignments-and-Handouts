
#include "stack.h"
#include "scanner.h"


bool ProcessOpenTag(Scanner& scanner, Stack<string>& tagStack)
{
    string tag = scanner.nextToken();
    tagStack.push(tag);
    return true;
}
bool ProcessCloseTag(Scanner& scanner, Stack<string>& tagStack)
{
    string tag = scanner.nextToken();
    if (!tagStack.isEmpty() && tag == tagStack.pop()) {
        return true;
    }else {
        return false;
    } }
bool ProcessTag(Scanner& scanner, Stack<string>& tagStack)
{
    // read the next token to see if we found an
    // opening or closing tag
    string token = scanner.nextToken();
    if (token == "/")
    {
        return ProcessCloseTag(scanner, tagStack);
    }
    else {
        return ProcessOpenTag(scanner, tagStack);
    }
}
bool IsCorrectlyNested(string htmlStr)
{
    Scanner scanner;
    scanner.setSpaceOption(Scanner::IgnoreSpaces);
    Stack<string> tagStack;
    scanner.setInput(htmlStr);
    // start by assuming it is balanced
    bool isBalanced = true;
    scanner.saveToken(token); //So ProcessOpenTag can use it
    while (scanner.hasMoreTokens())
    {
        string token = scanner.nextToken();
        if (token == "<")
        {
            if (!ProcessTag(scanner, tagStack))
            {
                isBalanced = false;
                break; }
            // get rid of ">" part of tag
            scanner.nextToken();
        }
    }
    if (!tagStack.isEmpty()) isBalanced = false;
    return isBalanced;
}
