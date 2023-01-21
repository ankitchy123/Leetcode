class Solution
{
public:
    int solve(string word1, string word2, int i, int j, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            return j;
        }
        if (j == 0)
        {
            return i;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int count = 0;
        if (word1[i - 1] == word2[j - 1])
        {
            count = solve(word1, word2, i - 1, j - 1, dp);
        }
        else
        {
            int op1 = solve(word1, word2, i, j - 1, dp);
            int op2 = solve(word1, word2, i - 1, j, dp);
            int op3 = solve(word1, word2, i - 1, j - 1, dp);
            count = min(op1, min(op2, op3)) + 1;
        }
        return dp[i][j] = count;
    }
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));
        for (int i = 1; i <= word1.size(); i++)
        {
            dp[i][0] = i;
        }
        for (int i = 1; i <= word2.size(); i++)
        {
            dp[0][i] = i;
        }
        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word2[j - 1] == word1[i - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                }
            }
        }

        return dp[word1.size()][word2.size()];
    }
};