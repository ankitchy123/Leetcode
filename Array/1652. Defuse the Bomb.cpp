class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        vector<int> ans(code.size(), 0);
        if (k == 0)
        {
            return ans;
        }

        for (int i = 0; i < code.size(); i++)
        {
            int count = 0;
            if (k > 0)
            {
                for (int j = (i + 1) % code.size(); count < k; j = (j + 1) % code.size())
                {
                    ans[i] += code[j];
                    count++;
                }
            }
            else if (k < 0)
            {
                int count = k;
                for (int j = i - 1; count < 0; j--)
                {
                    if (j == -1)
                    {
                        j = code.size() - 1;
                    }
                    ans[i] += code[j];
                    count++;
                }
            }
        }

        return ans;
    }
};