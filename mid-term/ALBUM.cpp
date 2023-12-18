#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<int> album1, album2;

    for (int i = 0; i < n; i++) {
        int stamp;
        cin >> stamp;
        album1.insert(stamp);
    }

    for (int i = 0; i < m; i++) {
        int stamp;
        cin >> stamp;
        album2.insert(stamp);
    }

    vector<int> commonStamps;
    for (int stamp : album1) {
        if (album2.count(stamp)) {
            commonStamps.push_back(stamp);
        }
    }

    cout << commonStamps.size() << endl;
    for (int stamp : commonStamps) {
        cout << stamp << " ";
    }

    return 0;
}
