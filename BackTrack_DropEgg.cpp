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
    //print coup k, n
    cout << k << " " << n << endl;

    if (k == 1) {
        return n;
    } 

    if (n == 0) {
        return 0;
    }
    
    if (n == 1) {
        return 1;
    }
    
    int min_egg = n;

    for(int i = 1; i <= n; i++) {
        int egg_break = dropegg(k - 1, i - 1);
        int egg_not_break = dropegg(k, n - i);
        int tmp = max(egg_break, egg_not_break) + 1;
        if (tmp < min_egg) {
            min_egg = tmp;
        }    
    }

    return min_egg;


}



int main() {
    int k, n;
    
    cin >> k >>n;

    cout << dropegg(k, n);
    
    
    
    
    return 0;

}