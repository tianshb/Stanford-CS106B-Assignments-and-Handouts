struct Node{
    int value;
    Node* next;
};

void(Node* list)
{
    for(Node* cur=list;cur!=NULL;cur=cur->next)
    {
        Node* dup=new Node;
        dup->next=cur->next;
        dup->value=cur->value;
        cur->next=dup;
        cur=dup;
    }
}