class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        map<string, int> mp;
        string word = "";
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == ' ')
            {
                mp[word]++;
                word = "";
                continue;
            }
            word += s1[i];
        }
        mp[word]++;
        word = "";

        for (int i = 0; i < s2.size(); i++)
        {
            if (s2[i] == ' ')
            {
                mp[word]++;
                word = "";
                continue;
            }
            word += s2[i];
        }
        mp[word]++;
        word = "";

        vector<string> vec;
        for (auto &i : mp)
        {
            if (i.second == 1)
            {
                vec.push_back(i.first);
            }
        }

        return vec;
    }
};