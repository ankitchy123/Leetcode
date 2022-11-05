class Solution
{
public:
    vector<int> memLeak(int memory1, int memory2)
    {
        int sec = 1;
        while (sec <= max(memory1, memory2))
        {
            if (memory2 > memory1)
            {
                memory2 -= sec;
            }
            else
            {
                memory1 -= sec;
            }
            sec++;
        }
        return {sec, memory1, memory2};
    }
};