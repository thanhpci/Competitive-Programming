// 1. FIBONACCI 
// Tìm số Fibonacci thứ n, hay f(n), biết f(0) = 0, f(1) = 1, và f(n) = f(n - 1) + f(n - 2) với n >= 2. 
// INPUT: 
// Dòng đầu nhập số n. 
// OUTPUT: 
// Một số nguyên duy nhất là đáp án sau khi chia lấy dư với 1e9+7. 
// GIỚI HẠN: 
// 2 <= n <= 1e6 



#include <bits/stdc++.h>


using namespace std;


const int MOD = 1e9 + 7;

int fibonacci(int n, vector<int> &fib) {
    if (n <= 1 || fib[n] != 0){
        return fib[n] ;
    } 
    else{
        fib[n] = (fibonacci(n - 1, fib) + fibonacci(n - 2, fib)) % MOD;
        return fib[n];
    }
}



// int fibonacci2(int n) {
//     if (n < 0) return 0;
//     if (n == 1) return 1;

//     vector<int> fib(n + 1, 0);
//     fib[0] = 0;
//     fib[1] = 1;


//     for (int i = 2; i <= n; i++) {
//         fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
//     }

//     return fib[n];
// }


// int fibonacci3(int n) {
//     if (n < 1) return 0;
//     if (n == 1) return 1;

//     int prev1 = 1;
//     int prev2 = 0;
//     int cur = 0;

//     for (int i = 2; i <= n; i++) {
//         cur = (prev1 + prev2)%MOD;
//         prev2 = prev1;
//         prev1 = cur;
       
//     }


//     return cur;

// }




int main() {
    int n = 0;
    cin >> n;

    vector<int> fib(n + 1, 0);

    fib[0] = 0;
    fib[1] = 1;

    cout << fibonacci(n, fib) << endl;
    // cout << fibonacci2(n) << endl;
    // cout << fibonacci3(n) << endl;

    return 0;

}