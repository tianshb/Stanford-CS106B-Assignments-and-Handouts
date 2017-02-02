

Cell * ConvertToListRealRecur(Vector<int> &vector, int index)
{
    if(index >= vector.size())
      return NULL;
    Cell *curr = new Cell;
    curr->value = vector[index];
    curr->next = ConvertToListRealRecur(vector, index + 1);
    return curr;
}

Cell * ConvertToListRecur(Vector<int> vector)
{
    return ConvertToRealRecur(vector, 0);
}
