class MyStack
{
public:
    queue<int> q1;
    int size;
    MyStack()
    {
        size = 0;
    }

    void push(int x)
    {
        q1.push(x);
        int count = size;
        while (count--)
        {
            q1.push(q1.front());
            q1.pop();
        }
        size++;
    }

    int pop()
    {
        int ele = q1.front();
        q1.pop();
        size--;
        return ele;
    }
    // 3 2 1
    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return size == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */