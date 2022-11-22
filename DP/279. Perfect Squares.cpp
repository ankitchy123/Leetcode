class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {
        if (n == 1)
        {
            return 1;
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }
        int ans = n;
        for (int i = 1; i * i <= n; i++)
        {
            int temp = n - i * i;
            ans = min(ans, 1 + solve(temp, dp));
        }
        return dp[n] = ans;
    }
    int numSquares(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};