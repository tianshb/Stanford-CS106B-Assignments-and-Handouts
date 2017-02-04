bool LocationOnGrid(int row, int col, Grid<int> & bombCounts)
{
    return row >= 0 && col >= 0 && row < bombCounts.numRows()&& col < bombCounts.numCols();
}
void MarkBomb(int row, int col, Grid<int> & bombCounts)
{
    for(int bombRow = -1; bombRow <= 1; bombRow++)
    {
        for(int bombCol = -1; bombCol <= 1; bombCol++)
        {
            if(LocationOnGrid(bombRow + row, bombCol + col,bombCounts))
                bombCounts(bombRow + row, bombCol + col)++;
        }
    }
}
Grid<int> MakeGridOfCounts(Grid<bool> & bombLocations)
{
    Grid<int> bombCounts(bombLocations.numRows(),
                         bombLocations.numCols());
    for(int row = 0; row < bombLocations.numRows(); row++)
    {
        for(int col = 0; col < bombLocations.numCols();col++)
        {
            bombCounts(row, col) = 0;
        }
    }
    for(int row = 0; row < bombLocations.numRows(); row++)
    {
        for(int col = 0; col < bombLocations.numCols();col++)
        {
            if(bombLocations(row, col))
            {
                MarkBomb(row, col, bombCounts);
            }
        }
    }
    return bombCounts;
}
