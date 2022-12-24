class Allocator
{
public:
    vector<int> vec;
    Allocator(int n)
    {
        vec.resize(n, -1);
    }

    int allocate(int size, int mID)
    {
        int mem = 0, i = 0;
        for (i = 0; i < vec.size(); i++)
        {
            if (vec[i] == -1)
            {
                mem++;
            }
            else
            {
                mem = 0;
            }

            if (mem == size)
            {
                break;
            }
        }

        if (mem != size)
        {
            return -1;
        }

        int ind = i - size + 1;
        for (int j = 0; j < size; j++)
        {
            vec[j + ind] = mID;
        }
        return ind;
    }

    int free(int mID)
    {
        int count = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == mID)
            {
                count++;
                vec[i] = -1;
            }
        }
        return count;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */