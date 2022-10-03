class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int i = 0, j = 0;
        int ans = 0;

        while (i < neededTime.size() && j < neededTime.size())
        {
            int curr = 0, sum = 0;
            while (j < neededTime.size() && colors[i] == colors[j])
            {
                sum += neededTime[j];
                curr = max(curr, neededTime[j]);
                j++;
            }
            ans += sum - curr;
            i = j;
        }
        return ans;
    }
};