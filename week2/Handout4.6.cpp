
void Append(Cell *& first, Cell* second)
{
    if (first == NULL)
    {
        first = second;
    }
    else {
        Append(first->next, second);
    }
}
