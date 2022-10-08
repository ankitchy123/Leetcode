class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [](int a, int b)
             {
            string x = to_string(a), y = to_string(b);
            return x + y > y + x; });

        if (nums[0] == 0)
        {
            return "0";
        }

        string ans = "";
        for (int i = 0; i < nums.size(); i++)
        {
            ans += to_string(nums[i]);
        }

        return ans;
    }
};