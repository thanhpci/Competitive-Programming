/**
Robotics, robot motion planning, and machine learning are areas that cross the boundaries of many of
the subdisciplines that comprise Computer Science: artificial intelligence, algorithms and complexity,
electrical and mechanical engineering to name a few. In addition, robots as “turtles” (inspired by
work by Papert, Abelson, and diSessa) and as “beeper-pickers” (inspired by work by Pattis) have been
studied and used by students as an introduction to programming for many years.
This problem involves determining the position of a robot exploring a pre-Columbian flat world.
Given the dimensions of a rectangular grid and a sequence of robot positions and instructions, you
are to write a program that determines for each sequence of robot positions and instructions the final
position of the robot.
A robot position consists of a grid coordinate (a pair of integers: x-coordinate followed by ycoordinate) and an orientation (N,S,E,W for north, south, east, and west). A robot instruction is a string
of the letters ‘L’, ‘R’, and ‘F’ which represent, respectively, the instructions:
• Left: the robot turns left 90 degrees and remains on the current grid point.
• Right: the robot turns right 90 degrees and remains on the current grid point.
• Forward: the robot moves forward one grid point in the direction of the current orientation and
mantains the same orientation.
The direction North corresponds to the direction from grid point (x, y) to grid point (x, y + 1).
Since the grid is rectangular and bounded, a robot that moves “off” an edge of the grid is lost
forever. However, lost robots leave a robot “scent” that prohibits future robots from dropping off the
world at the same grid point. The scent is left at the last grid position the robot occupied before
disappearing over the edge. An instruction to move “off” the world from a grid point from which a
robot has been previously lost is simply ignored by the current robot.
Input
The first line of input is the upper-right coordinates of the rectangular world, the lower-left coordinates
are assumed to be 0,0.
The remaining input consists of a sequence of robot positions and instructions (two lines per robot).
A position consists of two integers specifying the initial coordinates of the robot and an orientation
(N,S,E,W), all separated by white space on one line. A robot instruction is a string of the letters ‘L’, ‘R’,
and ‘F’ on one line.
Each robot is processed sequentially, i.e., finishes executing the robot instructions before the next
robot begins execution.
Input is terminated by end-of-file.
You may assume that all initial robot positions are within the bounds of the specified grid. The
maximum value for any coordinate is 50. All instruction strings will be less than 100 characters in
length.
Output
For each robot position/instruction in the input, the output should indicate the final grid position and
orientation of the robot. If a robot falls off the edge of the grid the word ‘LOST’ should be printed after
the position and orientation.
Sample Input
5 3
1 1 E
RFRFRFRF
3 2 N
FRRFLLFFRRFLL
0 3 W
LLFFFLFLFL
Sample Output
1 1 E
3 3 N LOST
2 3 S
 */

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

