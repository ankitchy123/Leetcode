class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        map<int, int> mp;
        for (int i = 0; i < tasks.size(); i++)
        {
            mp[tasks[i]]++;
        }

        int ans = 0;
        for (auto i : mp)
        {
            cout << i.second << " ";
            if (i.second == 1)
            {
                return -1;
            }

            if (i.second % 3 == 0)
            {
                ans += i.second / 3;
            }
            else
            {
                ans += (i.second / 3) + 1;
            }
        }
        return ans;
    }
};