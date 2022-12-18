class Solution
{
public:
    vector<string> getFolderNames(vector<string> &names)
    {
        unordered_map<string, int> mp;
        for (int i = 0; i < names.size(); i++)
        {
            if (mp.find(names[i]) != mp.end())
            {
                int k = mp[names[i]];
                while (mp.find(names[i] + "(" + to_string(k) + ")") != mp.end())
                {
                    k++;
                    mp[names[i]]++;
                }
                mp[names[i]]++;
                names[i] = names[i] + "(" + to_string(k) + ")";
            }
            mp[names[i]] = 1;
        }
        return names;
    }
};