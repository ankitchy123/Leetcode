class SeatManager
{
public:
    priority_queue<int> pq;
    int n = 1;
    SeatManager(int n)
    {
    }

    int reserve()
    {
        if (pq.empty())
        {
            return n++;
        }
        int temp = pq.top();
        pq.pop();
        return -temp;
    }

    void unreserve(int seatNumber)
    {
        pq.push(-seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */