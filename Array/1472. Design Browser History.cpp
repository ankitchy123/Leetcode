class BrowserHistory {
public:
    vector<string> vec;
    int count = 0, size = 0;
    BrowserHistory(string homepage) {
        vec.clear();
        vec.push_back(homepage);
        size = 1;
    }
    
    void visit(string url) {
        if(count < size - 1)
        {
            int x = size - 1 - count;
            while(x--)
            {
                vec.pop_back();
                size--;
            }
        }
        vec.push_back(url);
        size++;
        count++;
    }
    
    string back(int steps) {
        count = max(0, count - steps);
        return vec[count];
    }
    
    string forward(int steps) {
        int x = count + steps;
        if(x > size - 1)
        {
            count = size - 1;
        }
        else{
            count = x;
        }
        return vec[count];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */