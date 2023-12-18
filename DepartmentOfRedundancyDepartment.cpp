#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr;
    map<int, int> frequency;

    int number;

    while (cin >> number) {

        if (frequency[number] == 0) arr.insert(arr.end(), number);

        frequency[number]++;

    }
    
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ' << frequency[arr[i]] << endl;
    }
    
    return 0;
}