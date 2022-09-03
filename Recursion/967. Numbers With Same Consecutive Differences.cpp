class Solution
{
public:
    vector<int> ans;

    void solve(int n, int k, int num, int x)
    {
        if (n == 0)
        {
            ans.push_back(num);
            return;
        }
        for (int i = 0; i <= 9; i++)
        {
            if (abs(i - x) == k)
            {
                solve(n - 1, k, num * 10 + i, i);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k)
    {
        for (int i = 1; i <= 9; i++)
        {
            solve(n - 1, k, i, i);
        }
        return ans;
    }
};