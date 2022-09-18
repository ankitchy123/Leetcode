class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int curr = 0;
        int total_fuel = 0, total_cost = 0;
        int ans = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            total_fuel += gas[i];
            total_cost += cost[i];

            curr += gas[i] - cost[i];
            if (curr < 0)
            {
                ans = i + 1;
                curr = 0;
            }
        }
        if (total_fuel < total_cost)
        {
            return -1;
        }
        return ans;
    }
};