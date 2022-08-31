class FreqStack
{
    map<int, int> mp;
    map<int, stack<int>> mp2;
    int freq;

public:
    FreqStack()
    {
        freq = 0;
    }

    void push(int val)
    {
        mp[val]++;
        int temp = mp[val];
        freq = max(freq, temp);
        mp2[temp].push(val);
    }

    int pop()
    {
        int temp = mp2[freq].top();
        mp2[freq].pop();
        mp[temp]--;
        if (mp2[freq].size() == 0)
        {
            freq--;
        }
        return temp;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */