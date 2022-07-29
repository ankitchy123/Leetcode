class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        map<string, int> mp;
        for (int i = 0; i < list1.size(); i++)
        {
            mp[list1[i]] = i;
        }

        vector<string> vec;
        int ans = INT_MAX;
        for (int i = 0; i < list2.size(); i++)
        {
            if (mp.find(list2[i]) != mp.end())
            {
                int temp = mp[list2[i]] + i;
                if (temp < ans)
                {
                    ans = temp;
                    vec.clear();
                    vec.push_back(list2[i]);
                }
                else if (temp == ans)
                {
                    vec.push_back(list2[i]);
                }
            }
        }

        return vec;
    }
};