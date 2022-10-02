class Solution
{
public:
    static bool comp(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.second < p2.second;
    }

    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        vector<pair<int, int>> vec;
        sort(arr.begin(), arr.end());
        int count = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i - 1] == arr[i])
            {
                count++;
            }
            else
            {
                vec.push_back({arr[i - 1], count});
                count = 1;
            }
        }
        vec.push_back({arr[arr.size() - 1], count});
        sort(vec.begin(), vec.end(), comp);
        int i = 0;
        while (i < vec.size() && k)
        {
            if (vec[i].second > k)
            {
                break;
            }
            k = k - vec[i].second;
            i++;
        }
        return vec.size() - i;
    }
};