bool comp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
    {
        return a[1] > b[1];
    }
    return a[0] < b[0];
}

class Solution
{
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        stack<int> st;
        sort(properties.begin(), properties.end(), comp);
        int ans = 0;
        for (int i = 0; i < properties.size(); i++)
        {
            while (!st.empty() && st.top() < properties[i][1])
            {
                st.pop();
                ans++;
            }

            st.push(properties[i][1]);
        }
        return ans;
    }
};