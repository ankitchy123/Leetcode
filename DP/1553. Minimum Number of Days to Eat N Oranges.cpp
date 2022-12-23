class Solution
{
public:
    unordered_map<int, int> dp;
    int solve(int n)
    {
        if (dp.find(n) != dp.end())
        {
            return dp[n];
        }
        int ans = INT_MAX;
        if (n % 2 == 0)
        {
            ans = min(ans, 1 + solve(n / 2));
        }
        if (n % 3 == 0)
        {
            ans = min(ans, 1 + solve(n / 3));
        }
        if (n % 3 != 0 || n % 2 != 0)
        {
            ans = min(ans, 1 + solve(n - 1));
        }
        return dp[n] = ans;
    }
    int minDays(int n)
    {
        dp[0] = 0;
        dp[1] = 1;
        return solve(n);
    }
};