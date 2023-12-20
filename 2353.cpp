#include <bits/stdc++.h>
using namespace std;

class FoodRatings
{
public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        int n = foods.size();
        for (int i = 0; i < n; i++)
        {
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
            if (cuisineToRating.find(cuisines[i]) == cuisineToRating.end())
                cuisineToRating[cuisines[i]] = priority_queue<Food>();
            cuisineToRating[cuisines[i]].push(Food(foods[i], ratings[i]));
        }
    }

    void changeRating(string food, int newRating)
    {
        foodToRating[food] = newRating;
        cuisineToRating[foodToCuisine[food]].push(Food(food, newRating));
    }

    string highestRated(string cuisine)
    {
        auto now = cuisineToRating[cuisine].top();
        while (foodToRating[now.name] != now.rating)
        {
            cuisineToRating[cuisine].pop();
            now = cuisineToRating[cuisine].top();
        }
        return now.name;
    }

private:
    class Food
    {
    public:
        string name;
        int rating;
        bool operator<(const Food &other) const
        {
            if (rating == other.rating)
                return name > other.name;
            return rating < other.rating;
        };

        Food(string name, int rating) : name(name), rating(rating) {}
    };
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;
    unordered_map<string, priority_queue<Food>> cuisineToRating;
};