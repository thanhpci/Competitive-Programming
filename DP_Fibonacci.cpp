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





int main() {
    int n = 0;
    cin >> n;

    vector<int> fib(n + 1, 0);

    fib[0] = 0;
    fib[1] = 1;

    cout << fibonacci(n, fib);

    return 0;

}