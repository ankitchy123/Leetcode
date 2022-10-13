class Solution
{
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             {
            if (a[1] == b[1]) 
            {
                return a[0] < b[0];
            }
            return a[1] < b[1]; });

        vector<int> ans;
        ans.push_back(intervals[0][1] - 1);
        ans.push_back(intervals[0][1]);

        for (int i = 1; i < intervals.size(); i++)
        {
            int l = intervals[i][0], r = intervals[i][1];
            if (l > ans.back())
            {
                ans.push_back(r - 1);
                ans.push_back(r);
            }
            else if (l == ans.back())
            {
                ans.push_back(r);
            }
            else if (l > ans[ans.size() - 2])
            {
                ans.push_back(r);
            }
        }

        return ans.size();
    }
};