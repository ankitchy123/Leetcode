class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        if (points.size() == 1)
        {
            return 1;
        }
        int ans = 2;
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<double, int> mp;
            for (int j = 0; j < points.size(); j++)
            {
                if (j != i)
                {
                    mp[atan2(points[j][1] - points[i][1], points[j][0] - points[i][0])]++;
                }
            }
            for (auto k : mp)
            {
                ans = max(ans, k.second + 1);
            }
        }
        return ans;
    }
};