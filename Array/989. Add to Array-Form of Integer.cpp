class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        int c = 0, i = num.size() - 1;
        vector<int> ans;
        while (i >= 0 || k)
        {
            if (i >= 0)
            {
                k += num[i];
            }
            ans.push_back(k % 10);
            k /= 10;
            i--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};