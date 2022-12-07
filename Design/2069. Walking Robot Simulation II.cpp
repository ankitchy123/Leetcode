class Robot
{
public:
    int x, y, k = 0;
    vector<vector<int>> arr;
    bool flag = true;

    Robot(int width, int height)
    {
        y = width;
        x = height;
        for (int j = 0; j < y; j++)
        {
            arr.push_back({0, j, 101});
        }
        for (int i = 1; i < x; i++)
        {
            arr.push_back({i, y - 1, 102});
        }
        for (int j = y - 2; j >= 0; j--)
        {
            arr.push_back({x - 1, j, 103});
        }
        for (int i = x - 2; i > 0; i--)
        {
            arr.push_back({i, 0, 104});
        }
    }

    void step(int num)
    {
        if (flag)
        {
            flag = false;
        }
        num = num % arr.size();
        while (k < arr.size() && num)
        {
            k++;
            num--;
        }
        if (k == arr.size())
        {
            k = 0;
        }
        while (num)
        {
            k++;
            num--;
        }
    }

    vector<int> getPos()
    {
        return {arr[k][1], arr[k][0]};
    }

    string getDir()
    {
        if (flag)
        {
            return "East";
        }
        if (arr[k][0] == 0 && arr[k][1] == 0)
        {
            return "South";
        }
        if (arr[k][2] == 101)
        {
            return "East";
        }
        if (arr[k][2] == 102)
        {
            return "North";
        }
        if (arr[k][2] == 103)
        {
            return "West";
        }
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */