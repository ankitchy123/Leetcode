class Solution
{
public:
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
    {
        vector<int> q, w;
        for (int i = 0; i < queries.size(); i++)
        {
            map<char, int> mp;

            for (int j = 0; j < queries[i].size(); j++)
            {
                mp[queries[i][j]]++;
            }

            auto it = mp.begin();
            q.push_back(it->second);
        }

        for (int i = 0; i < words.size(); i++)
        {
            map<char, int> mp;

            for (int j = 0; j < words[i].size(); j++)
            {
                mp[words[i][j]]++;
            }

            auto it = mp.begin();
            w.push_back(it->second);
        }

        vector<int> ans;
        for (int i = 0; i < q.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < w.size(); j++)
            {
                if (q[i] < w[j])
                {
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};