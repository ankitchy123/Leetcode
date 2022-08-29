class Solution
{
public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        map<string, vector<string>> mp;
        for (int i = 0; i < paths.size(); i++)
        {
            string s = paths[i];
            string word = "", word2 = "", word3 = "";
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == ' ')
                {
                    word3 += '/';
                    i++;
                    while (s[i] != '(')
                    {
                        word3 += s[i];
                        i++;
                    }
                    i--;
                }
                else if (s[i] == '(')
                {
                    i++;
                    while (s[i] != ')')
                    {
                        word2 += s[i];
                        i++;
                    }
                    mp[word2].push_back(word + word3);
                    word3 = "";
                    word2 = "";
                }
                else
                {
                    word += s[i];
                }
            }
        }
        vector<vector<string>> ans;
        for (auto i : mp)
        {
            if (i.second.size() > 1)
            {
                ans.push_back(i.second);
            }
        }
        return ans;
    }
};