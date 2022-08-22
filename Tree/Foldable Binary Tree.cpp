// Function to check whether a binary tree is foldable or not.
bool solve(Node *left, Node *right)
{
    if (!left && !right)
    {
        return true;
    }
    if ((!left && right) || (left && !right))
    {
        return false;
    }
    bool l = solve(left->left, right->right);

    bool r = solve(left->right, right->left);

    return l && r;
}
bool IsFoldable(Node *root)
{
    // Your code goes here
    if (!root)
    {
        return true;
    }

    bool ans = solve(root->left, root->right);
    return ans;
}