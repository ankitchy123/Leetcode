class RangeFreqQuery
{
public:
    unordered_map<int, vector<int>> mp;
    RangeFreqQuery(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]].push_back(i);
        }
    }
    int query(int left, int right, int value)
    {
        if (mp.count(value) == 0)
        {
            return 0;
        }
        auto &v = mp[value];
        // 1, 7
        int j = upper_bound(begin(v), end(v), right) - begin(v);
        int i = lower_bound(begin(v), end(v), left) - begin(v);
        return j - i;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */