class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int s = 0, e = nums.size() - 1, ind = -1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target)
            {
                ind = mid;
                break;
            }
            else if (nums[mid] < target)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        if (ind == -1)
        {
            return {-1, -1};
        }
        s = ind, e = ind;
        while (s - 1 >= 0 && nums[s - 1] == nums[ind])
        {
            s--;
        }

        while (e + 1 < nums.size() && nums[e + 1] == nums[ind])
        {
            e++;
        }
        return {s, e};
    }
};