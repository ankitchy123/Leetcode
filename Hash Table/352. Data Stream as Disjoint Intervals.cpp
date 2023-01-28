class SummaryRanges
{
public:
    set<int> st;
    SummaryRanges()
    {
    }

    void addNum(int value)
    {
        st.insert(value);
    }

    vector<vector<int>> getIntervals()
    {
        if (st.empty())
        {
            return {};
        }
        vector<vector<int>> ans;
        int s = -1, e = -1;
        for (auto i : st)
        {
            if (s < 0)
            {
                s = e = i;
            }
            else if (e + 1 == i)
            {
                e = i;
            }
            else
            {
                ans.push_back({s, e});
                s = e = i;
            }
        }
        ans.push_back({s, e});
        return ans;
    }
};

/**
 * @brief 
 * 
 */
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */