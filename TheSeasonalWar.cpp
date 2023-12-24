#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int x, int y, vector<vector<int>> &image, int n)
{
    image[x][y] = 2;
    for (int i = 0; i < 8; i++)
    {
        int _x = x + dx[i];
        int _y = y + dy[i];
        if (_x >= 0 && _y >= 0 && _x < n && _y < n && image[_x][_y] == 1)
            dfs(_x, _y, image, n);
    }
}

int countWarEagle(vector<vector<int>> &image, int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (image[i][j] == 1)
            {
                dfs(i, j, image, n);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    string s;

    int numberImage = 1;

    while (cin >> n)
    {
        cin.ignore();

        vector<vector<int>> image(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            getline(cin, s);
            for (int j = 0; j < n; j++)
            {
                image[i][j] = s[j] - '0';
            }
        }

        cout << "Image number " << numberImage++ << " contains " << countWarEagle(image, n) << " war eagles." << endl;
    }

    return 0;
}
