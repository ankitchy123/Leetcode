class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> mp;
        for (int i = 0; i < nums2.size(); i++)
        {
            mp[nums2[i]] = i;
        }
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++)
        {
            int j = mp[nums1[i]];
            int num = -1;
            for (int k = j + 1; k < nums2.size(); k++)
            {
                if (nums2[k] > nums1[i])
                {
                    num = nums2[k];
                    break;
                }
            }
            ans.push_back(num);
        }
        return ans;
    }
};