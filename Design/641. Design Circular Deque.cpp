class MyCircularDeque
{
public:
    vector<int> vec;
    int size, curr = 0;
    int front, rear;
    ;
    MyCircularDeque(int k)
    {
        size = k;
        front = -1;
        rear = -1;
        vec.resize(k, -1);
    }

    bool insertFront(int value)
    {
        if (isFull())
        {
            return false;
        }
        if (curr == 0)
        {
            front = 0, rear = 0;
        }
        else
        {
            front = (front == 0) ? size - 1 : front - 1;
        }

        curr++;
        vec[front] = value;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
        {
            return false;
        }
        if (curr == 0)
        {
            front = 0, rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }

        curr++;
        vec[rear] = value;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
        {
            return false;
        }

        curr--;
        front = (front + 1) % size;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
        {
            return false;
        }
        curr--;
        rear = (rear == 0) ? size - 1 : rear - 1;
        return true;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return vec[front];
    }

    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return vec[rear];
    }

    bool isEmpty()
    {
        return curr == 0;
    }

    bool isFull()
    {
        return curr == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */