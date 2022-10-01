class Solution
{
public:
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int numWanted, int useLimit)
    {
        int n = labels.size() - 1;
        vector<pair<int, int>> vec;
        for (int i = 0; i < values.size(); i++)
        {
            vec.push_back({values[i], labels[i]});
        }

        sort(vec.begin(), vec.end());

        map<int, int> mp;
        int ans = 0;
        while (numWanted && n >= 0)
        {
            if (mp[vec[n].second] < useLimit)
            {
                numWanted--;
                ans = ans + vec[n].first;
                mp[vec[n].second]++;
            }
            n--;
        }

        return ans;
    }
};