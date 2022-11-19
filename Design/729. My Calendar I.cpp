class MyCalendar
{
public:
    set<pair<int, int>> st;
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        pair<int, int> e{start, end};
        const auto next = st.lower_bound(e);
        if (next != st.end() && next->first < end)
        {
            return false;
        }

        if (next != st.begin() && prev(next)->second > start)
        {
            return false;
        }
        st.insert(e);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */