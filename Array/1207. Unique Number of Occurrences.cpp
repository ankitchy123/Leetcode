class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int count = 1;
        vector<int> vec;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] == arr[i - 1])
            {
                count++;
            }
            else
            {
                vec.push_back(count);
                count = 1;
            }
        }
        vec.push_back(count);

        sort(vec.begin(), vec.end());

        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i] == vec[i - 1])
            {
                return false;
            }
        }
        cout << endl;

        return true;
    }
};