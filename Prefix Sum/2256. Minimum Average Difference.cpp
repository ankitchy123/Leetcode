class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long int> arr(nums.size(), 0);
        long long int curr = 0;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            arr[i] = nums[i];
            arr[i] += curr;
            curr += nums[i];
        }

        int ans = INT_MAX;
        int ind = -1;
        curr = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            curr += nums[i];
            int temp1 = curr / (i + 1);
            int temp2 = arr[i + 1] / (nums.size() - i - 1);

            if(abs(temp1 - temp2) < ans)
            {
                ans = abs(temp1 - temp2);
                ind = i;
            }
        }

        curr += nums[nums.size() - 1];
        int temp1 = curr / (nums.size());
        if(temp1 < ans)
        {
            ans = temp1;
            ind = nums.size() - 1;
        }
        return ind;
    }
};