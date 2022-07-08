class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> v = nums;
        int n = nums.size();
        sort(v.begin(), v.end());

        map<int, int> m;

        for (int i = n - 1; i >= 0; i--)
        {
            m[v[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            nums[i] = m[nums[i]];
        }

        return nums;
    }
};