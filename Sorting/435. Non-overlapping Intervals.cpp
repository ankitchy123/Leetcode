class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int ans = 0, prev = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < prev)
            {
                ans++;
                if (intervals[i][1] < prev)
                {
                    prev = intervals[i][1];
                }
            }
            else
            {
                prev = intervals[i][1];
            }
        }
        return ans;
    }
};