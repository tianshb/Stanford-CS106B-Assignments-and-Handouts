void TrimLeaves(nodeT * & tree)
{
    if (tree != NULL)
    {
        if ((node->left == NULL) && (node->right == NULL))
        {
            delete tree;
            tree = NULL;
        }
        else
        {
            TrimLeaves(tree->left);
            TrimLeaves(tree->right);
        }
    }
}
