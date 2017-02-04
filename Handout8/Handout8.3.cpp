bool TreeEqual(nodeT *t1, nodeT *t2)
{
    if ((t1 == NULL) && (t2 == NULL))
        return true;
    else if ((t1 == NULL) || (t2 == NULL))
        return false;
    else
        return ((t1->key == t2->key) &&TreeEqual(t1->left, t2->left) && TreeEqual(t1->right, t2->right));
}
            