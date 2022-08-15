class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> ans;
        int j = 1;
        for (int i = 0; i < target.size(); i++)
        {
            if (target[i] == j)
            {
                ans.push_back("Push");
            }
            else
            {
                i--;
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            j++;
        }
        return ans;
    }
};