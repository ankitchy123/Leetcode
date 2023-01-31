class Solution
{
public:
    int solve(vector<vector<int>> &dp, vector<pair<int, int>> &vec, int prev, int ind)
    {
        if (ind >= vec.size())
        {
            return 0;
        }

        if (dp[prev + 1][ind] != -1)
        {
            return dp[prev + 1][ind];
        }

        if (prev == -1 || vec[ind].second >= vec[prev].second)
        {
            return dp[prev + 1][ind] = max(solve(dp, vec, prev, ind + 1), vec[ind].second + solve(dp, vec, ind, ind + 1));
        }

        return dp[prev + 1][ind] = solve(dp, vec, prev, ind + 1);
    }
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        vector<pair<int, int>> vec;
        for (int i = 0; i < scores.size(); i++)
        {
            vec.push_back({ages[i], scores[i]});
        }
        sort(vec.begin(), vec.end());
        vector<vector<int>> dp(scores.size(), vector<int>(scores.size(), -1));
        return solve(dp, vec, -1, 0);
    }
};