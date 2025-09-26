#include <bits/stdc++.h>
using namespace std;

class TaskManager
{
public:
    TaskManager(vector<vector<int>> &tasks)
    {
        for (int i = 0; i < tasks.size(); i++)
            add(tasks[i][0], tasks[i][1], tasks[i][2]);
    }

    void add(int userId, int taskId, int priority)
    {
        taskToUser[taskId] = userId;
        taskToPriority[taskId] = priority;
        pq.push({priority, taskId});
    }

    void edit(int taskId, int priority)
    {
        taskToPriority[taskId] = priority;
        pq.push({priority, taskId});
    }

    void rmv(int taskId)
    {
        taskToUser.erase(taskId);
        taskToPriority.erase(taskId);
    }

    int execTop()
    {
        if (!pq.size())
            return -1;
        auto [priority, taskId] = pq.top();
        pq.pop();
        if (taskToPriority.count(taskId) && taskToPriority[taskId] == priority)
        {
            int userId = taskToUser[taskId];
            taskToUser.erase(taskId);
            taskToPriority.erase(taskId);
            return userId;
        }
        return execTop();
    }

private:
    unordered_map<int, int> taskToUser;
    unordered_map<int, int> taskToPriority;
    priority_queue<pair<int, int>> pq;
};