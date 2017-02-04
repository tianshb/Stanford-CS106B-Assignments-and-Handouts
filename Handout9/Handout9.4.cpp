void createNode(string word, graphT & graph)
{
    nodeT * newNode = new nodeT;
    newNode->name = word;
    graph.allNodes.add(newNode);
}

void ConstructGraph(graphT & graph, Lexicon & lex)
{
    lex.mapAll<graphT>(createNode, graph);
    Map<nodeT *> wordMap;
    Set<nodeT *>::Iterator iter = graph.allNodes.iterator();
    while(iter.hasNext())
    {
        nodeT* currNode = iter.next();
        wordMap.add(currNode->name, currNode);
    }
    iter = graph.allNodes.iterator();
    while(iter.hasNext())
    {
        nodeT* currNode = iter.next();
        string currWord = currNode->name;
        for(int i = 0; i < currWord.length(); i++)
        {
            for(int replaceChar = ‘a’; replaceChar <= ‘z’; replaceChar++)
            {
                string newWord = currWord.substr(0,i) + (char)replaceChar+ currWord.substr(i+1);
                if(lex.containsWord(newWord) && newWord != currWord)
                {
                    nodeT* otherNode = wordMap.getValue(newWord);
                    arcT * edge = new arcT;
                    edge->start = currNode;
                    edge->end = otherNode;
                    currNode->connected.add(edge);
                }
            }
        }
    }
}
