#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int shop, movie, price;
    bool operator<(const Node &other) const
    {
        if (price != other.price)
            return price < other.price;
        if (shop != other.shop)
            return shop < other.shop;
        return movie < other.movie;
    }
};

class MovieRentingSystem
{
public:
    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {
        for (auto i : entries)
        {
            Node node = Node{i[0], i[1], i[2]};
            byPair[hash(i[0], i[1])] = node;
            availableByMovie[i[1]].insert(node);
        }
    }

    vector<int> search(int movie)
    {
        vector<int> ans = vector<int>();
        int i = 1;
        for (auto node : availableByMovie[movie])
        {
            ans.push_back(node.shop);
            if (i++ == 5)
                break;
        }
        return ans;
    }

    void rent(int shop, int movie)
    {
        Node node = byPair[hash(shop, movie)];
        rentedSet.insert(node);
        availableByMovie[node.movie].erase(node);
    }

    void drop(int shop, int movie)
    {
        Node node = byPair[hash(shop, movie)];
        rentedSet.erase(node);
        availableByMovie[node.movie].insert(node);
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> ans = vector<vector<int>>();
        int i = 1;
        for (auto node : rentedSet)
        {
            ans.push_back({node.shop, node.movie});
            if (i++ == 5)
                break;
        }
        return ans;
    }

private:
    unordered_map<long long, Node> byPair;
    unordered_map<int, set<Node>> availableByMovie;
    set<Node> rentedSet;

    long long hash(int shop, int movie)
    {
        return ((long long)shop << 32) ^ movie;
    }
};