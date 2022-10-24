class SmallestInfiniteSet
{
public:
    set<int> st;
    int ind = 1;
    SmallestInfiniteSet()
    {
    }

    int popSmallest()
    {
        int num = ind;
        st.insert(num);
        while (st.find(ind + 1) != st.end())
        {
            ind++;
        }
        ind++;
        return num;
    }

    void addBack(int num)
    {
        if (st.find(num) != st.end())
        {
            st.erase(num);
            ind = min(ind, num);
            cout << ind << " ";
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */