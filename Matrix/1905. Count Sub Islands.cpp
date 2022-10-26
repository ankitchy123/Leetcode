class Solution
{
public:
    void solve(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j, bool &flag)
    {
        if (i >= grid2.size() || i < 0 || j >= grid2[0].size() || j < 0 || grid2[i][j] == 0)
        {
            return;
        }

        if (grid1[i][j] == 0)
        {
            flag = false;
            return;
        }

        grid2[i][j] = 0;
        solve(grid1, grid2, i + 1, j, flag);
        solve(grid1, grid2, i, j + 1, flag);
        solve(grid1, grid2, i, j - 1, flag);
        solve(grid1, grid2, i - 1, j, flag);
    }

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int ans = 0;
        for (int i = 0; i < grid2.size(); i++)
        {
            for (int j = 0; j < grid2[0].size(); j++)
            {
                if (grid2[i][j] == 1 && grid1[i][j] == 1)
                {
                    bool flag = true;
                    solve(grid1, grid2, i, j, flag);
                    if (flag)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};