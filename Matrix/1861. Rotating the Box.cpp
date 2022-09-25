class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans[i][j] = box[m - 1 - j][i];
            }
        }

        for (int i = 0; i < ans[0].size(); i++)
        {
            int end = n;
            for (int j = ans.size() - 1; j >= 0; j--)
            {
                if (ans[j][i] == '*')
                {
                    end = j;
                }
                else if (ans[j][i] == '#')
                {
                    ans[end - 1][i] = '#';
                    if (j != end - 1)
                    {
                        ans[j][i] = '.';
                    }
                    end--;
                }
            }
        }
        return ans;
    }
};