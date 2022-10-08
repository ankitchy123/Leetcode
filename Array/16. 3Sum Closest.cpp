class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int prev = INT_MAX, ans, temp = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                temp = nums[i] + nums[j] + nums[k];

                if (abs(temp - target) < prev)
                {
                    prev = abs(target - temp);
                    ans = temp;
                }

                if (temp == target)
                {
                    return temp;
                }
                else if (temp < target)
                {
                    j++;
                }
                else
                {

                    k--;
                }
            }
        }
        return ans;
    }
};