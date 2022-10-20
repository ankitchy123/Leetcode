class Solution
{
public:
    unordered_map<int, int> mem;
    void solve(int num, int x, int count)
    {
        if (x == 1)
        {
            mem[num] = count;
            return;
        }
        if (mem.count(x))
        {
            mem[num] = mem[x] + count;
            return;
        }

        if (x % 2 == 0)
        {
            solve(num, x / 2, count + 1);
        }
        else
        {
            solve(num, x * 3 + 1, count + 1);
        }
    }

    int getKth(int lo, int hi, int k)
    {
        for (int i = lo; i <= hi; i++)
        {
            solve(i, i, 0);
        }

        vector<pair<int, int>> vec(lo);
        for (auto m : mem)
        {
            vec.push_back({m.second, m.first});
        }

        sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b)
             {
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first < b.first; });

        return vec[lo + k - 1].second;
    }
};