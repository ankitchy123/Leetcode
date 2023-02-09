class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {
        unordered_set<string> st[26];
        for (int i = 0; i < ideas.size(); i++)
        {
            st[ideas[i][0] - 'a'].insert(ideas[i].substr(1));
        }
        long long ans = 0;
        for (int i = 0; i < 25; i++)
        {
            for (int j = i + 1; j < 26; j++)
            {
                int temp = 0;
                for (auto k : st[i])
                {
                    if (st[j].count(k))
                    {
                        temp++;
                    }
                }

                ans += 2LL * (st[i].size() - temp) * (st[j].size() - temp);
            }
        }
        return ans;
    }
};