class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        map<char, int> mp;
        string s = "qwertyuiop";
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]] = 1;
            mp[toupper(s[i])] = 1;
        }
        s = "asdfghjkl";
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]] = 2;
            mp[toupper(s[i])] = 2;
        }
        s = "zxcvbnm";
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]] = 3;
            mp[toupper(s[i])] = 3;
        }

        vector<string> vec;
        for (int i = 0; i < words.size(); i++)
        {
            bool ans = true;
            int num = mp[words[i][0]];
            for (int j = 1; j < words[i].size(); j++)
            {
                if (mp[words[i][j]] != num)
                {
                    ans = false;
                }
            }

            if (ans == true)
            {
                vec.push_back(words[i]);
            }
        }

        return vec;
    }
};