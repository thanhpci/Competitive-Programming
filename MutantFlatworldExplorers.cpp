#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct robot
{
    int x;
    int y;
    char orientation;
    string instructions;
    bool lost = false;

    robot(int _x, int _y, char _orientation, string _instructions)
    {
        x = _x;
        y = _y;
        orientation = _orientation;
        instructions = _instructions;
    }

    void forward(int maxX, int maxY, set<pair<int, int>> &scent)
    {
        int nextX = x;
        int nextY = y;

        if (orientation == 'N')
            nextY++;
        else if (orientation == 'E')
            nextX++;
        else if (orientation == 'W')
            nextX--;
        else if (orientation == 'S')
            nextY--;

        if (nextX < 0 || nextY < 0 || nextX > maxX || nextY > maxY) {
            if (scent.find({x, y}) == scent.end()) {
                scent.insert({x, y});
                lost=true;
            }
        } else {            x = nextX;
            y = nextY;
        }
    }

    void turnRight()
    {
        if (orientation == 'N')
            orientation = 'E';
        else if (orientation == 'E')
            orientation = 'S';
        else if (orientation == 'S')
            orientation = 'W';
        else if (orientation == 'W')
            orientation = 'N';
    }

    void turnLeft()
    {
        if (orientation == 'N')
            orientation = 'W';
        else if (orientation == 'W')
            orientation = 'S';
        else if (orientation == 'S')
            orientation = 'E';
        else if (orientation == 'E')
            orientation = 'N';
    }

    void runInstructions(int maxX, int maxY, set<pair<int, int>> &scent)
    {
        for (int i = 0; i < instructions.size(); i++)
        {
            if (lost)
                break;
            else if (instructions[i] == 'F')
                forward(maxX, maxY, scent);
            else if (instructions[i] == 'R')
                turnRight();
            else if (instructions[i] == 'L')
                turnLeft();
        }
    }
};

int main()
{

    int maxX, maxY;
    cin >> maxX >> maxY;

    int x, y;
    char orientation;

    set<pair<int, int>> scent;

    while (cin >> x >> y >> orientation)
    {
        cin.ignore();
        string instruction;
        getline(cin, instruction);

        robot r(x, y, orientation, instruction);
        r.runInstructions(maxX, maxY, scent);

        cout << r.x << " " << r.y << " " << r.orientation;

        if (r.lost) cout << " LOST";
        cout << endl;
    }

    return 0;
}

