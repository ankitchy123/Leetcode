class Solution
{
public:
    int findColumn(int row, int col, vector<vector<int>> &grid)
    {
        if (row == grid.size())
        {
            return col;
        }
        int nextCol = col + grid[row][col];
        if (nextCol < 0 || nextCol >= grid[0].size() || grid[row][col] != grid[row][nextCol])
        {
            return -1;
        }
        return findColumn(row + 1, nextCol, grid);
    }

    vector<int> findBall(vector<vector<int>> &grid)
    {
        vector<int> ans(grid[0].size(), 0);
        for (int i = 0; i < grid[0].size(); i++)
        {
            ans[i] = findColumn(0, i, grid);
        }
        return ans;
    }
};