class UndergroundSystem
{
    map<int, pair<string, int>> time;
    map<pair<string, string>, pair<int, int>> total;

public:
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        time[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        int timeTaken = t - time[id].second;
        total[{time[id].first, stationName}].first += timeTaken;
        total[{time[id].first, stationName}].second++;
    }

    double getAverageTime(string startStation, string endStation)
    {
        pair<string, string> p = {startStation, endStation};
        return (total[p].first / (double)total[p].second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */