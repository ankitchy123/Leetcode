class Solution
{
public:
    int longestDecomposition(string text)
    {
        string word1 = "", word2 = "";
        int n = text.size();
        int ans = 0, ind = n;
        for (int i = 0; i < n / 2; i++)
        {
            word1 += text[i];
            word2 = "";
            for (int j = n - i - 1; j < ind; j++)
            {
                word2 += text[j];
            }

            if (word1 == word2)
            {
                ans += 2;
                word1 = "";
                ind = n - 1 - i;
            }
        }
        if (ind != n / 2)
        {
            ans++;
        }
        return ans;
    }
};