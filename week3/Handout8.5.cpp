int TreeHeight(nodeT *tree)
{
    if (tree == NULL)
    {
        return 0;
    } else
    {
        return (1 + max(TreeHeight(tree->left),TreeHeight(tree->right)));
    }
}

bool IsBalanced(nodeT *tree)
{
    if (tree == NULL)
    {
        return true;
    } else
    {
        return((abs(TreeHeight(tree->left)-TreeHeight(tree->right)) <= 1) && IsBalanced(tree->left) && IsBalanced(tree->right));
    }
}
              
                        