bool RecCyclicCheck(graphT & graph, nodeT * node, Set<nodeT *> & visited)
{
    if (visited.contains(node))
    {
        return true;
    }
    Set<arcT *>::Iterator arcIter = node->connected.iterator();
    bool result = false;
    visited.add(node);
    while (!result && arcIter.hasNext())
    {
        if (RecCyclicCheck(graph, arcIter.next()->end, visited))
        {
            result = true;
        }
    }
    visited.remove(node);
    return result;
}
bool IsCyclicGraph(graphT & graph)
{
    Set<nodeT *>::Iterator iter = graph.allNodes.iterator();
    Set<nodeT *> visited;
    //We need to check starting from each node, since the graph may not be
    //connected
    while(iter.hasNext())
    {
        Set<nodeT *> currVisited;
        nodeT * currStart = iter.next();
        if(!visited.contains(currStart) &&
           RecCyclicCheck(graph, currStart, currVisited))
            return true;
        visited.unionWith(currVisited);
    }
    return false;
}
