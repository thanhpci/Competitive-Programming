
/**
BINCOEF (Hệ số nhị thức)
Hệ số nhị thức (n, k)* là hệ số của đơn thức xk
 khi khai triển và thu gọn đa thức (1 + x)n
.
 
Cách kí hiệu trên không phải là chính thức nên nếu muốn tìm hiểu thêm thì google nhé :)). 
INPUT: 
Gồm 1 dòng là 2 số k và n.. 
OUTPUT: 
In ra 1 số nguyên là đáp án sau khi chia lấy dư cho 1e9+7. 
GIỚI HẠN: 
0 <= k <= n <= 3000
 */




#include <bits/stdc++.h>


using namespace std;

const int MOD = 1e9+7;

int bincoef(int k, int n){
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k && j <= i; j++){
            dp[j][i] = (((j > 0) ? dp[j - 1][i - 1] :  0) + dp[j][i - 1]) % MOD;
        }
    }

    return dp[k][n];
    
}



int main() {
    int k, n;
    cin >> k;
    cin >> n;
    

     cout << bincoef(k, n) << endl;

    return 0;
}
