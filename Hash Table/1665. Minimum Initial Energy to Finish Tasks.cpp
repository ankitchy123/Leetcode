class Solution
{
public:
    int minimumEffort(vector<vector<int>> &tasks)
    {
        sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b)
             { return (a[1] - a[0]) > (b[1] - b[0]); });

        int curr = 0, ans = 0;
        for (int i = 0; i < tasks.size(); i++)
        {
            if (tasks[i][1] > curr)
            {
                ans += tasks[i][1] - curr;
                curr = tasks[i][1];
            }
            curr -= tasks[i][0];
        }
        return ans;
    }
};