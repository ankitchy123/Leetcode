class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, int> mp;

        for (int i = 0; i < order.size(); i++)
        {
            mp[order[i]] = i;
        }

        for (int i = 0; i < words.size() - 1; i++)
        {
            int n = min(words[i].size(), words[i + 1].size());

            for (int j = 0; j < n; j++)
            {
                if (words[i][j] != words[i + 1][j])
                {
                    if (mp[words[i][j]] > mp[words[i + 1][j]])
                    {
                        return false;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            if (words[i].size() > words[i + 1].size() && words[i][words[i + 1].size() - 1] == words[i + 1][words[i + 1].size() - 1])
            {
                return false;
            }
        }

        return true;
    }
};