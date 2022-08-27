class CustomStack
{
public:
    vector<int> vec;
    int count;

    CustomStack(int maxSize)
    {
        count = maxSize;
    }

    void push(int x)
    {
        if (count > 0)
        {
            vec.push_back(x);
            count--;
        }
    }

    int pop()
    {
        if (vec.size() == 0)
        {
            return -1;
        }
        int temp = vec[vec.size() - 1];
        vec.pop_back();
        count++;
        return temp;
    }

    void increment(int k, int val)
    {
        int x = min<int>(k - 1, vec.size() - 1);
        for (int i = 0; i <= x; i++)
        {
            vec[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */