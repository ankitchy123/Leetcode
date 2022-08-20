class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> ans;

        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            map<char, int> mp1;
            map<char, int> mp2;
            bool match = true;

            for (int j = 0; j < word.size(); j++)
            {
                if (mp1.find(pattern[j]) == mp1.end())
                {
                    mp1[pattern[j]] = word[j];
                }
                if (mp2.find(word[j]) == mp2.end())
                {
                    mp2[word[j]] = pattern[j];
                }
                if (mp1[pattern[j]] != word[j] || mp2[word[j]] != pattern[j])
                {
                    match = false;
                    break;
                }
            }

            if (match == true)
            {
                ans.push_back(word);
            }
        }
        return ans;
    }
};