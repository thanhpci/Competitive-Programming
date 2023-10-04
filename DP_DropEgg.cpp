/**
DROPEGG (EGGDROP) 
Cho k quả trứng và n tầng. Tìm số lần thử nghiệm ít nhất để xác định tầng gần nhất (thấp nhất) để quả trứng 
ném không bị vỡ) 
INPUT: 
Gồm 1 dòng là 2 số n và k. 
OUTPUT: 
In ra 1 số nguyên duy nhất là đáp án. 
GIỚI HẠN: 
1 <= n,k <= 3000 
 * 
 */



#include <bits/stdc++.h>
#include <iostream>

using namespace std;



int dropegg(int k, int n) {

    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        dp[1][i] = i;
    }

    for (int i = 1; i <= k; i++) {
        dp[i][1] = 1;
    }

    if (k <= 1 || n <= 1) return dp[k][n];

    for (int egg = 2; egg <= k; egg++) {
        for ( int i = 1; i <= n; i++) {
            int min_turn = n;    
            for (int j = 1; j <= n && j <= i ; j++) {    
                int egg_break = dp[egg - 1][j - 1];
                int egg_not_break = dp[egg][i - j];
                int tmp = max(egg_break, egg_not_break) + 1;
                if (tmp < min_turn) min_turn = tmp;
            }
            dp[egg][i] = min_turn;
        }
    }
    
    return dp[k][n];

}



int dropegg2(int k, int n) {

    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    if (k == 1) return n;
    if (k == 0) return 0;
    if (n == 1) return 1;

    int result = n;



}

int main() {
    int k, n;
    
    cin >> k >>n;
    // k = 3;
    // n = 14;

    cout << dropegg(k, n);
    
    
    
    
    return 0;

}