#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int main() {
    int n, m, k;

    cin >> n >> m >> k;

    int wishSize[n];
    int apartmentSize[m];
    
    for (int i = 0; i < n; i++) cin >> wishSize[i];
    for (int i = 0; i < m ; i++)  cin >> apartmentSize[i];


    sort(wishSize, wishSize + n);
    sort(apartmentSize, apartmentSize + m);


    int i = 0;
    int j = 0;

    int result = 0;

    while (i < n && j < m) {
        if (abs(wishSize[i] - apartmentSize[j]) <= k) {
            result++;
            i++;
            j++;
        } else {
            if (wishSize[i] - apartmentSize[j] > k) j++;
            else i++;
        }
    }

    cout << result;


    return 0;
}