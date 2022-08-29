class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            int j = 0, k = grid[i].size() - 1;
            while (j <= k)
            {
                int mid = j + (k - j) / 2;
                if (grid[i][mid] >= 0)
                {
                    j = mid + 1;
                }
                else
                {
                    ans += k - mid + 1;
                    k = mid - 1;
                }
            }
        }
        return ans;
    }
};