class Solution
{
public:
    int countDistinctIntegers(vector<int> &nums)
    {
        set<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            st.insert(nums[i]);
            int n = nums[i];
            int num = 0;
            while (n)
            {
                int temp = n % 10;
                num = num * 10 + temp;
                n /= 10;
            }
            st.insert(num);
        }
        return st.size();
    }
};