class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        map<string, bool> mp;
        for (int i = 0; i < paths.size(); i++)
        {
            if (!mp[paths[i][0]])
            {
                mp[paths[i][0]] = true;
            }
        }

        for (int i = 0; i < paths.size(); i++)
        {
            if (!mp[paths[i][1]])
            {
                return paths[i][1];
            }
        }
        return "";
    }
};