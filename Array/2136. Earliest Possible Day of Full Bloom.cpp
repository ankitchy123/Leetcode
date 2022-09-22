class Solution
{
public:
    static bool comp(pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.second == p2.second)
        {
            return p1.first < p2.first;
        }
        return p1.second > p2.second;
    }

    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
    {
        vector<pair<int, int>> vec;

        for (int i = 0; i < plantTime.size(); i++)
        {
            vec.push_back({plantTime[i], growTime[i] + 1});
        }
        sort(vec.begin(), vec.end(), comp);
        int days = -1;
        int maxx = INT_MIN;

        for (int i = 0; i < vec.size(); i++)
        {
            days += vec[i].first;
            maxx = max(maxx, days + vec[i].second);
        }
        return maxx;
    }
};