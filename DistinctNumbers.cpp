#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

    set<int> numbers;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;

        numbers.insert(x);
    }

    cout << numbers.size();

    return 0;
}