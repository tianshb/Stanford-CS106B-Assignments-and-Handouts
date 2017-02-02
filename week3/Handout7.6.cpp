void Unstutter(Node *list)
{
    for(Node *cur = list; cur != NULL; cur = cur->next)
    {
        if (cur->next != NULL && cur->value == cur->next->value)
        {
            Node* dup=cur->next;
            cur->next=cur->next->next;
            delete dup;
        }
    }
}
