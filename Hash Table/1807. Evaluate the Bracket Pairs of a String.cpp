class Solution
{
public:
    string evaluate(string s, vector<vector<string>> &knowledge)
    {
        unordered_map<string, string> mp;
        string ans;
        for (int i = 0; i < knowledge.size(); i++)
        {
            mp.insert({knowledge[i][0], knowledge[i][1]});
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                i++;
                string word;
                while (s[i] != ')')
                {
                    word.push_back(s[i]);
                    i++;
                }

                if (mp.count(word))
                {
                    ans += mp[word];
                }
                else
                    ans.push_back('?');
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};