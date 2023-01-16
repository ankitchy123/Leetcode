class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        bool flag = false;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (newInterval[0] < intervals[i][0])
            {
                intervals.insert(intervals.begin() + i, newInterval);
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            intervals.push_back(newInterval);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++)
        {
            vector<int> curr = {intervals[i][0], intervals[i][1]};
            i++;
            while (i < intervals.size() && intervals[i][0] <= curr[1])
            {
                curr = {min(intervals[i][0], curr[0]), max(intervals[i][1], curr[1])};
                i++;
            }
            i--;
            ans.push_back(curr);
        }
        return ans;
    }
};