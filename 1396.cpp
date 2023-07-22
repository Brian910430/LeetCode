#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem
{
public:
    UndergroundSystem()
    {
        ;
    }

    void checkIn(int id, string stationName, int t)
    {
        traveler[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        time[traveler[id].first][stationName] += t - traveler[id].second;
        people[traveler[id].first][stationName]++;
        traveler.erase(id);
    }

    double getAverageTime(string startStation, string endStation)
    {
        return (double)time[startStation][endStation] / people[startStation][endStation];
    }

private:
    unordered_map<string, unordered_map<string, int>> time;
    unordered_map<string, unordered_map<string, int>> people;
    unordered_map<int, pair<string, int>> traveler;
};