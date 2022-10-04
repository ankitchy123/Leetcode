class Solution
{
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        unordered_map<int, vector<int>> mp;
        int first = -1;

        for (int i = 0; i < adjacentPairs.size(); i++)
        {
            mp[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            mp[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        for (auto i : mp)
        {
            if (i.second.size() == 1)
            {
                first = i.first;
                break;
            }
        }
        vector<int> ans;
        ans.push_back(first);
        int prev = -1;
        while (ans.size() != adjacentPairs.size() + 1)
        {
            if (mp[first].size() == 1)
            {
                ans.push_back(mp[first][0]);
                prev = first;
                first = mp[first][0];
            }
            else
            {
                int temp = mp[first][0], temp2 = mp[first][1];
                int ele = temp == prev ? temp2 : temp;
                ans.push_back(ele);
                prev = first;
                first = ele;
            }
        }

        return ans;
    }
};