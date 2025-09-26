#include <bits/stdc++.h>
using namespace std;

class Spreadsheet
{
public:
    Spreadsheet(int rows)
    {
        record = vector<vector<int>>(26, vector<int>(rows + 1, 0));
    }

    void setCell(string cell, int value)
    {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1, cell.size() - 1));
        record[col][row] = value;
    }

    void resetCell(string cell)
    {
        setCell(cell, 0);
    }

    int getValue(string formula)
    {
        int op1, op2;
        int index = 1;
        while (formula[index] != '+')
            index++;
        string s1 = formula.substr(1, index - 1);
        string s2 = formula.substr(index + 1, formula.size() - index - 1);

        op1 = '0' <= s1[0] && s1[0] <= '9' ? stoi(s1) : record[s1[0] - 'A'][stoi(s1.substr(1, s1.size() - 1))];
        op2 = '0' <= s2[0] && s2[0] <= '9' ? stoi(s2) : record[s2[0] - 'A'][stoi(s2.substr(1, s2.size() - 1))];
        return op1 + op2;
    }

private:
    vector<vector<int>> record;
};