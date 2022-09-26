class Solution
{
public:
    bool solve(string s, string word)
    {
        int i = 0, j = 0;
        while (i < s.size() && j < word.size())
        {
            if (s[i] != word[j])
            {
                return false;
            }
            int count1 = 1, count2 = 1;
            while (i < s.size() && s[i] == s[++i])
            {
                count1++;
            }
            while (j < word.size() && word[j] == word[++j])
            {
                count2++;
            }
            if (count1 != count2 && (count2 > count1 || count1 < 3))
            {
                return false;
            }
        }
        return i == s.size() && j == word.size();
    }

    int expressiveWords(string s, vector<string> &words)
    {
        int ans = 0;
        for (int i = 0; i < words.size(); i++)
        {
            ans += solve(s, words[i]);
        }
        return ans;
    }
};