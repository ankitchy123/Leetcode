class Solution
{
public:
    vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] = i;
        }
        for (int i = 0; i < operations.size(); i++)
        {
            nums[mp[operations[i][0]]] = operations[i][1];
            mp[operations[i][1]] = mp[operations[i][0]];
        }
        return nums;
    }
};