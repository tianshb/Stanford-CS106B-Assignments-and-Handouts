int ShortestPathLength(pointT pt)
{
    int shortest, len;
    if (OutsideMaze(pt))
    {
        return 0; }
    if (IsMarked(pt))
    {
        return NoSolution;
    }
    shortest = NoSolution;
    MarkSquare(pt);
    for (directionT dir = North; dir <= West; dir=directionT(dir+1))
    {
        if (!WallExists(pt, dir))
        {
            len = ShortestPathLength(AdjacentPoint(pt, dir));
            if (len < shortest)
            {
                shortest = len;
            }
        } }
    UnmarkSquare(pt);
    if (shortest == NoSolution)
    {
        return NoSolution;
    }
    else
    {
        return (shortest + 1);
    }
}