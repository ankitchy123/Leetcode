class DataStream
{
public:
    int i = 1, val, k, count = 0;
    DataStream(int value, int K)
    {
        val = value;
        k = K;
    }

    bool consec(int num)
    {
        if (num == val)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        if (i++ < k)
        {
            return false;
        }
        return count >= k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */