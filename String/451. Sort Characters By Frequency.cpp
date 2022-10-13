class Solution
{
public:
    string frequencySort(string s)
    {
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }

        vector<pair<int, char>> vec;

        for (auto i : mp)
        {
            vec.push_back({i.second, i.first});
        }

        sort(vec.begin(), vec.end());
        string ans = "";
        for (int i = vec.size() - 1; i >= 0; i--)
        {
            int temp = vec[i].first;
            while (temp--)
            {
                ans += vec[i].second;
            }
        }

        return ans;
    }
};