class Solution
{
public:
    int minPartitions(string n)
    {
        char c = NULL;
        for (int i = 0; i < n.size(); i++)
        {
            c = max(c, n[i]);
        }
        return c - 48;
    }
};