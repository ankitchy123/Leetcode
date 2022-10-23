class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> vec(nums.size() + 1);
        int dup = -1, missing = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            vec[nums[i]] += 1;
        }
        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i] == 2)
            {
                dup = i;
            }
            else if (vec[i] == 0)
            {
                missing = i;
            }
        }

        return {dup, missing};
    }
};