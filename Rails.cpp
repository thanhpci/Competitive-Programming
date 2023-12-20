#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int N;
    int coach[1000];

    while (true)
    {
        cin >> N;
        if (N == 0) break;


        while (true) {
            cin >> coach[0];
            if (coach[0] == 0) {
                cout << endl;
                break;
            }

            for (int i = 1; i < N; i++) {
                cin >> coach[i];
            }

            stack<int> station;
            int curCoach = 0;
            int trueOrder = 1;


            while (trueOrder <= N) {
                station.push(trueOrder);

                while (!station.empty() && station.top() == coach[curCoach]) {
                    station.pop();
                    curCoach++;
                    if (curCoach >= N) break;
                }
                trueOrder++;
            }


            if (station.empty()) cout << "Yes" << endl;
            else cout << "No" << endl;




        }
    }

    return 0;
}