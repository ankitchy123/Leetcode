class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        unordered_set<int> st;

        for (int i = 0; i < arr.size(); i++)
        {
            if (st.find(arr[i] * 2) != st.end() || st.find(arr[i] / 2) != st.end() && arr[i] % 2 == 0)
            {
                return true;
            }
            st.insert(arr[i]);
        }

        return false;
    }
};