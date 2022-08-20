class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        map<char, int> mp;
        vector<int> vec;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]] = i;
        }

        int i = 0, j = 0;
        for (int k = 0; k < s.size(); k++)
        {
            i = max(i, mp[s[k]]);
            if (i == k)
            {
                vec.push_back(i - j + 1);
                j = k + 1;
            }
        }
        return vec;
    }
};