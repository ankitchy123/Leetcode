class Solution
{
public:
    static int comp(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        vector<pair<int, int>> vec;
        for (auto i : mp)
        {
            vec.push_back({i.first, i.second});
        }
        sort(vec.begin(), vec.end(), comp);
        vector<int> ans;
        for (int i = 0; i < vec.size() && i < k; i++)
        {
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};