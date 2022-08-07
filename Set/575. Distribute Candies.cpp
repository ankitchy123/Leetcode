class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        set<int> st;
        for (int i = 0; i < candyType.size(); i++)
        {
            st.insert(candyType[i]);
        }
        int x = st.size();
        int n = candyType.size() / 2;
        if (x < n)
        {
            return x;
        }

        return n;
    }
};