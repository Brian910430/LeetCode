#include <bits/stdc++.h>
using namespace std;

class ParkingSystem
{
public:
    ParkingSystem(int big, int medium, int small)
    {
        record.resize(4);
        record[1] = big;
        record[2] = medium;
        record[3] = small;
    }

    bool addCar(int carType)
    {
        if (record[carType] > 0)
        {
            record[carType]--;
            return true;
        }
        return false;
    }

private:
    vector<int> record;
};