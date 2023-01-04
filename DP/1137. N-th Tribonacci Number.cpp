class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        vector<int> vec(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++)
        {
            vec[i] = vec[i - 1] + nums[i - 1];
        }
        int ans = INT_MAX;
        for (int i = 1; i <= nums.size(); i++)
        {
            int temp = target + vec[i - 1];
            auto ind = lower_bound(vec.begin(), vec.end(), temp);
            if (ind != vec.end())
            {
                ans = min(ans, static_cast<int>(ind - (vec.begin() + i - 1)));
            }
        }

        if (ans == INT_MAX)
        {
            return 0;
        }
        return ans;
    }
};

// OR

class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
        {
            return dp[n] = n;
        }
        if (n == 2)
        {
            return dp[n] = 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp) + solve(n - 3, dp);
    }
    int tribonacci(int n)
    {
        vector<int> dp(n + 1, -1);
        solve(n, dp);
        return dp[n];
    }
};