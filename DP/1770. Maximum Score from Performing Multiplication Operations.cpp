class Solution
{
public:
    int solve(int i, int j, int n, vector<int> &nums, vector<int> &multipliers, vector<vector<int>> &dp)
    {
        if (j == multipliers.size())
        {
            return 0;
        }
        if (dp[i][j] != INT_MIN)
        {
            return dp[i][j];
        }
        int l = solve(i + 1, j + 1, n, nums, multipliers, dp) + (nums[i] * multipliers[j]);
        int r = solve(i, j + 1, n, nums, multipliers, dp) + (nums[(n - 1) - (j - i)] * multipliers[j]);
        return dp[i][j] = max(l, r);
    }

    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        int n = nums.size(), m = multipliers.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, INT_MIN));

        return solve(0, 0, n, nums, multipliers, dp);
    }
};