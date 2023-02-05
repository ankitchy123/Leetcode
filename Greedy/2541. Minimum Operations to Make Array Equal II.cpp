class Solution
{
public:
    long long minOperations(vector<int> &nums1, vector<int> &nums2, int k)
    {
        if (nums1 == nums2)
        {
            return 0;
        }
        if (k == 0)
        {
            return -1;
        }

        long long count1 = 0, count2 = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] > nums2[i])
            {
                if ((nums1[i] - nums2[i]) % k == 0)
                {
                    count1 += (nums1[i] - nums2[i]) / k;
                }
                else
                {
                    return -1;
                }
            }
            else if (nums1[i] < nums2[i])
            {
                if ((nums2[i] - nums1[i]) % k == 0)
                {
                    count2 += (nums2[i] - nums1[i]) / k;
                }
                else
                {
                    return -1;
                }
            }
        }

        if (count1 == count2)
        {
            return count1;
        }
        return -1;
    }
};