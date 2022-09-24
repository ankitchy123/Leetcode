class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        map<vector<int>, int> mp;

        for (int i = 0; i < grid.size(); i++)
        {
            vector<int> vec;
            for (int j = 0; j < grid[i].size(); j++)
            {
                vec.push_back(grid[j][i]);
            }
            mp[vec]++;
        }

        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            if (mp.find(grid[i]) != mp.end())
            {
                ans += mp[grid[i]];
            }
        }
        return ans;
    }
};