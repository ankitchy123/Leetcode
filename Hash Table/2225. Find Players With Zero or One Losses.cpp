class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        map<int, int> mp;
        for (int i = 0; i < matches.size(); i++)
        {
            if (mp.find(matches[i][0]) == mp.end())
            {
                mp[matches[i][0]] = 0;
            }
            mp[matches[i][1]]++;
        }

        vector<int> vec1, vec2;
        for (auto i : mp)
        {
            if (i.second == 0)
            {
                vec1.push_back(i.first);
            }
            else if (i.second == 1)
            {
                vec2.push_back(i.first);
            }
        }
        return {vec1, vec2};
    }
};