class Solution
{
public:
    int longestBeautifulSubstring(string word)
    {
        int i = 0;
        int ans = 0, curr = 1, count = 1;
        for (int i = 1; i < word.size(); i++)
        {
            if (word[i - 1] == word[i])
            {
                curr++;
            }
            else if (word[i - 1] < word[i])
            {
                curr++;
                count++;
            }
            else
            {
                count = 1;
                curr = 1;
            }

            if (count == 5)
            {
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};