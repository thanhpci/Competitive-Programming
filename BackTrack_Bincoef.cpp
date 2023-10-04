
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

int bincoef(int k, int n){
    if (k == 0 || k == n) return 1;

    return bincoef(k - 1, n -1) + bincoef(k, n - 1);
}


int main() {
    while(true) {
        int n, k;
        cin >> k >> n;


        cout << bincoef(k, n) << endl;
   
    }
  


    return 0;
}