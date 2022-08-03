class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int j = 0;
        int ans = 0;

        while (j < strs[0].size())
        {
            char c = strs[0][j];
            for (int i = 1; i < strs.size(); i++)
            {
                if (c > strs[i][j])
                {
                    ans++;
                    break;
                }
                c = strs[i][j];
            }
            j++;
        }

        return ans;
    }
};