#include <bits/stdc++.h>
using namespace std;

class MyHashSet
{
public:
    MyHashSet()
    {
        record.resize(1000005, false);
    }

    void add(int key)
    {
        record[key] = true;
    }

    void remove(int key)
    {
        record[key] = false;
    }

    bool contains(int key)
    {
        return record[key];
    }

private:
    vector<bool> record;
};