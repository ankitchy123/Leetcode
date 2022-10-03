class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int ans = 0;
        int curr = neededTime[0], sum = neededTime[0];

        for (int i = 1; i < neededTime.size(); i++)
        {
            if (colors[i] != colors[i - 1])
            {
                ans += sum - curr;
                curr = neededTime[i];
                sum = neededTime[i];
            }
            else
            {
                sum += neededTime[i];
                curr = max(curr, neededTime[i]);
            }
        }
        ans += sum - curr;
        return ans;
    }
};