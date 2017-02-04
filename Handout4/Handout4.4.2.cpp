int SumListRecur(Cell *list)
{
    if(list == NULL)
        return 0;
    else
        return list->value + SumListRecur(list->next);
}
