class Solution
{
public:
    int solve(int ind, vector<vector<int>> &vec, string &s, int &ans)
    {
        int temp1 = 0, temp2 = 0;
        for (auto child : vec[ind])
        {
            int curr = solve(child, vec, s, ans);
            if (s[child] != s[ind])
            {
                if (curr > temp1)
                {
                    temp2 = temp1;
                    temp1 = curr;
                }
                else if (curr > temp2)
                {
                    temp2 = curr;
                }
            }
        }
        ans = max(ans, temp1 + temp2 + 1);
        return temp1 + 1;
    }
    int longestPath(vector<int> &parent, string s)
    {
        vector<vector<int>> vec(parent.size());
        for (int i = 1; i < parent.size(); i++)
        {
            vec[parent[i]].push_back(i);
        }

        int ans = 1;
        solve(0, vec, s, ans);
        return ans;
    }
};