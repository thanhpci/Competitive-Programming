#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void dfs(int start, vector<vector<int>> &graph, vector<bool> &visited)
{
    for (int neighbor : graph[start])
    {
        if (!visited[neighbor])
        {
            visited[neighbor] = true;
            dfs(neighbor, graph, visited);
        }
    }
}

int main()
{
    int n;

    while (cin >> n && n != 0)
    {

        vector<vector<int>> adjacentList(n + 1);

        int u, v;

        // The adjacent list of u is edges signed to v
        while (cin >> u && u != 0)
        {
            while (cin >> v && v != 0)
            {
                adjacentList[u].push_back(v);
            }
        }

        int startSize, start;
        vector<bool> visited(n + 1);

        cin >> startSize;

        while (startSize--)
        {
            fill(visited.begin(), visited.end(), false);

            cin >> start;
            dfs(start, adjacentList, visited);

            vector<int> inaccessible;
            for (int i = 1; i <= n; i++)
            {
                if (!visited[i])
                {
                    inaccessible.push_back(i);
                }
            }

            cout << inaccessible.size() << ' ';
            for (int vertex : inaccessible){
                cout << vertex << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}

